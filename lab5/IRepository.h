#pragma once
#include <vector>

template<typename T>
class IRepository
{
	virtual std::vector<T> GetAll() = 0;
	virtual void Add(T User) = 0;
	virtual void Remove(T user) = 0;
	virtual void Update(T user) = 0;
};