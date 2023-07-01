#include <iostream>
#include <vector>


/*
    source: 
        https://leetcode.com/problems/single-number-ii/
    
    question:
        Given an integer array nums where every element appears three times except for one,
        which appears exactly once. Find the single element and return it.
*/


void update_sum(std::vector<int>& bits_sum, int num)
{
    for (int i = 0; i < 8 * sizeof(int); ++i)
    {
        int ith_bit = num & ( 1 << i );
        if (ith_bit)
            bits_sum[i]++;
    }
}

int binary_to_decimal(const std::vector<int>& bitstring)
{
    int decimal { 0 };
    for (int i = 0; i < static_cast<int>(bitstring.size()); ++i)
        decimal += bitstring[i] * ( 1 << i );
    return decimal;
}

int find_number(const std::vector<int>& nums)
{
    int                 n { 8 * sizeof(int) };
    std::vector<int>    bit_positional_sums(32, 0);

    for (int num: nums)
        update_sum(bit_positional_sums, num);

    for (int& sum: bit_positional_sums)
        sum %= 3;

    return binary_to_decimal(bit_positional_sums);
}

int main()
{
    // std::vector<int> nums {2,2,3,2};
    std::vector<int> nums {0,1,0,1,0,1,99};
    std::cout << find_number(nums) << "\n";

    return 0;
}
