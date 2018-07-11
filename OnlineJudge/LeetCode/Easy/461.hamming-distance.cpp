/*
 * [461] Hamming Distance
 *
 * https://leetcode.com/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (69.56%)
 * Total Accepted:    140.9K
 * Total Submissions: 202.5K
 * Testcase Example:  '1\n4'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 * 
 * Given two integers x and y, calculate the Hamming distance.
 * 
 * Note:
 * 0 ≤ x, y < 231.
 * 
 * 
 * Example:
 * 
 * Input: x = 1, y = 4
 * 
 * Output: 2
 * 
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * ⁠      ↑   ↑
 * 
 * The above arrows point to positions where the corresponding bits are
 * different.
 * 
 * 
 */
#include "common.h"

// My Solution 4ms
// 注意边界条件
static auto _________ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x ^ y, dist = 0;
        while (diff) {
            diff = diff & (diff - 1);
            dist++;
        }
        return dist;
    }
};

// Another Solution
class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> xbs(x);
        bitset<32> ybs(y);
        int count = 0;
        for (size_t i = 0; i < 32; i++) {
            if (xbs[i] != ybs[i])
                count++;
        }
        return count;
    }
};