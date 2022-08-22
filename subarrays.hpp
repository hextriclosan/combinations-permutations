
#pragma once

#include "utils.hpp"
#include <vector>
#include <iostream>

namespace
{

void collect_subarrays(const std::vector<int>& arr, int start, int end, std::vector<std::vector<int>>& acc)
{

    if (end == arr.size()) // Stop if we have reached the end of the array
    {
        return;
    }

    if (start > end) // Increment the end point and start from 0
    {
        collect_subarrays(arr, 0, end + 1, acc);
    }
    else // Print the subarray and increment the starting point
    {
        auto b = arr.begin();
        acc.push_back({b + start, b + end + 1});
        collect_subarrays(arr, start + 1, end, acc);
    }

}

}

/// Get all subarray of the given array
/// \param input array
/// \return subarrays
std::vector<std::vector<int>> subarrays(const std::vector<int>& input)
{
    std::vector<std::vector<int>> acc;
    collect_subarrays(input, 0, 0, acc);

    return acc;
}
