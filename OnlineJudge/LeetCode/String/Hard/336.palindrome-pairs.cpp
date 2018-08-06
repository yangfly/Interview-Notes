/*
 * [336] Palindrome Pairs
 *
 * https://leetcode.com/problems/palindrome-pairs/description/
 *
 * algorithms
 * Hard (27.57%)
 * Total Accepted:    42.8K
 * Total Submissions: 155.3K
 * Testcase Example:  '["abcd","dcba","lls","s","sssll"]'
 *
 * Given a list of unique words, find all pairs of distinct indices (i, j) in
 * the given list, so that the concatenation of the two words, i.e. words[i] +
 * words[j] is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: ["abcd","dcba","lls","s","sssll"]
 * Output: [[0,1],[1,0],[3,2],[2,4]] 
 * Explanation: The palindromes are
 * ["dcbaabcd","abcddcba","slls","llssssll"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["bat","tab","cat"]
 * Output: [[0,1],[1,0]] 
 * Explanation: The palindromes are ["battab","tabbat"]
 * 
 * 
 * 
 * 
 */
// 时间复杂度 O(n^2*k), 超时
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> rst;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                if (palindrome(words[i] + words[j]))
                    rst.emplace_back(vector<int>({i, j}));
                if (palindrome(words[j] + words[i]))
                    rst.emplace_back(vector<int>({j, i}));
            }
        return rst;
    }

    bool palindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r && s[l] == s[r]) {
            l++;
            r--;
        }
        return l >= r;
    }
};
// 时间复杂度 O(n*k^2), 超时
class Solution {
    bool isPalindrome(const string & s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
  public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> res;
        unordered_map<string, int> str2idx;
        for (int i = 0; i < n; i++)
            str2idx[words[i]] = i;
        for (int i = 0; i < n; i++) {
            string& word = words[i];
            for (int j = 0; j <= word.length(); j++) {
                string str1 = word.substr(0, j);
                string str2 = word.substr(j);
                if (isPalindrome(str1)) {
                    string tmp(str2.rbegin(), str2.rend());
                    if (str2idx.count(tmp) && str2idx[tmp] != i)
                        res.push_back({str2idx[tmp], i});
                }
                if (isPalindrome(str2)) {
                    string tmp(str1.rbegin(), str1.rend());
                    // 特别注意两个字符串对等长的情况。
                    if (str2idx.count(tmp) && str2idx[tmp] != i && !str2.empty())
                        res.push_back({i, str2idx[tmp]});
                }
            }
        }
        return res;
    }
};
