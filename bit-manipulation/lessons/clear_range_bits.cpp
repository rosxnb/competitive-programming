#include <iostream>
#include <bitset>

void clear_range_bits(int& num, int front, int back)
{
    int front_mask = -1 << (front + 1);
    int back_mask  = (1 << back) - 1;
    int mask       = front_mask | back_mask;
    num &= mask;
}

int main()
{
    int in;
    std::cout << "Enter number: "; std::cin >> in;
    std::cout << "The input number " << in << " has binary form: " << std::bitset<8 * sizeof(int)>(in) << "\n";

    int front;
    std::cout << "Enter front pos : "; std::cin >> front;
    int back;
    std::cout << "Enter back pos  : "; std::cin >> back;

    clear_range_bits(in, front, back);
    std::cout << "Output: " << std::bitset<8 * sizeof(int)>(in) << "\n";

    return 0;
}
