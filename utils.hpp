
#pragma once

#include <iostream>

template<typename T>
void print(const T& cont)
{
    for (auto value : cont)
    {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}
