#include <iostream>
#include <vector>

int multiply(std::vector<int>& result, int num, int size)
{
    int carry = 0;
    for (int i = 0; i < size; ++i)
    {
        int product = result[i] * num + carry;

        result[i] = product % 10;
        carry = product / 10;
    }

    while (carry)
    {
        result[size++] = carry % 10;
        carry /= 10;
    }

    return size;
}

void print_factorial(int num)
// stores the factorial in an array in little endian form
{
    std::vector<int> result(1000, 0);

    result[0] = 1;
    int size = 1;   // num of digits in the result
    for (int n = 2; n <= num; ++n)
    {
        size = multiply(result, n, size);
    }

    for (int i = size - 1; i >= 0; --i)
        std::cout << result[i];
    std::cout << std::endl;
}

int main()
{
    int input;
    std::cin >> input;
    print_factorial(input);

    return 0;
}
