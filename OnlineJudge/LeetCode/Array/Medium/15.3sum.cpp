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

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		size_t n = nums.size();
		if (n < 3)
			return result;
        vector<vector<int>> result;
		std::sort(nums.begin(), nums.end());
		int target = 0;
        std::vector<int> q(3);
        for(size_t i=0; i + 2 < n; ++i) {
            if (i && nums[i-1] == nums[i]) continue;
            if (nums[i] > target) break;
            int v= target - nums[i];        
            size_t j = i + 1, k = n - 1;
            while (j < k) {
                int tmp = nums[j] + nums[k];
                if (tmp == v) {
                    q[0] = nums[i];
                    q[1] = nums[j];
                    q[2] = nums[k];
                    result.push_back(q);
                    while (j < k && nums[j] == q[1]) ++j;
                    while (k > j && nums[k] == q[2]) --k;
                }
                else if (tmp < v) ++j;
                else --k;
            }
        } 
        return result;
    }
};
