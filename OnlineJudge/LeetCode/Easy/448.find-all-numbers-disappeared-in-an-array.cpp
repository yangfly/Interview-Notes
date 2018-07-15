/*
 * [448] Find All Numbers Disappeared in an Array
 *
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (51.19%)
 * Total Accepted:    80.7K
 * Total Submissions: 157.6K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some
 * elements appear twice and others appear once.
 * 
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * 
 * Could you do it without extra space and in O(n) runtime? You may assume the
 * returned list does not count as extra space.
 * 
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [5,6]
 * 
 * 
 */
#include "common.h"

// My Solution 117ms
static auto _________ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        size_t size = nums.size();
        // use the vector itself to mark if numbers has appeared
        // negative if appeared else positive.
        for (size_t i = 0; i < size; i++) {
            size_t index = abs(nums[i]) - 1;
            if (nums[index] > 0)
                nums[index] = -nums[index];
        }
        vector<int> result;
        for (size_t i = 0; i < size; i++) {
            if (nums[i] > 0)
                result.push_back(i + 1);
        }
        return result;
    }
};
