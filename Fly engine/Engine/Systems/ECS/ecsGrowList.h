#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <functional>

template<typename T>
class ecsGrowList
{
public:
	std::vector<T> Items;
	int Count;
	ecsGrowList(int capacity);
	void Add(T item);
	void EnsureCapacity(int count);
};

template<typename T>
inline ecsGrowList<T>::ecsGrowList(int capacity)
{
	Items.resize(capacity);
	Count = 0;
}

template<typename T>
inline void ecsGrowList<T>::Add(T item)
{
	if (Items.size() == Count)
	{
		Items.resize(Items.size() << 1);
	}
	Items[Count++] = item;
}

template<typename T>
inline void ecsGrowList<T>::EnsureCapacity(int count)
{
	if (Items.size() < count)
	{
		int len = Items.size() << 1;
		while (len <= count)
		{
			len <<= 1;
		}
		Items.resize(len);
	}
}
