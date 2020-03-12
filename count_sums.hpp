
#pragma once

/// Calculates number of all combination with given sum
/// Input values treated as unique
///
/// \param c values
/// \param n sum
/// \return sum combinations
long sums_count(const std::vector<long>& c, int n)
{
    std::vector<long> numways(n + 1); // numways[x] means # ways to get sum x
    numways[0] = 1; // init base case n=0

    // go thru coins 1-by-1 to build up numways[] dynamically
    // just need to consider cases where sum j>=c[i]
    for (int i = 0; i < c.size(); i++)
    {
        for (int j = c[i]; j <= n; j++)
        {
            // find numways to get sum j given value c[i]
            // it consists of those found earlier plus
            // new ones.
            // E.g. if c[]=1,2,3... and c[i]=3,j=5,
            //      new ones will now include '3' with
            //      numways[2] = 2, that is:
            //      '3' with '2', '3' with '1'+'1'
            numways[j] += numways[j - c[i]];
        }
    }

    return numways[n];
}

