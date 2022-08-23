

#include "unique_combinations.hpp"
#include "count_sums.hpp"
#include "calculate_sums.hpp"
#include "calculate_permutations.hpp"
#include "subarrays.hpp"
#include "fib.hpp"

#include <iostream>

int main()
{
    {
        std::vector<int> input{1, 2, 3, 4};
        constexpr int k = 3;
        std::cout << "Unique combinations of " << k << " from " << input << ":\n";
        auto unique_comb = unique_combinations(input, k);
        std::cout << unique_comb << '\n';
    }

    {
        std::vector<int> input{1, 2};
        constexpr int sum = 5;
        std::cout << "Number of all combination of " << input << " gives sum " << sum << ":\n";
        std::cout << sums_count(input, sum) << '\n';
        std::cout << '\n';
    }

    {
        std::vector<int> input{1, 2};
        constexpr int sum = 5;
        std::cout << "All combination of " << input << " gives sum " << sum << ":\n";
        std::cout << calculate_sums(input, sum) << '\n';
        std::cout << '\n';
    }

    {
        std::vector<int> input{1, 2, 3};
        std::cout << "All permutations for " << input << ":\n";
        std::cout << calculate_permutations(input);
        std::cout << '\n';
    }

    {
        std::vector<int> input{1, 2, 3, 4};

        std::cout << "All subarrays of " << input << " recursively:\n";
        std::cout << subarrays_recursively(input);
        std::cout << '\n';

        std::cout << "All subarrays of " << input << " iteratively:\n";
        std::cout << subarrays_iteratively(input);
        std::cout << '\n';
    }

    {
        size_t nth = 15;
        std::cout << nth <<  "th element of The Fibonacci Sequence:\n";
        std::cout << "iterations: " << fib_iter(nth) << '\n';
        std::cout << "recursion: " << fib_rec(nth) << '\n';
        std::cout << "dynamic: " << fib_dyn(nth) << '\n';
    }
}
