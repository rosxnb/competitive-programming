#include <iostream>
#include <bitset>

int get_ith_bit(int num, int pos)
{
    int mask = 1 << pos;
    int res  = ( num & mask);
    return res ? 1 : 0;
}

int main()
{
    int in;
    std::cout << "Enter number: "; std::cin >> in;
    std::cout << "The input number " << in << " has binary form: " << std::bitset<8 * sizeof(int)>(in) << "\n";

    int pos;
    std::cout << "Choose position (0-based): "; std::cin >> pos;

    std::cout << "Result: " << get_ith_bit(in, pos) << "\n";

    return 0;
}
