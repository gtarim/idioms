#include <iostream>

class Client
{
    friend class Attorney;
    int privacyFunc() { std::cout << "client privacy published\n"; return 5; }
};

class Attorney
{
    Client client;
    friend class ThirdPerson;
    int reachResult() { return client.privacyFunc(); }
};

struct ThirdPerson
{
    static int getResult()
    {
        Attorney attorney;
        return attorney.reachResult();
    }
};

int main()
{
    std::cout << ThirdPerson::getResult() << "\n";
}