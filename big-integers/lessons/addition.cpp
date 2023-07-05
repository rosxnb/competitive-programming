#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

std::ostream& operator <<(std::ostream& print, const std::vector<int>& digits)
{
    for (auto it = digits.rbegin(); it != digits.rend(); ++it)
        print << *it;
    return print;
}

std::vector<int> addition(ll a, ll b)
// it is assumend that b is greater that a
{
    std::vector<int> result;
    int              carry = 0;

    while (a)
    {
        int a_ld    = a % 10;
        int b_ld    = b % 10;
        int sum     = a_ld + b_ld + carry;
        
        carry = sum / 10;
        result.push_back(sum % 10);

        a /= 10;
        b /= 10;
    }

    while (b)
    {
        int b_ld = b % 10;
        int sum  = b_ld + carry;
        
        carry = sum / 10;
        result.push_back(sum % 10);

        b /= 10;
    }

    if (carry)
    {
        result.push_back(carry);
    }

    return result;
}

int main()
{
    ll a, b;
    std::cout << "Enter two integers: \n"; std::cin >> a >> b;

    std::cout << "Normal addition:        " << a + b << std::endl;
    std::cout << "Array Storage addition: " << addition(a, b) << std::endl;

    return 0;
}
