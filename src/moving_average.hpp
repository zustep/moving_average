#pragma once
#include <vector>
#include <numeric>
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

    // По условию задачи размер окна начинается от 4.
    assert(window_sz >= 4);

    assert(data.size() > window_sz);

    std::vector<T> result{};
    result.reserve(data.size());

    // Вычисление начального значения.
    T sum = std::accumulate(data.begin(), data.begin()+window_sz, T{});
    sum /= window_sz;
    result.push_back(sum);

    // В силу линейности среднего:
    for (int i = 1; i <= data.size()-window_sz; ++i) {
        T next_mean = result.back() + (data[i+window_sz-1] - data[i-1])/window_sz;
        result.push_back(next_mean);
    }

    return result;
}