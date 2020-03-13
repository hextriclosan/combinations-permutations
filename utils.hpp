
#pragma once

#include <iostream>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    os << '[';
    for (auto it = std::cbegin(vec); it != std::cend(vec); ++it)
    {
        os << *it;
        os << (it + 1 != std::cend(vec) ? ", " : "]");
    }
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>>& vec)
{
    for (const auto& value : vec)
    {
        os << value << '\n';
    }

    return os;
}
