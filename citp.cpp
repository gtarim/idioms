#include <iostream>

// both side is same operation.

// template <std::size_t size>
// std::size_t fib() { return fib<size-1>() + fib<size-2>(); }
// template <>
// std::size_t fib<1>() { return 1; }
// template <>
// std::size_t fib<0>() { return 1; }

template <std::size_t size>
std::size_t fib() 
{
    if constexpr ( size > 1 )
    {
        return fib<size-1>() + fib<size-2>();
    }
    else
    {
        return 1;
    }
}

int main()
{
    std::cout << fib<7>();
}