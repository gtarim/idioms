#include <iostream>

class Base
{
public:
    void print() 
    {
        print_impl(); 
    }
    virtual ~Base() = default;

private:
    virtual void print_impl() = 0; 
};

class Der : public Base
{
private:
    virtual void print_impl()
    {
        std::cout << "Der implementation\n";
    }
};

int main()
{
    std::unique_ptr<Base> ptr { new Der{} };
    ptr->print();
}