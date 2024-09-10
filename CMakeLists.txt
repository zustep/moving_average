cmake_minimum_required(VERSION 3.0)

project(moving_average)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Release)

include_directories(${CMAKE_CURRENT_LIST_DIR}/src)

add_executable(${PROJECT_NAME} main.cpp)