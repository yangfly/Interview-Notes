/*
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (37.61%)
 * Total Accepted:    834.7K
 * Total Submissions: 2.2M
 * Testcase Example:  '[3,2,4]\n6'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */
#include "common.h"

// My Solution 244ms
// 暴力搜索 O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    result[0] = i;
                    result[1] = j;
                }
            }
        }
        return result;
    }
};

// Quickest Solution 3ms
// 全局匿名函数 io加速
static const auto __________ = []()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        using SizeType = remove_reference_t<decltype(nums)>::size_type;
        // 把历史存入hashmap，避免重复计算
        using ValueToIndexMapType = unordered_map<int, SizeType>;
        ValueToIndexMapType map;
        for (SizeType index = 0; index < nums.size(); ++index)
        {
            const auto foundIterator = map.find(target - nums[index]);
            if (foundIterator != end(map) && foundIterator->second != index)
                return vector<int>{ index, foundIterator->second };
            else
                map.emplace(nums[index], index);    
        }
        throw std::runtime_error("Solution not found");
    }
};
