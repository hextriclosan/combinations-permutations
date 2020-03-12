
#pragma once

#include "utils.hpp"

#include <algorithm>
#include <iterator>
#include <iostream>

namespace
{

void perm(std::vector<int>& input, int i, std::vector<std::vector<int>>& acc)
{
    if (i == input.size())
    {
        acc.push_back(input);
        return;
    }

    for (int j = i; j < input.size(); j++)
    {
        std::iter_swap(input.begin() + i, input.begin() + j);

        perm(input, i + 1, acc);

        std::iter_swap(input.begin() + i, input.begin() + j);
    }
}

} // anonymous namespace

/// Calculates all permutations for the given input, number of permutation is N!
///
/// \param input
/// \return all possible permutation
std::vector<std::vector<int>> calculate_permutations(const std::vector<int>& input)
{
    std::vector<std::vector<int>> acc;
    auto in = input;
    perm(in, 0, acc);

    return acc;
}
