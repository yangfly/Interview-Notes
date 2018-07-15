/*
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (28.18%)
 * Total Accepted:    65.6K
 * Total Submissions: 232.6K
 * Testcase Example:  '[3,2,1]'
 *
 * Given a non-empty array of integers, return the third maximum number in this
 * array. If it does not exist, return the maximum number. The time complexity
 * must be in O(n).
 * 
 * Example 1:
 * 
 * Input: [3, 2, 1]
 * 
 * Output: 1
 * 
 * Explanation: The third maximum is 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2]
 * 
 * Output: 2
 * 
 * Explanation: The third maximum does not exist, so the maximum (2) is
 * returned instead.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [2, 2, 3, 1]
 * 
 * Output: 1
 * 
 * Explanation: Note that the third maximum here means the third maximum
 * distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 * 
 * 
 */
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> top(3, INT_MIN);
        int mim = INT_MAX;
        for (int num : nums) {
            if (num > top[0]) {
                top[2] = top[1];
                top[1] = top[0];
                top[0] = num;
            }
            else if (num < top[0] && num > top[1]) {
                top[2] = top[1];
                top[1] = num;
            }
            else if (num < top[1] && num > top[2]) {
                top[2] = num;
            }
            mim = min(mim, num);
        }

        if (top[2] >= mim && top[2] < top[1])
            return top[2];
        else
            return top[0];
    }
};
