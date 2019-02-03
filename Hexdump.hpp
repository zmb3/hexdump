#ifndef HEXDUMP_HPP
#define HEXDUMP_HPP

#include <iomanip>
#include <ostream>

template <typename T, T RowSize, bool ShowAscii>
class CustomHexdumpBase
{
public:
    CustomHexdumpBase(unsigned char* data, T length) :
        mData(static_cast<unsigned char*>(data)), mLength(length) { }

    T getLength() const { return mLength; }
    unsigned char getData(const T& i) const { return mData[i]; }

private:
    const unsigned char* mData;
    const T mLength;
};

template <std::size_t RowSize, bool ShowAscii>
class CustomHexdump : public CustomHexdumpBase<std::size_t, RowSize, ShowAscii>
{
public:
    CustomHexdump(unsigned char* data, std::size_t length) : CustomHexdumpBase<std::size_t, RowSize, ShowAscii>(data, length) {}
};

template <typename T, T RowSize, bool ShowAscii>
std::ostream& operator<<(std::ostream& out, const CustomHexdumpBase<T, RowSize, ShowAscii>& dump)
{
    out.fill('0');
    for (T i = 0; i < dump.getLength(); i += RowSize)
    {
        out << "0x" << std::setw(6) << std::hex << int(i) << ": ";
        for (T j = 0; j < RowSize; ++j)
        {
            if (i + j < dump.getLength())
            {
                out << std::hex << std::setw(2) << static_cast<int>(dump.getData(i + j)) << " ";
            }
            else
            {
                out << "   ";
            }
        }

        out << " ";
        if (ShowAscii)
        {
            for (T j = 0; j < RowSize; ++j)
            {
                if (i + j < dump.getLength())
                {
                    if (std::isprint(dump.getData(i + j)))
                    {
                        out << static_cast<char>(dump.getData(i + j));
                    }
                    else
                    {
                        out << ".";
                    }
                }
            }
        }
        out << std::endl;
    }
    return out;
}

typedef CustomHexdump<16, true> Hexdump;

#endif // HEXDUMP_HPP
