
cmake_minimum_required(VERSION 3.8)

project(combinations-permutations)

add_executable(${CMAKE_PROJECT_NAME}
    main.cpp
    count_sums.hpp
    calculate_permutations.hpp
    subarrays.hpp
    calculate_sums.hpp
    unique_combinations.hpp
    fib.hpp
    utils.hpp)

target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17)
