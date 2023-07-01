#include <iostream>
#include <vector>


/*
    source:
       https://leetcode.com/problems/subsets/ 

    question:
        Given an integer array nums of unique elements, return all possible subsets (the power set).
        The solution set must not contain duplicate subsets. Return the solution in any order
*/


std::vector<std::vector<int>> find_subsets(const std::vector<int>& nums)
{
    size_t                          n { nums.size() };
    std::vector<std::vector<int>>   subsets;

    int set_size { 1 << n };
    for (size_t i = 0; i < set_size; ++i)
    {
        std::vector<int> subset;
        for (size_t j = 0; j < n; ++j)
        {
            if ( i & (1 << j) )
                subset.push_back(nums[j]);
        }
        subsets.push_back(subset);
    }

    return subsets;
}


int main()
{
    // std::vector<int> nums {1,2,3};
    std::vector<int> nums {0};

    auto subsets = find_subsets(nums);
    for (const auto& subset: subsets)
    {
        for (const int n: subset)
            std::cout << n << " ";
         std::cout << "\n";
    }

    return 0;
}
