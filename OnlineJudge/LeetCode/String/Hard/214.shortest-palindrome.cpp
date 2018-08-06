/*
 * [214] Shortest Palindrome
 *
 * https://leetcode.com/problems/shortest-palindrome/description/
 *
 * algorithms
 * Hard (25.62%)
 * Total Accepted:    57.8K
 * Total Submissions: 225.7K
 * Testcase Example:  '"aacecaaa"'
 *
 * Given a string s, you are allowed to convert it to a palindrome by adding
 * characters in front of it. Find and return the shortest palindrome you can
 * find by performing this transformation.
 * 
 * Example 1:
 * 
 * 
 * Input: "aacecaaa"
 * Output: "aaacecaaa"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "abcd"
 * Output: "dcbabcd"
 * 
 */
// class Solution {
// public:
//     string shortestPalindrome(string s) {
//         int n = s.length()
//     }
// };

class Solution {
public:
    string shortestPalindrome(string s) {
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
            if (i-P[i] < 2) // start from very begining
                mam = max(mam, P[i]);
        }
        string rst;
        for (int i = 0; i < n-(mam-1); i++)
            rst.push_back(s[n-i-1]);
        return rst + s;
    }
};
