/*
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (40.04%)
 * Total Accepted:    240.1K
 * Total Submissions: 599.6K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */
#include "common.h"

// My Solution 244ms
// 遍历查找 O(n)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (std::size_t i = 0; i < nums.size(); i++) {
            if (target <= nums[i]) {
                return i;
            }
        }
        return nums.size();
    }
};

// Quickest Solution 3ms
// 二分查找 O(logn)
static const auto __________ = []()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (target == nums[mid]) return mid;
            if (target < nums[mid]) {
                hi = mid - 1;
            } else {
                lo = mid +1;
            }
        }
        if (nums[lo] >= target) return lo;
        else return lo + 1;
    }
};