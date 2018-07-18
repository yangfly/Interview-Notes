/*
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (41.29%)
 * Total Accepted:    208K
 * Total Submissions: 503.7K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,4,5,1,2] 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
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
