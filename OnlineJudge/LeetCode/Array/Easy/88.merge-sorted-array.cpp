/*
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (32.71%)
 * Total Accepted:    251.2K
 * Total Submissions: 767.9K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 * 
 */

static const auto ________ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int e = m + n - 1;
        m--; n--;
        int x, y;
        int int_min = 0x80000000;
        
        while (m >= 0 || n >= 0) {
            x = m >= 0 ? nums1[m] : int_min;
            y = n >= 0 ? nums2[n] : int_min;
            if (x >= y)
                nums1[e--] = nums1[m--];
            else
                nums1[e--] = nums2[n--];
        }
    }
};


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int e = m + n - 1;
        m--; n--;

        while (n >= 0) {
            if (m >= 0 && nums1[m] > nums2[n])
                nums1[e--] = nums1[m--];
            else
                nums1[e--] = nums2[n--];
        }
    }
};
