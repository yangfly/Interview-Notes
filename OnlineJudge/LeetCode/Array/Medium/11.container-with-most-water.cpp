/*
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (37.35%)
 * Total Accepted:    215K
 * Total Submissions: 575.6K
 * Testcase Example:  '[1,1]'
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if (n < 2) return 0;
        int l = 0, r = n - 1;
        int Max = 0;
        while (l < r) {
            Max = max(Max, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) l++;
            else r--;
        }
        return Max;
    }
};


