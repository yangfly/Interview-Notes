/*
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (31.98%)
 * Total Accepted:    275.1K
 * Total Submissions: 860.4K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size();
        while (start < end) {
            int mid = (start + end) / 2;
            if (target == nums[mid])
                return mid;
            if (nums[start] < nums[mid]) {  // [2,3,4,^,5,0,1]
                if (nums[start] <= target && target < nums[mid])
                    end = mid;
                else
                    start = mid + 1;
            }
            else {  // [5,0,1,^,2,3,4]
                if (nums[mid] < target && target <= nums[end-1]
                    start = mid + 1;
                else
                    end = mid;
            }
        }
        return -1;
    }
};