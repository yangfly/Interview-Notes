/*
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (35.69%)
 * Total Accepted:    307.2K
 * Total Submissions: 860.9K
 * Testcase Example:  '-2147483648'
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 
 * click to show spoilers.
 * 
 * Some hints:
 * 
 * Could negative integers be palindromes? (ie, -1)
 * 
 * If you are thinking of converting the integer to string, note the
 * restriction of using extra space.
 * 
 * You could also try reversing an integer. However, if you have solved the
 * problem "Reverse Integer", you know that the reversed integer might
 * overflow. How would you handle such case?
 * 
 * There is a more generic way of solving this problem.
 * 
 * 
 */
#include "common.h"

// My Solution 147ms
// 逆序后比较
// 注意避免数值越界 overflow
static auto _________ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long lx = x, rx = 0;
        while (x) {
            rx = rx * 10 + x % 10;
            x /= 10;
        }
        return (lx == rx);
    }
};


// Quicker Solution 143ms
// 只逆序后面一半，然后与前面一半做对比
// 负数不可能是回文数
// 数不可能以零开头，所以非零回文数不可能以0结尾
static auto _________ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reverted = 0;
        while (x > reverted) {
            reverted = reverted * 10 + x % 10;
            x /= 10;
        }
        return (x == reverted || x == reverted / 10);
    }
};