
#pragma once

#include <stack>

struct DataFrame
{
    int sum;
    std::vector<int> coins;
    std::vector<int> avail_coins;
};

void print(DataFrame df)
{
    for (auto v : df.coins)
    {
        std::cout << v << ' ';
    }
    std::cout << '\n';
}

int print_sums(std::vector<int> nums, int n)
{
    std::stack<DataFrame> s;
    s.push({n, {}, nums});
    int ways = 0;
    while (!s.empty())
    {
        DataFrame top = s.top();
        s.pop();
        if (top.sum < 0)
        {
            // broken simple throw it out
            continue;
        }

        if (top.sum == 0)
        {
            // we are done here
            ++ways;
            print(top);
            continue;
        }

        if (top.avail_coins.empty())
        {
            // no coins, sorry
            continue;
        }


        DataFrame d = top;

        // try a first coin
        d.sum -= top.avail_coins[0];
        d.coins.push_back(top.avail_coins[0]);
        s.push(d);

        // remove first coin
        d = top;
        d.avail_coins.erase(std::begin(d.avail_coins));
        s.push(d);
    }

    return ways;
}

