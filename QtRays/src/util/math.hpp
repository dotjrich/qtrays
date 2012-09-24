#ifndef MATH_HPP
#define MATH_HPP

#include <cstdlib>

inline void
set_rand_seed(int seed)
{
    srand(seed);
}

// -----------------------------------------------------------------------

inline int
rand_int()
{
    return rand();
}

// -----------------------------------------------------------------------

inline float
rand_float()
{
    return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}

#endif // MATH_HPP
