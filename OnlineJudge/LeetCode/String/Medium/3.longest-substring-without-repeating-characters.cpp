/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (24.84%)
 * Total Accepted:    527.8K
 * Total Submissions: 2.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 */

// 循环查找：O(n^2)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        size_t length = 0;
        string ss;
        for (char c : s) {
            size_t n = ss.find(c);
            if (n != string::npos) {
                length = max(length, ss.size());
                ss = ss.substr(n + 1);
            }
            ss.push_back(c);
        }
        length = max(length, ss.size());
        return length;
    }
};

// unordered_map<char, int>: 保存最近一次出现的位置
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int i = -1, len = 0;
        for (int j = 0; j < s.length(); j++) {
            auto it = map.find(s[j]);
            // 这里 0 不能作为存在条件
            if (it != map.end()) {
                i = max(i, it->second);
            }
            map[s[j]] = j;
            len = max(len, j - i);
        }
        return len;
    }
};

// 因为 ASCII 只有255个，所以可以用数组代替
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(255, -1);
        int len = 0, i = -1, tmp;
        for (int j = 0; j < s.length(); j++) {
            i = max(tmp, map[s[j]]);
            map[s[j]] = j;
            len = max(len, j - i);
        }
        return len;
    }
};
