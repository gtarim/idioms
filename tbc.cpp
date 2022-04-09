#include <iostream>
#include <tuple>

class Base
{
    int ival;
    std::string str;
public:
    explicit Base(int ival, std::string str) : ival{ival}, str{str} {}

    friend bool operator<(const Base& l, const Base& r)
    {
		return std::tuple{ l.ival, l.str } < std::tuple{ r.ival, r.str };
    }
};

int main()
{
    Base b1{ 10, "gokhan" };
    Base b2{ 20, "tarim" };

    std::cout << std::boolalpha << (b1 < b2);
}