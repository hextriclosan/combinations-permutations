
#pragma once

#include "utils.hpp"

#include <algorithm>
#include <iterator>
#include <iostream>

namespace {
    void recursive1(std::vector<int> &input, const size_t start, std::vector<std::vector<int>> &acc) {
        if (start == input.size()) {
            acc.push_back(input);
            return;
        }

        for (int j = start; j < input.size(); j++) {
            std::iter_swap(input.begin() + start, input.begin() + j);

            recursive1(input, start + 1, acc);

            std::iter_swap(input.begin() + start, input.begin() + j);
        }
    }
}
/// Calculates all permutations for the given input recursive approach, number of permutation is N!
///
/// \param input
/// \return all possible permutation
std::vector<std::vector<int>> calculate_permutations_recursive1(const std::vector<int> &input) {
    std::vector<std::vector<int>> acc;
    auto in = input;
    recursive1(in, 0, acc);

    return acc;
}


namespace {
    std::vector<std::vector<int>> recursive2(const std::vector<int> &input) {
        std::vector<std::vector<int>> result;

        if (input.size() == 1) {
            return {input};
        }

        for (int i = 0; i < input.size(); i++) {
            int current_element = input[i];

            auto remaining_elements = input;
            remaining_elements.erase(remaining_elements.begin() + i);

            auto remaining_elements_permuted = recursive2(remaining_elements);

            for (int j = 0; j < remaining_elements_permuted.size(); j++) {
                auto permutation = remaining_elements_permuted[j];
                permutation.insert(permutation.begin(), current_element);
                result.push_back(permutation);
            }
        }

        return result;
    }
}
/// Calculates all permutations for the given input recursive approach, number of permutation is N!
///
/// \param input
/// \return all possible permutation
std::vector<std::vector<int>> calculate_permutations_recursive2(const std::vector<int> &input) {
    return recursive2(input);
}


namespace {
    void heaps_recursive(std::vector<int> &input, int len, std::vector<std::vector<int>> &acc) {
        if (len == 1) {
            acc.push_back(input);
        } else {
            heaps_recursive(input, len - 1, acc);
            for (int i = 0; i < len - 1; i++) {
                if (len % 2 == 0) {
                    std::iter_swap(input.begin() + i, input.begin() + len - 1);
                } else {
                    std::iter_swap(input.begin() + 0, input.begin() + len - 1);
                }
                heaps_recursive(input, len - 1, acc);
            }
        }
    }
}
/// Calculates all permutations for the given input with recursive Heap's algorithm, number of permutation is N!
///
/// \param input
/// \return all possible permutation
std::vector<std::vector<int>> calculate_permutations_heaps_recursive(const std::vector<int> &input) {
    std::vector<std::vector<int>> acc;
    auto modifiable = input;
    heaps_recursive(modifiable, input.size(), acc);

    return acc;
}


/// Calculates all permutations for the given input with iterative Heap's algorithm, number of permutation is N!
///
/// \param input
/// \return all possible permutation
std::vector<std::vector<int>> calculate_permutations_heaps_iterative(const std::vector<int> &input) {
    std::vector<std::vector<int>> acc;
    auto modifiable = input;

    std::vector<int> c(input.size(), 0);

    acc.push_back(modifiable);

    int i = 1;
    while (i < modifiable.size()) {
        if (c[i] < i) {
            if (i % 2 == 0) {
                std::iter_swap(modifiable.begin() + 0, modifiable.begin() + i);
            } else {
                std::iter_swap(modifiable.begin() + c[i], modifiable.begin() + i);
            }
            acc.push_back(modifiable);

            c[i]++;
            i = 1;
        } else {
            c[i] = 0;
            i++;
        }
    }

    return acc;
}


namespace {
    bool next_permutation(std::vector<int> &input) {
        const int sz = input.size();
        int i = sz - 2;
        while (i >= 0 && input[i] >= input[i + 1]) --i;
        if (i >= 0) {
            int j = sz - 1;
            while (j >= i && input[j] <= input[i]) --j;
            std::swap(input[i], input[j]);
            std::reverse(std::begin(input) + i + 1, std::end(input));
            return true;
        }

        std::reverse(std::begin(input), std::end(input));
        return false;
    }
}
/// Calculates all permutations for the given input lexicographically, number of permutation is N!
///
/// \param input
/// \return all possible permutation
std::vector<std::vector<int>> calculate_permutations_lexicographic(const std::vector<int> &input) {
    std::vector<std::vector<int>> acc;
    auto modifiable = input;

    do {
        acc.push_back(modifiable);
    } while (next_permutation(modifiable));

    return acc;
}
