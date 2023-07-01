#include <iostream>
#include <bitset>

/*
    Given two 32-bits numbers, N and M, and two bit positions i and j.
    Write a function to set all bits between i and j in N equal to M.

    Example:
        N = 10000000000
        M = 10101
        i = 2, j = 6
        Output = 1001010100
*/

int replace_bits(int n, int m, int i, int j)
{
    // clear the bits in range in n
    int left_padding  = -1 << j;
    int right_padding = (1 << i) - 1;
    int mask          = left_padding | right_padding;
    n &= mask;

    // replace bits in n with m
    m <<= i;
    return n | m;
}

int main()
{
    int n = 0b10000000000;
    int m = 0b10101;
    int i = 2, j = 6;

    int res = replace_bits(n, m, i, j); 
    std::cout << std::boolalpha << ( res == 0b10001010100 ) << "\n";
    std::cout << ( std::bitset<20>(res) ) << "\n";

    return 0;
}
