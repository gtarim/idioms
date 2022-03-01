#include <iostream>

class Base
{
public:
    virtual ~Base() {}
    virtual Base* clone() const = 0;
};

class Der : public Base
{
public:
    ~Der() { }
    Base* clone() const override
    {
        return new Der(*this);
    }
};

int main()
{
    Base* base = new Der;

    Base* der = base->clone();
}