/*
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (41.29%)
 * Total Accepted:    208K
 * Total Submissions: 503.7K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,4,5,1,2] 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 * 
 * 
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return -1;
        if (nums.size() == 1) return nums[0];
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            if (nums[start] < nums[end]) break;
            int mid = start + (end - start) / 2;
            if (nums[start] > nums[mid]) // [450^123]
                end = mid;
            else // [345^012]
                start = mid + 1;
        }
        return nums[start];
    }
};
