/*
 * [154] Find Minimum in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Hard (38.14%)
 * Total Accepted:    101.6K
 * Total Submissions: 266.4K
 * Testcase Example:  '[1,3,5]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * The array may contain duplicates.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5]
 * Output: 1
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,2,0,1]
 * Output: 0
 * 
 * Note:
 * 
 * 
 * This is a follow up problem to Find Minimum in Rotated Sorted Array.
 * Would allow duplicates affect the run-time complexity? How and why?
 * 
 * 
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            runtime_error("Invalid numbers");
        int s = 0, m, e = nums.size() - 1;
        while (s < e) {
            m = s + ((e - s) >> 1);
            if (nums[m] < nums[e]) { // [1,3,5]
                e = m;
            }
            else if (nums[m] > nums[e]) { // [3,1]
                s = m + 1;
            }
            else {
                e--;
            }
        }
        return nums[s];
    }
};
