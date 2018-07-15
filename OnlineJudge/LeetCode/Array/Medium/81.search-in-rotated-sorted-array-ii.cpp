/*
 * [81] Search in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (32.55%)
 * Total Accepted:    126.8K
 * Total Submissions: 389.6K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return true,
 * otherwise return false.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 * 
 * Follow up:
 * 
 * 
 * This is a follow up problem to Search in Rotated Sorted Array, where nums
 * may contain duplicates.
 * Would this affect the run-time complexity? How and why?
 * 
 * 
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size();
        while (start < end) {
            int mid = (start + end) / 2;
            if (target == nums[mid])
                return true;
            if (nums[start] < nums[mid]) {
                // [456^712]
                if (nums[start] <= target && target < nums[mid])
                    end = mid;
                else
                    start = mid + 1;
            }
            else if (nums[mid] < nums[end-1]) {
                // [561^234]
                if (nums[mid] < target && target <= nums[end-1])
                    start = mid + 1;
                else
                    end = mid;
            }
            else if (nums[start] == nums[mid]) 
                start++;  // take care [3,1] 3
            else
                end--;    // take care [2,2,2,0,1] 0
        }
        return false;
    }
};
