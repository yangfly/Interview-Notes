/*
 * [628] Maximum Product of Three Numbers
 *
 * https://leetcode.com/problems/maximum-product-of-three-numbers/description/
 *
 * algorithms
 * Easy (44.74%)
 * Total Accepted:    41K
 * Total Submissions: 91.7K
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array, find three numbers whose product is maximum and
 * output the maximum product.
 * 
 * Example 1:
 * 
 * Input: [1,2,3]
 * Output: 6
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,3,4]
 * Output: 24
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array will be in range [3,104] and all elements are
 * in the range [-1000, 1000].
 * Multiplication of any three numbers in the input won't exceed the range of
 * 32-bit signed integer.
 * 
 * 
 */
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() == 3)
            return nums[0] + nums[1] + nums[2];
        std::sort(nums.begin(), nums.end());
        int negs = 0;
        for (int num : nums) {
            if (num < 0)
                negs++;
            else
                break;
        }
        int npos = nums.size() - negs;
        if (npos >= 3 && negs >= 2)
            return max(nums[0] * nums[1], nums[nums.size()-2], nums[nums.size()-3]) * nums[nums.size()-1];
        else if (npos >= 3 || npos == 0)
            return nums[nums.size()-2], nums[nums.size()-3] * nums[nums.size()-1];
        else if (npos >= 1 && negs >= 2)
            return nums[0] * nums[1] * nums[nums.size()-1];
        else
            return nums[0] + nums[1] + nums[2];
    }
};


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        return max(nums[0] * nums[1] * nums[2], nums[0] * nums[nums.size()-1] * nums[nums.size()-2]);
    }
};