#pragma once
#include <map>
#include <vector>
#include <string>
#include <cassert>
#include <functional>
#include <type_traits>
#include "ecsGrowList.h"
#include "ecsEntityManager.h"

/// <summary>
/// Base interface for all systems.
/// </summary>
class IEcsSystem
{
public:
	//IEcsSystem() = default;
	virtual ~IEcsSystem() {}; // ���������� ����������
};

/// <summary>
/// Interface for PreInit systems. PreInit() will be called before Init().
/// </summary>
class IEcsPreInitSystem : public IEcsSystem
{
protected:
	virtual ~IEcsPreInitSystem() = default; // ���������� ����������
public:
	virtual void PreInit() = 0;
};

/// <summary>
/// Interface for Init systems. Init() will be called before Run().
/// </summary>
class IEcsInitSystem
{
protected:
	virtual ~IEcsInitSystem() = default; // ���������� ����������
public:
	virtual void Init() = 0;
};

/// <summary>
/// Interface for PostDestroy systems. PostDestroy() will be called after Destroy().
/// </summary>
class IEcsPostDestroySystem : public IEcsSystem
{
protected:
	virtual ~IEcsPostDestroySystem() = default; // ���������� ����������
public:
	virtual void PostDestroy() = 0;
};

/// <summary>
/// Interface for Destroy systems. Destroy() will be called last in system lifetime cycle.
/// </summary>
class IEcsDestroySystem : public IEcsSystem
{
protected:
	virtual ~IEcsDestroySystem() {};
public:
	virtual void Destroy() = 0;
};

/// <summary>
/// Interface for Run systems.
/// </summary>
class IEcsRunSystem : public IEcsSystem
{
protected:
	virtual ~IEcsRunSystem() = default; // ���������� ����������
public:
	virtual void Run() = 0;
};

/// <summary>
/// IEcsRunSystem instance with active state.
/// </summary>
class EcsSystemsRunItem
{
public:
	EcsSystemsRunItem() {};
	EcsSystemsRunItem(bool Active, IEcsRunSystem* System) { this->Active = Active, this->System = System; };
	bool Active;
	IEcsRunSystem* System;
};

/// <summary>
/// Logical group of systems.
/// </summary>
class ecsSystems : public IEcsRunSystem, IEcsInitSystem
{
public:
	std::string Name;
	ecsEntityManager* _manager;
	ecsGrowList<IEcsSystem*> _allSystems = ecsGrowList<IEcsSystem*>(64);
	ecsGrowList<EcsSystemsRunItem> _runSystems = ecsGrowList<EcsSystemsRunItem>(64);
	std::map<int, int> _namedRunSystems;
//	//template <typename T, typename B>
//	//std::map<T, B> _injections;
	bool _injected;
	bool _initialized;
	bool _destroyed;
//	//std::vector<IEcsSystemsDebugListener> _debugListeners;
// 
	ecsSystems() {}
///// <summary>
///// Creates new instance of EcsSystems group.
///// </summary>
///// <param name="world">EcsWorld instance.</param>
///// <param name="name">Custom name for this group.</param>
	ecsSystems(ecsEntityManager* manager, std::string name = "")
	{
		_manager = manager;
		Name = name;
	}

/// <summary>
/// Adds new system to processing.
/// </summary>
/// <param name="system">System instance.</param>
/// <param name="namedRunSystem">Optional name of system.<param>
	ecsSystems Add(IEcsSystem* system, std::string namedRunSystem = "")
	{
		assert(system != NULL, "System is null.");
		assert("Cant add system after initialization.", _initialized);
		assert("Cant touch after destroy.", _destroyed);
		assert("Cant name non-IEcsRunSystem.", !namedRunSystem.empty() && !std::is_convertible_v<IEcsRunSystem*, IEcsSystem*>);
		_allSystems.Add(system);
		if (dynamic_cast<IEcsRunSystem*> (system) != nullptr)
		{
			if (namedRunSystem.length() == NULL && std::is_convertible_v<ecsSystems, IEcsSystem*>)
			{
				auto sys = reinterpret_cast<ecsSystems*> (system);
 				namedRunSystem = sys->Name;
			}
			if (!namedRunSystem.empty())
			{

				if (_namedRunSystems.find(std::hash<std::string>()(namedRunSystem)) == _namedRunSystems.end())
				{
					assert(_namedRunSystems.find(std::hash<std::string>()(namedRunSystem)) == _namedRunSystems.end(), "Cant add named system - " + namedRunSystem + " name already exists.");
				}

				_namedRunSystems[std::hash<std::string>()(namedRunSystem)] = _runSystems.Count;
			}
			_runSystems.Add(EcsSystemsRunItem{true, dynamic_cast<IEcsRunSystem*> (system) });
		}
		return *this;
	}

