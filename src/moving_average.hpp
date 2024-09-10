#pragma once
#include <vector>
#include <type_traits>
#include <cassert>

/*
    Функция для вычисления скользящего среднего на последовательности 
    чисел с плавающей точкой data в окне длины window_sz.
*/
template<typename T>
std::vector<T> moving_average(const std::vector<T>& data, size_t window_sz)
{
    static_assert(std::is_floating_point<T>::value, "[ERROR] Expected floating point type.");
    assert(data.size() >= window_sz);

    std::vector<T> result{};

    return result;
}