

#include "unique_combinations.hpp"
#include "count_sums.hpp"
#include "calculate_sums.hpp"
#include "calculate_permutations.hpp"
#include "print_subarrays.hpp"

#include <iostream>

int main()
{
    auto unique_comb = unique_combinations({1, 2, 3, 4}, 3);
    std::cout << unique_comb;
    std::cout << '\n';

    std::cout << sums_count({1, 2}, 5) << '\n';
    std::cout << '\n';

    std::cout << calculate_sums({1, 2}, 5) << '\n';
    std::cout << '\n';

    std::cout << calculate_permutations({1, 2, 3});
    std::cout << '\n';


    std::cout << subarrays({ 1, 2, 3 });
    std::cout << '\n';

}
