/*
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (26.15%)
 * Total Accepted:    199.1K
 * Total Submissions: 761.1K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-1,-100,3,99] and k = 2
 * Output: [3,99,-1,-100]
 * Explanation: 
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * 
 * 
 * Note:
 * 
 * 
 * Try to come up as many solutions as you can, there are at least 3 different
 * ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 * 
 * 
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if (k > 0) {
            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin() + k);
            reverse(nums.begin() + k, nums.end());
        }
    }
};

// STL details
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k % n == 0) return;
        int first = 0, middle = n - k % n, last = n;
        int next = middle;
        while (first != next) {
            swap(nums[first++], nums[next++]);
            if (next == last) next = middle;
            else if (first == middle) middle = next;
        }
    }
};

// STL
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = n - k % n;
        std::rotate(nums.begin(), nums.begin() + k, nums.end());
    }
};

// Juggling Algorithm
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if ((n == 0) || (k <= 0)) return;
        int cnt = 0; // rotated num
        int start = 0, curr = 0;
        int tmp = nums[start];
        while (cnt < n) {
            do {
                curr = (curr + k) % n;
                swap(nums[curr], tmp);
                cnt++;
            } while (curr != start);
            tmp = nums[++start];
            curr = start;
        }
    }
};
