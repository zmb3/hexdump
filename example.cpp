#include "Hexdump.hpp"

#include <iostream>

template <typename T, T RowSize, T bufSize, bool showFlag>
void testCustomHexdumpBase()
{
    unsigned char data[bufSize];
    unsigned char c = 0;
    for (auto& val : data)
    {
        val = c++;
    }
    std::cout << CustomHexdumpBase<T, RowSize, showFlag>(data, bufSize) << std::endl;
}

int main()
{
    unsigned char data[150];
    unsigned char c = 0;
    for (auto& val : data)
    {
        val = c++;
    }

    std::cout << Hexdump(data, sizeof(data)) << std::endl;
    std::cout << CustomHexdump<8, true>(data, sizeof(data)) << std::endl;
    std::cout << CustomHexdump<32, false>(data, sizeof(data)) << std::endl;

    testCustomHexdumpBase<uint8_t, 8, 16, true>();
    testCustomHexdumpBase<int8_t, 8, 16, true>();
    testCustomHexdumpBase<uint16_t, 16, 32, true>();
    testCustomHexdumpBase<int16_t, 16, 32, true>();
}
