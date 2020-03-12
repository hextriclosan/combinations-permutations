
#pragma once

#include <iostream>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    for (const auto& value : vec)
    {
        os << ' ' << value;
    }
    os << '\n';

    return os;
}
