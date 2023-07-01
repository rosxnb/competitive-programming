#include <iostream>
#include <bitset>

void clear_last_ith_bits(int& num, int val)
{
    int mask = -1 << val;
    num &= mask;
}

int main()
{
    int in;
    std::cout << "Enter number: "; std::cin >> in;
    std::cout << "The input number " << in << " has binary form: " << std::bitset<8 * sizeof(int)>(in) << "\n";

    int val;
    std::cout << "Enter count: "; std::cin >> val;

    clear_last_ith_bits(in, val);
    std::cout << "Output: " << std::bitset<8 * sizeof(int)>(in) << "\n";

    return 0;
}
