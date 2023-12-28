#pragma once
#include <vector>
#include <stdexcept>


template <typename T>
class Array3d
{
public:
	Array3d()
		: m_arr(0), m_arrSize(0), m_dim0(0), m_dim1(0), m_dim2(0)
	{
	}
	Array3d(int dim0, int dim1, int dim2)
		:m_arr(nullptr), m_dim0(dim0), m_dim1(dim1), m_dim2(dim2)
	{
		m_arr = new T[m_dim0 * m_dim1 * m_dim2];
		m_arrSize = m_dim0 * m_dim1 * m_dim2;
	}
	~Array3d()
	{
		delete m_arr;
	}
	T& operator ()(int i, int j, int k)
	{
		if (i < m_dim0 && j < m_dim1 && k < m_dim2)
			return m_arr[i * m_dim0 + j * m_dim1 + k * m_dim2];
		else
			throw std::runtime_error("Error: Invalid indexes entered!");
	}
	std::vector<std::vector<T>> getValues0(int i);
	std::vector<std::vector<T>> getValues1(int j);
	std::vector<std::vector<T>> getValues2(int k);
	std::vector<T> getValues01(int i, int j);
	std::vector<T> getValues02(int i, int k);
	std::vector<T> getValues12(int j, int k);

	void setValues0(int i, std::vector<std::vector<T>> subArray);
	void setValues1(int j, std::vector<std::vector<T>> subArray);
	void setValues2(int k, std::vector<std::vector<T>> subArray);
	void setValues01(int i, int j, std::vector<T> subArray);
	void setValues02(int i, int k, std::vector<T> subArray);
	void setValues12(int j, int k, std::vector<T> subArray);
	
	void ones();
	void zeros();
	void fill(T sample);
private:
	T* m_arr;
	int m_arrSize;
	int m_dim0;
	int m_dim1;
	int m_dim2;
};

#include "Array3d_impl.h"