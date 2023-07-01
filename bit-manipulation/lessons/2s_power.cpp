#include <iostream>

bool is_tows_power(int number)
{
    return ( (number & (number - 1)) == 0  );
}

int main()
{
    int num; std::cin >> num;
    std::cout << std::boolalpha << is_tows_power(num) << "\n";

    return 0;
}
