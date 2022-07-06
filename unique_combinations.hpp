
#pragma once

#include "utils.hpp"

#include <vector>
#include <iostream>

namespace
{

void unique_combination(const std::vector<int>& input, std::vector<int>& data, int k, int start, int data_index,
                        std::vector<std::vector<int>>& acc)
{
    if (k == data_index)
    {
        acc.push_back(data);
        return;
    }

    for (int i = start; i < input.size() && input.size() - i >= k - data_index; i++)
    {
        data[data_index] = input[i];
        unique_combination(input, data, k, i + 1, data_index + 1, acc);
    }
}

}

/// Calculates all combinations (order does not matter) of n taken k at a time
///
/// @note The number of all combinations is N!/((N-k)!*k!)
///
/// \param input
/// \param k
/// \return
std::vector<std::vector<int>> unique_combinations(const std::vector<int>& input, int k)
{
    std::vector<std::vector<int>> acc;
    std::vector<int> data(k);
    unique_combination(input, data, k, 0, 0, acc);

    return acc;
}
