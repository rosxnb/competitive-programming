#include <iostream>

bool is_odd(int num)
{
    return num & 1;
}

int main()
{
    int in;
    std::cout << "Enter number: "; std::cin >> in;

    std::cout << ( is_odd(in) ? "Number is Odd" : "Number is Even" ) << "\n";

    return 0;
}
