#include <iostream>
#include <cstring>
#include <memory>

class small_object
{
    static constexpr std::size_t smallObjectSize = 16;

    union Data
    {
        char buffer[smallObjectSize];
        char* bufferPtr;
    } data;
    std::size_t _size;

public:
    explicit small_object (const char* str) : _size {std::strlen(str)} 
    {
        if (_size > smallObjectSize)
        {
            data.bufferPtr = new char[_size];
            std::strcpy( data.bufferPtr, str );
        }
        else
        {
            std::strcpy( data.buffer, str );
        }
    }
    
    ~small_object() 
    {
        if( _size > smallObjectSize)
        {
            delete[] data.bufferPtr;
        }
    }

    small_object (small_object&& oth)
    {
        if (oth._size > smallObjectSize)
        {
            data.bufferPtr = oth.data.bufferPtr;
            oth.data.bufferPtr = nullptr;
        }
        else
        {
            std::strcpy(data.buffer, oth.data.buffer);
        }
        _size = oth._size;
        oth._size = 0;
    }

    std::size_t size() const
    {
        return _size;
    }

private:
    friend std::ostream& operator<<( std::ostream& os, const small_object& so)
    {
        return os << (( so._size > so.smallObjectSize ) ? so.data.bufferPtr : so.data.buffer);
    }
};

int main()
{
    small_object str{"gokhan tarim"};
    std::cout << str;
}