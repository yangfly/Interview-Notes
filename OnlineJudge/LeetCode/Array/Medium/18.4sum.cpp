/*
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (27.96%)
 * Total Accepted:    167K
 * Total Submissions: 597.1K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
static const auto ______ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> rst;
        if (n < 4)  return rst;
        sort(nums.begin(), nums.end());
        int Min = target - 3 * nums[n - 1];
        for (int a = 0; a < n - 3; a++) {
            if (a && nums[a] == nums[a-1]) continue;
            if (nums[a] < Min) continue; // too small
            if (nums[a] * 4 > target) break; // too large
            else if (nums[a] * 4 == target) {
                if (nums[a + 3] == nums[a])
                    rst.push_back(vector<int>(4, nums[a]));
                break;              
            }
            threeSum(nums, target, a, rst);
        }
        return rst;
    }
    
    void threeSum(const vector<int>& nums, int target,
                  int a, vector<vector<int>>& rst) {
        int n = nums.size();
        target -= nums[a];
        for (int b = a + 1; b < n - 2; b++) {
            if (b > a + 1 && nums[b] == nums[b-1]) continue;
            if (nums[b] * 3 > target) break;
            int c = b + 1, d = n - 1;
            while (c < d) {
                int sum = nums[b] + nums[c] + nums[d];
                if (sum == target) {
                    vector<int> quad = {nums[a], nums[b], nums[c], nums[d]};
                    rst.push_back(quad);
                    while (nums[++c] == quad[2] && c < d);
                    while (nums[--d] == quad[3] && c < d);
                }
                else if (sum < target)
                    c++;
                else
                    d--;
            }
        }
    }
};