	//template<typename T>
	//T GetComponentItem()
	//{
	//	for (size_t i = 0; i < _allSystems.Count; i++)
	//	{
	//		//if (T == )
	//		//{

	//		//}
	//		//if (T* item = dynamic_cast<T*>(_allSystems.Items[i]))
	//		//{
	//		//	if (item != nullptr)
	//		//	{
	//		//		items = item;
	//		//		return items;
	//		//	}
	//		//}
	//	}
	//}

/// <summary>
/// Sets IEcsRunSystem active state.
/// </summary>
/// <param name="idx">Index of system.</param>
/// <param name="state">New state of system.</param>
	void SetRunSystemState(int idx, bool state)
	{
		assert("Invalid index", idx < 0 || idx >= _runSystems.Count);
		_runSystems.Items[idx].Active = state;
	}

/// <summary>
/// Gets IEcsRunSystem active state.
/// </summary>
/// <param name="idx">Index of system.</param>
	bool GetRunSystemState(int idx)
	{
		assert("Invalid index", idx < 0 || idx >= _runSystems.Count);
		return _runSystems.Items[idx].Active;
	}

/// <summary>
/// Get all systems. Important: Don't change collection!
/// </summary>
	ecsGrowList<IEcsSystem*> GetAllSystems()
	{
		return _allSystems;
	}

/// <summary>
/// Gets all run systems. Important: Don't change collection!
/// </summary>
	ecsGrowList<EcsSystemsRunItem> GetRunSystems()
	{
		return _runSystems;
	}

/// <summary>
/// Closes registration for new systems, initialize all registered.
/// </summary>
	void Init()
	{
		assert("Already initialized.", _initialized);
		assert("Cant touch after destroy.", _destroyed);
//		ProcessInjects();
//		// IEcsPreInitSystem processing.
//		for (int i = 0, iMax = _allSystems.Count; i < iMax; i++)
//		{
//			var system = _allSystems.Items[i];
//			if (system is IEcsPreInitSystem preInitSystem)
//			{
//				preInitSystem.PreInit();
//				World.CheckForLeakedEntities($"{preInitSystem.GetType().Name}.PreInit()");
//			}
//		}
		// IEcsInitSystem processing.
		for (int i = 0, iMax = _allSystems.Count; i < iMax; i++)
		{
			auto system = _allSystems.Items[i];
			auto initSystem = dynamic_cast<IEcsInitSystem*> (system);
			if (dynamic_cast<IEcsInitSystem*> (system))
		{
				initSystem->Init();
//				World.CheckForLeakedEntities($"{initSystem.GetType().Name}.Init()");
			}
		}
		_initialized = true;
	}

/// <summary>
/// Processes all IEcsRunSystem systems.
/// </summary>
	void Run() 
	{
		assert("[{Name ?? NONAME}] EcsSystems should be initialized before.", !_initialized);
		assert("Cant touch after destroy.", _destroyed);
		for (int i = 0, iMax = _runSystems.Count; i < iMax; i++)
		{
			auto runItem = _runSystems.Items[i];
			if (runItem.Active)
			{
				runItem.System->Run();				
			}
		//	if (World.CheckForLeakedEntities(null))
		//	{
		////		throw new Exception($"Empty entity detected, possible memory leak in {_runSystems.Items[i].GetType().Name}.Run ()");
		//	}
		}
	}
private:
};