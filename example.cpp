#include "Hexdump.hpp"

#include <iostream>

int main()
{
    unsigned char data[150];
    unsigned char c = 0;
    for (int i=0;i<sizeof(data);i++)
    {
        data[i] = c++;
    }

    std::cout << Hexdump(data, sizeof(data)) << std::endl;
    std::cout << CustomHexdump<8, true>(data, sizeof(data)) << std::endl;
    std::cout << CustomHexdump<32, false>(data, sizeof(data)) << std::endl;

}
