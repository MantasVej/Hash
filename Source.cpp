#include <iostream>
#include <string>
#include <bitset>
#include <unordered_map>

int main()
{
    std::unordered_map<std::string, char> hex;
    hex["0000"] = '0';
    hex["0001"] = '1';
    hex["0010"] = '2';
    hex["0011"] = '3';
    hex["0100"] = '4';
    hex["0101"] = '5';
    hex["0110"] = '6';
    hex["0111"] = '7';
    hex["1000"] = '8';
    hex["1001"] = '9';
    hex["1010"] = 'a';
    hex["1011"] = 'b';
    hex["1100"] = 'c';
    hex["1101"] = 'd';
    hex["1110"] = 'e';
    hex["1111"] = 'f';

    std::string str = "blockchain";
    std::string bin = "";

    for (char const& c : str) {
        bin += std::bitset<8> (c).to_string();
    }
    bin.resize(248, '0');
    bin += std::bitset<8>(str.length()).to_string();
    for (int i = 0; i < 256; i += 4) {
        std::cout << hex[bin.substr(i, 4)];
    }
    return 0;
}