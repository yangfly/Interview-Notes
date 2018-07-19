/*
 * [804] Rotated Digits
 *
 * https://leetcode.com/problems/rotated-digits/description/
 *
 * algorithms
 * Easy (51.00%)
 * Total Accepted:    12.4K
 * Total Submissions: 24.3K
 * Testcase Example:  '10'
 *
 * X is a good number if after rotating each digit individually by 180 degrees,
 * we get a valid number that is different from X.  Each digit must be rotated
 * - we cannot choose to leave it alone.
 * 
 * A number is valid if each digit remains a digit after rotation. 0, 1, and 8
 * rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each
 * other, and the rest of the numbers do not rotate to any other number and
 * become invalid.
 * 
 * Now given a positive number N, how many numbers X from 1 to N are good?
 * 
 * 
 * Example:
 * Input: 10
 * Output: 4
 * Explanation: 
 * There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
 * Note that 1 and 10 are not good numbers, since they remain unchanged after
 * rotating.
 * 
 * 
 * Note:
 * 
 * 
 * N  will be in range [1, 10000].
 * 
 * 
 */
class Solution {
public:
    int rotatedDigits(int N) {
        int n = 0;
        int digit[7] = {0, 1, 2, 5, 6, 8, 9};
        for (int h = 1; h < 7; h++) {
            int dig = digit[h];
            if (dig > N)
                break;
            if (rotate(dig)) n++;
            for (int i = 0; i < 7; i++) {
                int dig1 = dig * 10 + digit[i];
                if (dig1 > N)
                    break;
                if (rotate(dig1)) n++;
                for (int j = 0; j < 7; j++) {
                    int dig2 = dig1 * 10 + digit[j];
                    if (dig2 > N)
                        break;
                    if (rotate(dig2)) n++;
                    for (int k = 0; k < 7; k++) {
                        int dig3 = dig2 * 10 + digit[k];
                        if (dig3 > N)
                            break;
                        if (rotate(dig3)) n++;
                    }
                }
            }
        }
        return n;
    }
    
    bool rotate(int x) {
        while (x > 0) {
            int r = x % 10;
            if (r == 2 || r == 5 || r == 6 || r == 9)
                return true;
            x /= 10;
        }
        return false;
    }
};


class Solution {
public:
    int digit[7] = {0, 1, 2, 5, 6, 8, 9};
    
    int rotatedDigits(int N) {
        int n = 0;    
        for (int h = 1; h < 7; h++) {
            int dig = digit[h];
            if (dig <= N) {
                if (rotate(dig)) n++;
                n += headRotate(N, dig);
            }
        }
        return n;
    }

    int headRotate(int N, int H) {
        int n = 0;
        for (int i = 0; i < 7; i++) {
            int dig = H * 10 + digit[i];
            if (dig <= N) {
                if (rotate(dig)) n++;
                n += headRotate(N, dig);
            }
        }
        return n;
    }
    
    bool rotate(int x) {
        while (x > 0) {
            int r = x % 10;
            if (r == 2 || r == 5 || r == 6 || r == 9)
                return true;
            x /= 10;
        }
        return false;
    }
};
