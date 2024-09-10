#pragma once
#include <vector>
#include <type_traits>

/*
    Функция для генерации последовательности длины n_elements 
    равномерно распределённых чисел с плавающей точкой в отрезке от a до b.
*/
template<typename T>
std::vector<T> generate_data(T a, T b, size_t n_elements)
{
    static_assert(std::is_floating_point<T>::value, "[ERROR] Expected floating point type.");
    std::vector<T> ans{};
    return ans;
}