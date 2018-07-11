/*
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (39.88%)
 * Total Accepted:    188.4K
 * Total Submissions: 472.4K
 * Testcase Example:  '[]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Credits:Special thanks to @ifanchu for adding this problem and creating all
 * test cases. Also thanks to @ts for adding additional test cases.
 */
#include "common.h"

// My Solution 4ms
// 注意边界条件
static auto _________ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int rob(vector<int>& nums) {
        std::size_t size = nums.size();
        if (size == 0)
            return 0;
        else if (size == 1)
            return nums[0];

        vector<int> maxs(size);
        maxs[0] = nums[0];
        maxs[1] = max(nums[0], nums[1]);
        for (std::size_t i = 2; i < size; i++) {
            maxs[i] = max(maxs[i-1], maxs[i-2] + nums[i]);
        }
        return maxs[size - 1];
    }
};

// A Simpler Solution
class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0, b = 0;
        for (std::size_t i = 0; i < nums.size(); i++) {
            // a, b 交替记录最大抢劫金额。(状态：抢/没抢)
            if (i % 2  == 0)
                a = max(a + nums[i], b);
            else
                b = max(b + nums[i], a);
        }
        return max(a, b);
    }
};