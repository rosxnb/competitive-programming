#include <iostream>
#include <vector>


/*
    source: 
        https://leetcode.com/problems/single-number/
    
    question:
        Given a non-empty array of integers nums, every element appears twice except for one.
        Find that single one.
*/


int find_unique(const std::vector<int>& nums)
{
    size_t  n                   { nums.size() };
    int     xor_accumulator     { 0 };

    for (int num: nums)
        xor_accumulator ^= num;

    return xor_accumulator;
}

int main()
{
    // std::vector<int> nums {2,2,1};
    std::vector<int> nums {4,1,2,1,2};
    // std::vector<int> nums {1};

    std::cout << find_unique(nums) << std::endl;

    return 0;
}
