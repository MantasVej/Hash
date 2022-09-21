#include <iostream>
#include <string>
#include "Hash.h";

int main()
{
   
    //input text
    std::string str = "Lietuva";

    Hash h;
    h = str;
    std::cout << h.hashing() << std::endl;

    return 0;
}