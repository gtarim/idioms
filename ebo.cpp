#include <iostream>

struct Base  
{
    void func();
    static int someUtilityFun2();
};

struct Der : Base
{
};

struct Myclass
{
    Base e;
    int x;
};

int main()
{
    std::cout << sizeof( Base ) << "\n";
    std::cout << sizeof( Der ) << "\n";
    std::cout << sizeof( Myclass ) << "\n";
}