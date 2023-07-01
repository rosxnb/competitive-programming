#include <iostream>
#include <bitset>

void clear_ith_bit(int& num, int pos)
{
    int mask = ~(1 << pos);
    num &= mask;
}


int main()
{
    int in;
    std::cout << "Enter number: "; std::cin >> in;
    std::cout << "The input number " << in << " has binary form: " << std::bitset<8 * sizeof(int)>(in) << "\n";

    int pos;
    std::cout << "Choose position (0-based): "; std::cin >> pos;

    clear_ith_bit(in, pos);
    std::cout << "Output: " << std::bitset<8 * sizeof(int)>(in) << "\n";

    return 0;
}
