#include <iostream>
#include <vector>


/*
    source: 
        https://leetcode.com/problems/single-number-iii/
    
    question:
        Given an integer array nums, in which exactly two elements appear only once 
        and all the other elements appear exactly twice. Find the two elements that appear only once.
        You can return the answer in any order.
*/

std::pair<int, int> find_pair(const std::vector<int>& nums)
{
    size_t size         { nums.size() };
    int xor_accumulator { 0 };
    
    int result { 0 };
    for (int n: nums)
        result ^= n;

    int pos     {0};
    while ( (result & 1) == 0 )
    {
        pos++;
        result >>= 1;
    }

    int mask      { 1 << pos };
    int xor_set_a { 0 };
    int xor_set_b { 0 };
    for (int n: nums)
    {
        if (n & mask)
            xor_set_a ^= n;
        else
            xor_set_b ^= n;
    }

    return {xor_set_a, xor_set_b};
}


int main()
{
    // std::vector<int> nums {1,2,1,3,2,5};
    // std::vector<int> nums {-1,0};
    std::vector<int> nums {0,1};

    auto [a, b] = find_pair(nums);
    std::cout << a << " " << b << " \n";

    return 0;
}
