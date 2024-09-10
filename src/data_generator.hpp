#pragma once

#include <vector>
#include <type_traits>
#include <random>

/*
    Функция для генерации последовательности длины n_elements 
    равномерно распределённых чисел с плавающей точкой в отрезке от a до b.
*/
template<typename T>
std::vector<T> generate_data(T a, T b, size_t n_elements)
{
    static_assert(std::is_floating_point<T>::value, "[ERROR] Expected floating point type.");

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<T> dis(a, b);

    std::vector<T> data{};
    data.reserve(n_elements);

    for (int i = 0; i < n_elements; ++i)
        data.push_back(dis(gen));

    return data;
}