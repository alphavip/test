#include <string>
#include <iostream>
#include <memory.h>

int main()
{
    char* pStr = new char[8];
    bzero(pStr, 8);
    pStr = "hello";

    std::string a = std::string(pStr, strlen(pStr));
    std::string b;
    b.assign(pStr, strlen(pStr));
    std::string c(pStr, strlen(pStr));

    std::cout << a.c_str() << std::endl;
    return 0;
}