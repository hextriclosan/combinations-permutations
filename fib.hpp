

// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, ...
// 1, 2, 3, 4, 5, 6, 7,  8,  9, 10, 11, 12,  13,  14,  15,  16,  17,   18,   19,   20,   21,    22,    23, ...

size_t fib_iter(size_t nth)
{
    size_t first = 0;
    size_t second = 1;
    size_t res = first;
    for (size_t i = 0; i < nth; i++)
    {
        res = first + second;
        first = second;
        second = res;
    }

    return first;
}

size_t fib_rec(size_t nth)
{
    if (nth < 2)
    {
        return nth;
    }
    else
    {
        return fib_rec(nth - 2) + fib_rec(nth - 1);
    }
}

size_t fib_dyn(size_t nth)
{
    std::vector<size_t> res(nth+1);
    res[0] = 0;
    res[1] = 1;

    for (size_t i = 2; i <= nth; i++)
    {
        res[i] = res[i-2] + res[i-1];
    }

    return res[nth];
}
