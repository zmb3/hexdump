hexdump
=======

hexdump is a simple wrapper that allows you to display the contents of memory using C++ streams.  The output is formatted similar to the Linux tool of the same name.

For example, suppose you have an array of data:

```cpp
unsigned char data[150];
unsigned char c = 0;
for (auto& val : data)
{
    val = c++;
}
```

You can display the hexdump of this array with a single line:

```cpp
std::cout << Hexdump(data, sizeof(data)) << std::endl
```

This produces the following output:
```
0x000000: 00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f  ................
0x000010: 10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f  ................
0x000020: 20 21 22 23 24 25 26 27 28 29 2a 2b 2c 2d 2e 2f   !"#$%&'()*+,-./
0x000030: 30 31 32 33 34 35 36 37 38 39 3a 3b 3c 3d 3e 3f  0123456789:;<=>?
0x000040: 40 41 42 43 44 45 46 47 48 49 4a 4b 4c 4d 4e 4f  @ABCDEFGHIJKLMNO
0x000050: 50 51 52 53 54 55 56 57 58 59 5a 5b 5c 5d 5e 5f  PQRSTUVWXYZ[\]^_
0x000060: 60 61 62 63 64 65 66 67 68 69 6a 6b 6c 6d 6e 6f  `abcdefghijklmno
0x000070: 70 71 72 73 74 75 76 77 78 79 7a 7b 7c 7d 7e 7f  pqrstuvwxyz{|}~.
0x000080: 80 81 82 83 84 85 86 87 88 89 8a 8b 8c 8d 8e 8f  ................
0x000090: 90 91 92 93 94 95                                ......
```

## Configuration

Hexdump allows you to configure the length of each row (number of bytes displayed).  Additionally, the ASCII text display can be disabled.  To configure these features, use the `CustomHexdump` class template.  The class accepts two template arguments, the first being the length of the row, and the second being a boolean indicating whether or not the ASCII text should be displayed.

For example:

```cpp
// row length of 8, with ASCII
std::cout << CustomHexdump<8, true>(data, sizeof(data)) << std::endl;
```

Produces:
```
0x000000: 00 01 02 03 04 05 06 07  ........
0x000008: 08 09 0a 0b 0c 0d 0e 0f  ........
0x000010: 10 11 12 13 14 15 16 17  ........
0x000018: 18 19 1a 1b 1c 1d 1e 1f  ........
0x000020: 20 21 22 23 24 25 26 27   !"#$%&'
0x000028: 28 29 2a 2b 2c 2d 2e 2f  ()*+,-./
0x000030: 30 31 32 33 34 35 36 37  01234567
0x000038: 38 39 3a 3b 3c 3d 3e 3f  89:;<=>?
0x000040: 40 41 42 43 44 45 46 47  @ABCDEFG
0x000048: 48 49 4a 4b 4c 4d 4e 4f  HIJKLMNO
0x000050: 50 51 52 53 54 55 56 57  PQRSTUVW
0x000058: 58 59 5a 5b 5c 5d 5e 5f  XYZ[\]^_
0x000060: 60 61 62 63 64 65 66 67  `abcdefg
0x000068: 68 69 6a 6b 6c 6d 6e 6f  hijklmno
0x000070: 70 71 72 73 74 75 76 77  pqrstuvw
0x000078: 78 79 7a 7b 7c 7d 7e 7f  xyz{|}~.
0x000080: 80 81 82 83 84 85 86 87  ........
0x000088: 88 89 8a 8b 8c 8d 8e 8f  ........
0x000090: 90 91 92 93 94 95        ......

And

```cpp
// row length of 32, with no ASCII text
std::cout << CustomHexdump<32, false>(data, sizeof(data)) << std::endl;
```

Produces:
```
0x000000: 00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f 10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f 
0x000020: 20 21 22 23 24 25 26 27 28 29 2a 2b 2c 2d 2e 2f 30 31 32 33 34 35 36 37 38 39 3a 3b 3c 3d 3e 3f 
0x000040: 40 41 42 43 44 45 46 47 48 49 4a 4b 4c 4d 4e 4f 50 51 52 53 54 55 56 57 58 59 5a 5b 5c 5d 5e 5f 
0x000060: 60 61 62 63 64 65 66 67 68 69 6a 6b 6c 6d 6e 6f 70 71 72 73 74 75 76 77 78 79 7a 7b 7c 7d 7e 7f 
0x000080: 80 81 82 83 84 85 86 87 88 89 8a 8b 8c 8d 8e 8f 90 91 92 93 94 95 
```
## Usage

Hexdump is header-only.  To use it, simply place the `Hexdump.hpp` file on your include path and `#include` it.  See the example for reference.
