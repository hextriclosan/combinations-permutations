

#include "unique_combinations.hpp"
#include "count_sums.hpp"
#include "calculate_sums.hpp"
#include "calculate_permutations.hpp"
#include "subarrays.hpp"

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
        std::vector<int> input{1, 2, 3};
        std::cout << "All subarray of " << input << ":\n";
        std::cout << subarrays(input);
        std::cout << '\n';
    }
}
