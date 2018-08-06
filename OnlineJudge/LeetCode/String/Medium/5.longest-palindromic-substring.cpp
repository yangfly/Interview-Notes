/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.62%)
 * Total Accepted:    348.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

class Solution {
  public:
    int longestPalindrome1(string s) {
        int n = s.length();
        string new_s(2*n+2, '#');
        new_s[0] = '$';
        for (int i = 0; i < n; i++)
            new_s[2*i+2] = s[i];
        vector<int> P(2*n+2);
        int mam = 0, id, rm = 0;
        for (int i = 1; i < 2*n+2; i++) {
            if (i < rm)
                P[i] = min(P[2*id-i], rm-i);
            else
                P[i] = 1;
            while (new_s[i-P[i]] == new_s[i+P[i]])
                P[i]++;
            if (rm < i + P[i]) {
                id = i;
                rm = i + P[i];
            }
            mam = max(mam, P[i]);
        }
        return mam - 1;
    }

    string longestPalindrome2(string s) {
        int n = s.length();
        string new_s(2*n+2, '#');
        new_s[0] = '$';
        for (int i = 0; i < n; i++)
            new_s[2*i+2] = s[i];
        vector<int> P(2*n+2);
        int mdx = 1, id, rm = 0;
        for (int i = 1; i < 2*n+2; i++) {
            if (i < rm)
                P[i] = min(P[2*id-1], rm-i);
            else
                P[i] = 1;
            while (new_s[i-P[i]] == new_s[i+P[i]])
                P[i]++;
            if (rm < i + P[i]) {
                rm = i + P[i];
                id = i;
            }
            if (P[mdx] < P[i])
                mdx = i;
        }
        return s.substr((mdx-P[mdx])/2, P[mdx]-1);
    }
};

int main()
{
    Solution so;
    cout << so.longestPalindrome1("babad") << endl;
    cout << so.longestPalindrome1("cbbd") << endl;
    cout << so.longestPalindrome1("babadada") << endl;
    cout << so.longestPalindrome2("babad") << endl;
    cout << so.longestPalindrome2("cbbd") << endl;
    cout << so.longestPalindrome2("babadada") << endl;
    return 0;
}
