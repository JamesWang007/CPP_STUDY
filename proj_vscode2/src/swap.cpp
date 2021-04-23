#include "swap.h"

template <typename T>
void Swap::do_swap(T &&x, T &&y)
{
    T tmp = x;
    x = y;
    y = tmp;
}