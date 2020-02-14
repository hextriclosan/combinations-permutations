
#pragma once

#include "utils.hpp"

#include <algorithm>
#include <iterator>
#include <iostream>

void perm(std::vector<int>& input, int i)
{
    if (i == input.size())
    {
        print(input);
        return;
    }

    for (int j = i; j < input.size(); j++)
    {
        std::iter_swap(input.begin() + i, input.begin() + j);

        perm(input, i + 1);

        std::iter_swap(input.begin() + i, input.begin() + j);
    }
}

void print_perm(const std::vector<int>& input)
{
    auto in = input;
    perm(in, 0);
}
