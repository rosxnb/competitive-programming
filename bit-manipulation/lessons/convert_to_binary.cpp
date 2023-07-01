#include <iostream>

int convert_to_binary(int num)
{
    int res     {0};
    int p       {1};

    while (num)
    {
        int last_bit = num & 1;
        int ith_bit  = last_bit * p;

        res += ith_bit;

        p *= 10;
        num >>= 1;
    }

    return res;
}

int main()
{
    int num; std::cin >> num;
    std::cout << convert_to_binary(num) << "\n";

    return 0;
}
