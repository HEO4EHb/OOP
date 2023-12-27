//
// Created by Yan on 11.10.2023.
//

#include "../include/Array3d.h"
#include <iostream>

using namespace Data;

// Конструктор класса Array3d с тремя параметрами (размерности массива)
template <typename T>
Array3d<T>::Array3d(int dim0, int dim1, int dim2)
        : mDim0{dim0}, mDim1{dim1}, mDim2{dim2} {
    // Инициализация вектора mData размером, равным произведению трех размерностей
    mData.resize(mDim0 * mDim1 * mDim2);
}


// Оператор для доступа к элементу массива по индексам i, j, k
template <typename T>
T& Array3d<T>::operator()(int i, int j, int k) {
    return mData[i + j * mDim0 + k * mDim0 * mDim1];
}

// Метод для получения среза массива по указанной оси (dim) и индексу (i)
template <typename T>
std::vector<T> Array3d<T>::GetValues2d(int dim, int i) const {
    // Проверка на корректность входных параметров
    if(dim < 0 || dim > 2 || i < 0) throw std::out_of_range("Index was out of range");

    // Вектор для хранения значений среза
    std::vector<T> result;

    // Используется оператор switch для выбора нужной оси
    switch (dim) {
        case 0:
            // Цикл по mDim1 и mDim2 для заполнения вектора значениями среза по оси dim=0
            for (int j = 0; j < mDim1; j++)
                for (int k = 0; k < mDim2; k++)
                    // Добавление элемента в вектор из массива mData
                    result.push_back(mData[i + j * mDim0 + k * mDim0 * mDim1]);
            break;
        case 1:
            // Цикл по mDim0 и mDim2 для заполнения вектора значениями среза по оси dim=1
            for (int j = 0; j < mDim0; j++)
                for (int k = 0; k < mDim2; k++)
                    // Добавление элемента в вектор из массива mData
                    result.push_back(mData[j + i * mDim0 + k * mDim0 * mDim1]);
            break;
        case 2:
            // Цикл по mDim0 и mDim1 для заполнения вектора значениями среза по оси dim=2
            for (int j = 0; j < mDim0; j++)
                for (int k = 0; k < mDim1; k++)
                    // Добавление элемента в вектор из массива mData
                    result.push_back(mData[j + k * mDim0 + i * mDim0 * mDim1]);
            break;
        default:
            break;
    }

    // Возвращение вектора среза
    return result;
}



// Метод для установки значений в массив по указанной оси (dim) и индексу (i)
template <typename T>
void Array3d<T>::SetValues2d(int dim, int i, std::vector<std::vector<T>>& data) {
    // Проверка на корректность входных параметров
    if(dim < 0 || dim > 2 || i < 0) throw std::out_of_range("Index was out of range");

    // Используется оператор switch для выбора нужной оси
    switch (dim) {
        case 0:
            // Цикл по mDim1 и mDim2 для установки значений в массив по оси dim=0
            for (int j = 0; j < mDim1; j++)
                for (int k = 0; k < mDim2; k++)
                    // Установка значения из вектора data в массив mData
                    mData[i + j * mDim0 + k * mDim0 * mDim1] = data[j][k];
            break;
        case 1:
            // Цикл по mDim0 и mDim2 для установки значений в массив по оси dim=1
            for (int j = 0; j < mDim0; j++)
                for (int k = 0; k < mDim2; k++)
                    // Установка значения из вектора data в массив mData
                    mData[j + i * mDim0 + k * mDim0 * mDim1] = data[j][k];
            break;
        case 2:
            // Цикл по mDim0 и mDim1 для установки значений в массив по оси dim=2
            for (int j = 0; j < mDim0; j++)
                for (int k = 0; k < mDim1; k++)
                    // Установка значения из вектора data в массив mData
                    mData[j + k * mDim0 + i * mDim0 * mDim1] = data[j][k];
            break;
        default:
            break;
    }
}

