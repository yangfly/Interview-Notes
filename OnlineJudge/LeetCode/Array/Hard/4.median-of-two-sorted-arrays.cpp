/*
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (23.43%)
 * Total Accepted:    277.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * Example 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * 
 * Example 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */

static const auto ________ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int total = m + n;
        if (total & 0x1)
            return find_kth(nums1.begin(), m, nums2.begin(), n, (total + 1) / 2);
        else
            return (find_kth(nums1.begin(), m, nums2.begin(), n, total / 2)
                   + find_kth(nums1.begin(), m, nums2.begin(), n, total / 2 + 1)) / 2.0;
    }

private:
    int find_kth(vector<int>::const_iterator A, int m,
                 vector<int>::const_iterator B, int n, int k) {
        // always assume m <= n
        if (m > n) return find_kth(B, n, A, m, k);
        if (m == 0) return B[k - 1];
        if (k == 1) return min(*A, *B);

        // devide k into two parts
        int im = min(k / 2, m), in = k - im;
        if (A[im - 1] < B[in - 1])
            return find_kth(A + im, m - im, B, n, k - im);
        else if (A[im - 1] > B[in - 1])
            return find_kth(A, m, B + in, n - in, k - in);
        else
            return A[im - 1];
    }
};
