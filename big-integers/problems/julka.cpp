/*
    source: 
        https://www.spoj.com/problems/tag/big-numbers
*/

#include <iostream>
#include <algorithm>

int char_to_digit(char ch)
{ return ch - '0'; }

char digit_to_char(int d)
{ return d + '0'; }

std::string num_add(std::string& a, std::string& b)     // a > b
{
    if (a.length() < b.length())
        std::swap(a, b);

    std::string result {};
    int carry {0};

    int b_digits = b.length();
    int a_digits = a.length();
    int a_lefts  = a_digits - b_digits;

    for (int i = b_digits - 1; i >= 0; --i)   // exhaust small number first
    {
        int d1  = char_to_digit( a[a_lefts + i] );
        int d2  = char_to_digit( b[i] );
        int sum = d1 + d2 + carry;

        result.push_back(digit_to_char( sum % 10));
        carry = sum / 10;
    }

    for (int i = a_lefts - 1; i >= 0; --i)  // exhuast remaining digits of big number
    {
        int d1  = char_to_digit( a[i] );
        int sum = d1 + carry;

        result.push_back(digit_to_char( sum % 10));
        carry = sum / 10;
    }

    if (carry) result.push_back('1');
    std::reverse(result.begin(), result.end());

    return result;
}

void take_borrow(std::string& num, int idx)
{
    if (idx == 0)
    {
        num[0]--;
        return;
    }

    int current_digit = char_to_digit( num[idx] );
    if ( current_digit == 0 )
    {
        take_borrow(num, idx - 1);
        num[idx] = '9';
        return;
    }

    num[idx]--;
}

std::string num_subtract(std::string& a, const std::string& b)
{
    std::string result {};

    int b_digits = b.length();
    int a_digits = a.length();
    int a_lefts  = a_digits - b_digits;

    for (int i = b_digits - 1; i >= 0; --i)
    {
        int idx_a = a_lefts + i;
        if (idx_a == 0) break;

        int d1 = char_to_digit( a[idx_a] );
        int d2 = char_to_digit( b[i] );

        if (d1 < d2)
        {
            take_borrow(a, idx_a - 1);
            d1 += 10;
        }

        result.push_back( digit_to_char(d1 - d2) );
    }

    for (int i = a_lefts - 1; i > 0; --i)
        result.push_back(a[i]);

    if ( (a_lefts != 0) and (a[0] != '0') ) result.push_back(a[0]);
    std::reverse(result.begin(), result.end());

    return result;
}

std::string num_divide(const std::string& dividend, int divisor)
{
    int idx {0};
    int prefix { char_to_digit(dividend[idx]) };
    int len { static_cast<int>(dividend.length()) };

    while ( (idx < len) and (prefix < divisor) )
        prefix = prefix * 10 + char_to_digit(dividend[++idx]);

    std::string result {};
    while (idx < len)
    {
        result.push_back( digit_to_char(prefix / divisor) );
        prefix = (prefix % divisor) * 10 + char_to_digit(dividend[++idx]);
    }

    return result == "" ? "0" : result;     // when dividend is string of 0's, return "0"
}

std::pair<std::string, std::string> divide_apples(std::string& n, std::string& a)
{
    std::string e = num_subtract(n, a);  // apples that can be divided equally in half
    std::string p = num_divide(e, 2);    // least apples each person will get
    std::string r2 = p;                  // store result as num_add(str, str) can modify it
    std::string r1 = num_add(p, a);

    return { r1, r2 };
}

int main()
{
    std::string n, a;   // n: total number of apples, a: additional apples Klaudia has
    int t {10};

    // std::cout << num_add(n, a);
    // std::cout << num_subtract(n, a);
    // std::cout << num_divide(n, a);

    while (t--)
    {
        std::cin >> n >> a;

        auto res = divide_apples(n, a);
        std::cout << res.first << "\n" << res.second << "\n";
    }

    return 0;
}
