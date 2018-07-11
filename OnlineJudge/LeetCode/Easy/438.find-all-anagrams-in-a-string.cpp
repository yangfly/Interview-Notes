/*
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Easy (33.92%)
 * Total Accepted:    58K
 * Total Submissions: 171.1K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given a string s and a non-empty string p, find all the start indices of p's
 * anagrams in s.
 * 
 * Strings consists of lowercase English letters only and the length of both
 * strings s and p will not be larger than 20,100.
 * 
 * The order of output does not matter.
 * 
 * Example 1:
 * 
 * Input:
 * s: "cbaebabacd" p: "abc"
 * 
 * Output:
 * [0, 6]
 * 
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of
 * "abc".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s: "abab" p: "ab"
 * 
 * Output:
 * [0, 1, 2]
 * 
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 * 
 * 
 */
#include "common.h"

// My Solution 73ms
static auto _________ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();
// 采用字频表保存和对比窗口状态
class Solution {
public:
	using CharMap = unordered_map<char, size_t>;

	bool equal(CharMap& pmap, CharMap& tmap) {
		for (auto iter = pmap.begin(); iter != pmap.end(); ++iter) {
			if (iter->second != tmap[iter->first])
				return false;
		}
		return true;
	}

	void update(CharMap& tmap, char front, char next) {
		auto iter = tmap.find(front);
		if (iter != end(tmap))
			tmap[front]--;
		iter = tmap.find(next);
		if (iter != end(tmap))
			tmap[next]++;
	}

	vector<int> findAnagrams(string s, string p) {
		vector<int> result;
		size_t m = p.size();
		size_t n = s.size();

		if (m <= n) {
			CharMap pmap, tmap;
			for (size_t i = 0; i < m; i++) {
				auto iter = pmap.find(p[i]);
				if (iter != end(pmap))
					iter->second++;
				else {
					pmap.emplace(p[i], 1);
					tmap.emplace(p[i], 0);
				}
			}
			for (size_t i = 0; i < m; i++) {
				tmap[s[i]]++;
			}

			for (size_t i = 0; i < n - m; i++) {
				if (equal(pmap, tmap))
					result.push_back(i);
				update(tmap, s[i], s[i+m]);
			}
			if (equal(pmap, tmap))
				result.push_back(n - m);
		}

		return result;
	}
};

// A Simpler Solution 36ms
// 因为字符只有26个(有限),直接使用数组做字频表
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector <int> sv (26,0);
        vector <int> pv (26,0);
        vector <int> result;
        
        if (p.length() > s.length()) 
            return result;
        
        for (int i = 0; i < p.length(); i++) {
            pv[p[i]-'a'] += 1;
            sv[s[i]-'a'] += 1;
        }
        
        if (sv == pv) {
            result.push_back(0);
        }
        
        for (int i = p.length(); i < s.length(); i++) {
            sv[s[i-p.length()]-'a'] -= 1;
            sv[s[i]-'a'] += 1;
            if (sv == pv) {
                result.push_back(i-p.length()+1);
            }
        }
    
        return result;
    }
};