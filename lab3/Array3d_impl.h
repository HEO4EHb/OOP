#pragma once
#include "Array3d.h"

template <typename T>
std::vector<std::vector<T>> Array3d<T>::getValues0(int i)
{
	std::vector<std::vector<T>> subArray(m_dim1, std::vector<T>(m_dim2, T(0)));
	if (i < m_dim0)
		for (int j = 0; j < m_dim1; j++)
			for (int k = 0; k < m_dim2; k++)
				subArray[j][k] = m_arr[i*m_dim0*m_dim0 + j * m_dim1 + k];
	return subArray;
}
template <typename T>
std::vector<std::vector<T>> Array3d<T>::getValues1(int j)
{
	std::vector<std::vector<T>> subArray(m_dim0, std::vector<T>(m_dim2, T(0)));
	if (j < m_dim1)
		for (int i = 0; i < m_dim1; i++)
			for (int k = 0; k < m_dim2; k++)
				subArray[i][k] = m_arr[i * m_dim0 * m_dim0 + j * m_dim1 + k];
	return subArray;
}
template <typename T>
std::vector<std::vector<T>> Array3d<T>::getValues2(int k)
{
	std::vector<std::vector<T>> subArray(m_dim0, std::vector<T>(m_dim1, T(0)));
	if (k < m_dim2)
		for (int i = 0; i < m_dim1; i++)
			for (int j = 0; j < m_dim2; j++)
				subArray[i][j] = m_arr[i * m_dim0 * m_dim0 + j * m_dim1 + k];
	return subArray;
}
template <typename T> 
std::vector<T>  Array3d<T>::getValues01(int i, int j)
{
	std::vector<T> subArray = std::vector<T>(m_dim2, T(0));
	if (i < m_dim0 && j < m_dim1)
		for(int k =0; k < m_dim2; k++)
			subArray[k] = m_arr[i * m_dim0 * m_dim0 + j * m_dim1 + k];
	return subArray;
}
template <typename T>
std::vector<T>  Array3d<T>::getValues02(int i, int k)
{
	std::vector<T> subArray = std::vector<T>(m_dim1, T(0));
	if (i < m_dim0 && k < m_dim2)
		for (int j = 0; j < m_dim1; j++)
			subArray[j] = m_arr[i * m_dim0 * m_dim0 + j * m_dim1 + k];
	return subArray;
}
template <typename T>
std::vector<T>  Array3d<T>::getValues12(int j, int k)
{
	std::vector<T> subArray = std::vector<T>(m_dim0, T(0));
	if (j < m_dim1 && k < m_dim2)
		for (int i = 0; i < m_dim0; i++)
			subArray[i] = m_arr[i * m_dim0 * m_dim0 + j * m_dim1 + k];
	return subArray;
}
template<typename T>
void Array3d<T>::setValues0(int i, std::vector<std::vector<T>> subArray)
{
	if (subArray.size() == m_dim1 && subArray[0].size() == m_dim2)
	{
		for (int j = 0; j < m_dim1; j++)
			for (int k = 0; k < m_dim2; k++)
				m_arr[i * m_dim0 * m_dim0 + j * m_dim1 + k] = subArray[j][k];
	}
}
template<typename T>
void Array3d<T>::setValues1(int j, std::vector<std::vector<T>> subArray)
{
	if (subArray.size() == m_dim0 && subArray[0].size() == m_dim2)
	{
		for (int i = 0; i < m_dim0; i++)
			for (int k = 0; k < m_dim2; k++)
				m_arr[i * m_dim0 * m_dim0 + j * m_dim1 + k] = subArray[i][k];
	}
}
template<typename T>
void Array3d<T>::setValues2(int k, std::vector<std::vector<T>> subArray)
{
	if (subArray.size() == m_dim0 && subArray[0].size() == m_dim1)
	{
		for (int i = 0; i < m_dim0; i++)
			for (int j = 0; j < m_dim1; j++)
				m_arr[i * m_dim0 * m_dim0 + j * m_dim1 + k] = subArray[i][j];
	}
}
template<typename T>
void Array3d<T>::setValues01(int i, int j, std::vector<T> subArray)
{
	if (subArray.size() == m_dim2)
	{
		for (int k = 0; k < m_dim2; k++)
			m_arr[i * m_dim0 * m_dim0 + j * m_dim1 + k] = subArray[k];
	}
}
template<typename T>
void Array3d<T>::setValues02(int i, int k, std::vector<T> subArray)
{
	if (subArray.size() == m_dim1)
	{
		for (int j = 0; j < m_dim1; j++)
			m_arr[i * m_dim0 * m_dim0 + j * m_dim1 + k] = subArray[j];
	}
}
template<typename T>
void Array3d<T>::setValues12(int j, int k, std::vector<T> subArray)
{
	if (subArray.size() == m_dim0)
	{
		for (int i = 0; i < m_dim0; i++)
			m_arr[i * m_dim0 * m_dim0 + j * m_dim1 + k] = subArray[i];
	}
}

template<typename T>
void Array3d<T>::ones()
{
	for (int i = 0; i < m_arrSize; i++)
		m_arr[i] = T(1);
}

template<typename T>
void Array3d<T>::zeros()
{
	for (int i = 0; i < m_arrSize; i++)
		m_arr[i] = T(0);
}

template<typename T>
void Array3d<T>::fill(T sample)
{
	for (int i = 0; i < m_arrSize; i++)
		m_arr[i] = sample;
}
