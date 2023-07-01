#include <iostream>
#include <bitset>

// int count_set_bits(int num)
// {
//     int count {0};
//     while (num)
//     {
//         if (num & 1) count++;
//         num >>= 1;
//     }
//     return count;
// }

int count_set_bits(int num)
{
    int count {0};
    for ( ; num != 0; ++count )
        num &= (num - 1);
    return count;
}

int main()
{
    int num; std::cin >> num;
    std::cout << std::bitset<8 * sizeof(int)>(num) << "\n";

    std::cout << count_set_bits(num) << "\n";
    return 0;
}
