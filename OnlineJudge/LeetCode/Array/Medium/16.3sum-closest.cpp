/*
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (32.12%)
 * Total Accepted:    186.9K
 * Total Submissions: 582K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

static const auto ______ []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3)
            runtime_error("No solution");
        
        sort(nums.begin(), nums.end());
        int nsum = nums[0] + nums[1] + nums[2];
        for (int l = 0; l < n - 2; l++) {
            int m = l + 1, r = n - 1;
            if (l && nums[l] == nums[l-1]) continue;
            if (nums[l] * 3 > target) break;
            while(m < r) {
                int sum = nums[l] + nums[m] + nums[r];
                if (sum == target)
                    return target;
                else if (sum < target)
                    m++;
                else
                    r--;
                if (abs(sum - target) < abs(nsum - target))
                        nsum = sum;
            } 
        }
        return nsum;
    }
};
