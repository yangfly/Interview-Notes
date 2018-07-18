/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (21.84%)
 * Total Accepted:    349K
 * Total Submissions: 1.6M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> rst;
        for (int left = 0; left < nums.size(); left++) {
            if (nums[left] > 0) break;
            // 跳过 left 重复匹配
            if (left > 0 && nums[left] == nums[left-1])
                continue;
            int mid = left + 1, right = nums.size() - 1;
            int tmp = -nums[left];
            while (mid < right) {
                int tmp_mid = nums[mid], tmp_right = nums[right];
                if (nums[mid] + nums[right] == tmp) {
                    rst.push_back(vector<int>{nums[left], nums[mid], nums[right]});
                    // 跳过 right 和 mid 的重复匹配
                    while (mid < right && nums[++mid] == tmp_mid);
                    while (mid < right && nums[--right] == tmp_right);
                }
                else if (nums[mid] + nums[right] < tmp)
                    mid++;
                else
                    right--;
            }
        }
        return rst;
    }
};


static const auto ______ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> rst;
        if (n < 3)
            return rst;
        sort(nums.begin(), nums.end());
        for (int left = 0; left < n - 2; left++) {
            if (left && nums[left] == nums[left-1]) continue;
            if (nums[left] > 0) break;
            int mid = left + 1, right = n - 1;
            while (mid < right) {
                int sum = nums[left] + nums[mid] + nums[right];
                if (sum == 0) {
                    vector<int> triplet = {nums[left], nums[mid], nums[right]};
                    rst.push_back(triplet);
                    while(nums[++mid] == triplet[1] && mid < right);
                    while(nums[--right] == triplet[2] && mid < right);
                }
                else if (sum < 0)
                    mid++;
                else
                    right--;
            }
        }
        return rst;
    }
};
