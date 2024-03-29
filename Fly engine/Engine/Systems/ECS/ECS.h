#pragma once
#include <array>
#include <bitset>
#include <iostream>

class Entity;
class ecsComponent;

using Group = std::size_t;
using ComponentTypeID = std::size_t;

inline ComponentTypeID getUniqueComponentID()
{
	static ComponentTypeID lastID = 0u;
	return lastID++;
}

template<typename T>
inline ComponentTypeID getComponentTypeID() noexcept
{
	static_assert(std::is_base_of<ecsComponent, T>::value, "Type not base on component!");
	static const ComponentTypeID typeID = getUniqueComponentID();
	return typeID;
}

constexpr std::size_t MAX_ENTITIES = 5000;
constexpr std::size_t MAX_COMPONENTS = 5000;

using ComponentBitset = std::bitset<MAX_COMPONENTS>;
using ComponentList = std::array<ecsComponent*, MAX_COMPONENTS>;

constexpr std::size_t maxGroups{ 32 };
using GroupBitset = std::bitset<maxGroups>;