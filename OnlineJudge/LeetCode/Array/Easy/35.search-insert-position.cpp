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
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        if (nums[start] >= target)
            return start;
        else
            return start + 1;
    }
};