// Метод для получения среза массива по двум указанным осям (dim1, dim2) и индексам (i, j)
template<typename T>
std::vector<T> Array3d<T>::GetValues1d(int dim1, int dim2, int i, int j) const {
    // Проверка на корректность входных параметров
    if(dim1 < 0 || dim1 > 2 || i < 0 || dim2 < 0 || dim2 > 2 || j < 0)
        throw std::out_of_range("Index was out of range");

    // Вектор для хранения результатов
    std::vector<T> result;

    // Используется условие для выбора среза в зависимости от значений dim1 и dim2
    if((dim1 == 0 && dim2 == 1) || (dim1 == 1 && dim2 == 0)) {
        // Цикл по mDim2 для получения значений среза по оси dim1=0, dim2=1 или dim1=1, dim2=0
        for (int k = 0; k < mDim2;k++)
            result.push_back(mData[i + j * mDim0 + k * mDim0 * mDim1]);
    }
    else if((dim1 == 0 && dim2 == 2) || (dim1 == 2 && dim2 == 0)) {
        // Цикл по mDim1 для получения значений среза по оси dim1=0, dim2=2 или dim1=2, dim2=0
        for (int k = 0; k < mDim1; k++)
            result.push_back(mData[i + j * mDim0 + k * mDim0 * mDim1]);
    }
    else if((dim1 == 1 && dim2 == 2) || (dim1 == 2 && dim2 == 1)) {
        // Цикл по mDim0 для получения значений среза по оси dim1=1, dim2=2 или dim1=2, dim2=1
        for (int k = 0; k < mDim0; k++)
            result.push_back(mData[i + j * mDim0 + k * mDim0 * mDim1]);
    }

    return result;
}


// Метод для установки значений в массив по двум указанным осям (dim1, dim2) и индексам (i, j)
template<typename T>
void Array3d<T>::SetValues1d(int dim1, int dim2, int i, int j, std::vector<T>& data) {
    // Проверка на корректность входных параметров
    if(dim1 < 0 || dim1 > 2 || i < 0 || dim2 < 0 || dim2 > 2 || j < 0)
        throw std::out_of_range("Index was out of range");

    // Используется условие для выбора оси для установки значений
    if((dim1 == 0 && dim2 == 1) || (dim1 == 1 && dim2 == 0)) {
        // Цикл по mDim2 для установки значений по оси dim1=0, dim2=1 или dim1=1, dim2=0
        for (int k = 0; k < mDim2; k++)
            mData[i + j * mDim0 + k * mDim0 * mDim1] = data[k];
    }
    else if((dim1 == 0 && dim2 == 2) || (dim1 == 2 && dim2 == 0)) {
        // Цикл по mDim1 для установки значений по оси dim1=0, dim2=2 или dim1=2, dim2=0
        for (int k = 0; k < mDim1; k++)
            mData[i + j * mDim0 + k * mDim0 * mDim1] = data[k];
    }
    else if((dim1 == 1 && dim2 == 2) || (dim1 == 2 && dim2 == 1)) {
        // Цикл по mDim0 для установки значений по оси dim1=1, dim2=2 или dim1=2, dim2=1
        for (int k = 0; k < mDim0; k++)
            mData[i + j * mDim0 + k * mDim0 * mDim1] = data[k];
    }
}

// Метод для заполнения массива нулями
template<typename T>
[[maybe_unused]] void Array3d<T>::zerosFill() {
    for(int i = 0; i < mDim0 * mDim1 * mDim2; i++)
        mData[i] = 0;
}

// Метод для установки всех элементов массива в 1
template<typename T>
void Array3d<T>::ones() {
    for(int i = 0; i < mDim0 * mDim1 * mDim2; i++)
        mData[i] = 1;
}

// Метод для заполнения массива определенным значением
template<typename T>
void Array3d<T>::fill(T value) {
    for(int i = 0; i < mDim0 * mDim1 * mDim2; i++)
        mData[i] = value;
}

// Метод для вывода массива в консоль
template<typename T>
void Array3d<T>::arrayPrint() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++)
                std::cout << this->operator()(i, j, k) << " ";
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}
