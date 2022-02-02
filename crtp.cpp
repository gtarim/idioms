#include <iostream>

class Der;
template <typename T = Der>
class Base
{
public:
    virtual void impl() {}
    virtual void pure_impl() = 0;

    void crtp_impl() { (static_cast<T*>(this))->crtp_impl(); }
    void crtp_pure_interface() { (static_cast<T*>(this))->crtp_pure_impl(); }
private:
    void crtp_pure_impl() = delete;
};

class Der : public Base<Der>
{
private: // works even in private
    friend struct Base<Der>;
    void impl() { std::cout << "der::impl\n"; }
    void pure_impl() { std::cout << "der::pure_impl\n"; }
    void crtp_impl() { std::cout << "der::crtp_impl\n"; }
    void crtp_pure_impl() { std::cout << "der::crtp_pure_impl\n"; }
};

int main()
{
    Base<>* ptr = new Der;
    ptr->impl();
    ptr->pure_impl();

    ptr->crtp_impl();
    ptr->crtp_pure_interface();
    // ptr->crtp_pure_impl(); syntax err!
}