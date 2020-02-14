

#include "print_unique.hpp"

#include "count_sums.hpp"

#include "print_sums.hpp"

#include "print_perm.hpp"

#include <iostream>

int main()
{
    print_unique({1, 2, 3, 4}, 3);
    std::cout << '\n';

    std::cout << get_sums_count({1, 2}, 5) << '\n';
    std::cout << '\n';

    std::cout << print_sums({1, 2}, 5) << '\n';
    std::cout << '\n';

    print_perm({1, 2, 3}, 0);
    std::cout << '\n';

}
