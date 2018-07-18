/*
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (31.83%)
 * Total Accepted:    204.7K
 * Total Submissions: 642.9K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> rst(2, -1);
        if (nums.empty()) return rst;
        
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target)
                start = mid + 1;
            else if (nums[mid] > target)
                end = mid - 1;
            else {
                // find left boundary
                int s = start, e = mid;
                while (s < e) {
                    int m = s + (e - s) / 2;
                    if (nums[m] < target)
                        s = m + 1;
                    else
                        e = m;
                }
                rst[0] = e;
                // find right boundary
                s = mid, e = end;
                while (s < e) {
                    // 注意判断方向
                    int m = s + (e - s) / 2 + 1; // here make mid right side
                    if (nums[m] > target)
                        e = m - 1;
                    else
                        s = m;
                }
                rst[1] = s;
                return rst;
            }
        }
        // 注意退出条件
        if (nums[start] == target) {
            rst[0] = start;
            rst[1] = start;
        }
        return rst;
    }
};

// A better Solution
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> rst(2, -1);
        if (nums.empty()) return rst;
        
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid;
        }
        if (nums[start] == target) {
            rst[0] = start; // left bound
            end = nums.size() - 1;
            while (start < end) {
                int mid = start + (end - start) / 2 + 1; // right side
                if (nums[mid] > target)
                    end = mid - 1;
                else
                    start = mid;
            }
            rst[1] = end;
        }
        return rst;
    }
};
