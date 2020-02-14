
#pragma once

#include <vector>
#include <iostream>

void unique_combination(const std::vector<int>& input, std::vector<int>& data, int k, int start, int data_index)
{
    if (k == data_index)
    {
        for (auto a : data)
        {
            std::cout << a << ' ';
        }
        std::cout << '\n';
        return;
    }

    for (int i = start; i < input.size() && input.size() - i >= k - data_index; i++)
    {
        data[data_index] = input[i];
        unique_combination(input, data, k, i + 1, data_index + 1);
    }
}

void print_unique(const std::vector<int> input, int k)
{
    std::vector<int> data(k);
    unique_combination(input, data, k, 0, 0);
}
