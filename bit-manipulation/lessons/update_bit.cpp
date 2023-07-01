#include <iostream>
#include <bitset>

void update_ith_bit(int& num, int pos, int val)
{
    // clear the bit at pos
    int mask = ~(1 << pos);
    num &= mask;

    // set the bit
    mask = (val << pos); // assumption: val is a bit : 0 or 1
    num |= mask;
}

int main()
{
    int in;
    std::cout << "Enter number: "; std::cin >> in;
    std::cout << "The input number " << in << " has binary form: " << std::bitset<8 * sizeof(int)>(in) << "\n";

    int pos;
    std::cout << "Choose position (0-based): "; std::cin >> pos;
    int val;
    std::cout << "Enter bit: "; std::cin >> val;

    update_ith_bit(in, pos, val);
    std::cout << "Output: " << std::bitset<8 * sizeof(int)>(in) << "\n";

    return 0;
}
