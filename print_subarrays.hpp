#pragma once

#include "utils.hpp"
#include <vector>
#include <iostream>

void print_subarrays(const std::vector<int>& arr, int start, int end)
{

    if (end == arr.size()) // Stop if we have reached the end of the array
    {
        return;
    }
    else if (start > end) // Increment the end point and start from 0
    {
        print_subarrays(arr, 0, end + 1);
    }
    else // Print the subarray and increment the starting point
    {
        std::cout << "[";
        for (int i = start; i < end; i++)
        {
            std::cout << arr[i] << ", ";
        }

        std::cout << arr[end] << "]\n";
        print_subarrays(arr, start + 1, end);
    }

    return;
}

void print_subarrays(const std::vector<int>& input)
{
    print_subarrays(input, 0, 0);
}