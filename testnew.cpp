#include <iostream>
#include <stdio.h>

class ObjectA
{
public:
    ObjectA()
    {
        std::cout << "constructor" << std::endl;
    }
    virtual ~ObjectA()
    {
        std::cout << "deconstructor" << std::endl;
    }

private:
    int a;
};

int main()
{
    ObjectA* pa = new ObjectA();
    pa->~ObjectA();


    ObjectA* pb = new(pa) ObjectA();

    return 0;
}