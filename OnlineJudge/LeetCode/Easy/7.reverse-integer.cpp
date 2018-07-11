/*
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (24.37%)
 * Total Accepted:    376.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * Input: 123
 * Output:  321
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only hold integers
 * within the 32-bit signed integer range. For the purpose of this problem,
 * assume that your function returns 0 when the reversed integer overflows.
 * 
 */

#include "common.h"

// My Solution 31ms
class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN)
            return 0;
        if (x < 0)
            return -reverse(-x);
        
        int rx = 0;
        while(x != 0) {
            // check overflow
            if (rx > (INT_MAX - x % 10) / 10)
                return 0;
            rx = rx * 10 + x % 10;
            x /= 10;
        }
        
        return rx;
    }
};

// Quickest Solution 5ms
// 全局匿名函数
static int x = []() { 
     // 关闭cin与stdin的同步，减小io延时
    ios::sync_with_stdio(false);
    // 关于cin与cout的绑定，减小<<的flush
    cin.tie(NULL);  
    return 0; 
}();    // 定义后执行

class Solution {
public:
    int reverse(int x) {
        // 使用long逃避32位越界
        long answer = 0;
        while (x != 0) {
            answer = answer * 10 + x % 10;
            if (answer > INT_MAX || answer < INT_MIN) return 0;
            x /= 10;
        }
        return (int)answer;
    }
};
