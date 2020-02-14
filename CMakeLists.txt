
cmake_minimum_required(VERSION 3.8)

project(combinations-permutations)

add_executable(main
    main.cpp
    count_sums.hpp
    print_perm.hpp
    print_sums.hpp
    print_unique.hpp
    utils.hpp)

target_compile_features(main PRIVATE cxx_std_17)
