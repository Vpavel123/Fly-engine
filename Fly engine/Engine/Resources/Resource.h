#pragma once
#include <iostream>
#include <string>
#include <map>
#include "AssetPool.h"
#include "../Debugging/Logger.h"

template <class T>

class Resource
{
public:
	Logger* log = Logger::getInstance();
	std::string Root;
	std::string Directory;
	std::map<std::string, T> Resources;
	Resource();
	Resource(AssetPool assetpool);
	virtual ~Resource() {};
	T Find(std::string name);
	virtual void Load(std::string name) = 0;
};

template<class T>
inline Resource<T>::Resource()
{

}

template<class T>
inline Resource<T>::Resource(AssetPool assetpool)
{
	Root = assetpool.Root;
}

template<class T>
T Resource<T>::Find(std::string name)
{
	return Resources[name];
}

template<class T>
void Resource<T>::Load(std::string name)
{
	log->Information("Resource load: " + name);
}