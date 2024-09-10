#pragma once

#include <vector>
#include <cassert>
#include "moving_average.hpp"

static void test_example_1()
{
    auto data = std::vector<float>{1.f, 2.f, 3.f, 4.f, 4.f, 3.f, 2.f, 1.f};
    auto average_values = moving_average(data, 4);

    assert(average_values[0] == 2.5f);
    assert(average_values[1] == 3.25f);
    assert(average_values[2] == 3.5f);
    assert(average_values[3] == 3.25f);
    assert(average_values[4] == 2.5f);
}

static void test_example_2()
{
    auto data = std::vector<float>{1.f, 2.f, 3.f, 4.f, 4.f, 3.f, 2.f, 1.f};
    auto average_values = moving_average(data, 8);

    assert(average_values[0] == 2.5f);
}