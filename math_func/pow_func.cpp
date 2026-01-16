#include <cstddef>

long long pow_func(long long base_num, size_t exp)
{
    long long result = 1;

    for (size_t idx = 0; idx < exp; ++idx)
        result *= base_num;

    return result;
}
