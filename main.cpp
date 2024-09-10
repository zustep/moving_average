#include "data_generator.hpp"
#include "moving_average.hpp"

#include <chrono>
#include <iostream>

#define NOT_OPTIMIZE(x) asm("" ::"r,i"(x))

int main()
{
    constexpr size_t sequence_sz = 1'500'000;
    constexpr size_t window_sz = 8;
    
    constexpr double seq_start_val = 0.0;
    constexpr double seq_end_val = 32768.0;

    auto data = generate_data<double>(seq_start_val, seq_end_val, sequence_sz);

    auto start_timestamp = std::chrono::high_resolution_clock::now();
    auto average_values = moving_average(data, window_sz);
    // Отключение оптимизаций компилятора
    NOT_OPTIMIZE(average_values[0]);
    auto end_timestamp = std::chrono::high_resolution_clock::now();

    auto elapsed_time = std::chrono::duration_cast<
        std::chrono::microseconds>(end_timestamp - start_timestamp).count();

    std::cout << "Elapsed time: " << 1e-6*elapsed_time << " seconds"
            << ", data size = " << sequence_sz << ", window size = "
            << window_sz << std::endl;

    return 0;
}