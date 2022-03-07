#include <iostream>

class Convert
{
    const std::string str;
public:
    Convert( const char *str ) : str(str) { }
    template <typename T>
    operator T()
    {
        if constexpr( std::is_same_v<T, float> )
            return std::stof( str );
        else if( std::is_same_v<T, int> )
            return std::stoi( str );
    }
};

int main()
{
    int ival = Convert("12");
    float fval = Convert("123.111");

    std::cout << ival << "\n";
    std::cout << fval << "\n";
}
