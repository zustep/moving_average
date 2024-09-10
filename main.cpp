#include <iostream>

#include "data_generator.hpp"
#include "moving_average.hpp"

int main()
{
    auto data = generate_data<float>(0.f, 1.f, 100);
    auto res = moving_average<float>(data, 4);

    return 0;
}