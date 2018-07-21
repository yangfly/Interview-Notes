#include <iostream>
#include <vector>
using namespace std;

static const auto ______ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


/** 背景：
 * 给定一个字符串，求出其最长回文子串。例如
 *  1. s="abcd"，最长回文长度为1；
 *  2. s="ababa"，最长回文长度为5；
 *  3. s="abccb"，最长回文长度为4，即"bccb"。
 **/
class Solution {
public:
    // 纯暴力：便历字串前后索引，判断是否回文。
    // 时间复杂度：O(n^3)
    int pure_search(string& s)
    {
        if (s.empty()) return 0;
        int len = s.length();
        int mam = 1;
        for (int i = 0; i <= len - 2; i++)
            for (int j = i + 2; j <= len; j++)
                if (isPalindrome(s, i, j))
                    mam = max(mam, j - i);
        return mam;
    }

    bool isPalindrome(string& s, int start, int end)
    {
        while (start < --end && s[start++] == s[end])
        return start <= end;
    }

    // 暴力: 遍历字符串，以每个字符为中心向两边查找。
    // 时间复杂度：O(n^2)
    int bi_search(string& s)
    {
        if (s.empty()) return 0;
        int len = s.length();
        int mam = 1;
        for (int i = 1; i < len - 1; i++) {
            mam = max(mam, biPalindrome(s, i, i));  // 单核回文
            mam = max(mam, biPalindrome(s, i, i+1)); // 双核回文
        }
        return mam;
    }

    int biPalindrome(string s, int left, int right)
    {
        while (left >= 0 && right < s.length())
        {
            if (s[left] == s[right]) {
                left--;
                right++;
            }
            else break;
        }
        return right - left - 1;   
    }

    // 马拉车算法：O(n)
    // 第一步，在各字符间填充一个额外字符如'#'，将奇回文和偶回文统一为奇回文。
    // 动规计算扩充串的最长回文半径p，则原串的最长回文长度p[i]-1的最大值。
    int manacher(string& s, bool verbose=false)
    {
        string s_new(s.length() * 2 + 2, '#');
        vector<int> p(s_new.length());
        s_new[0] = '$';
        for (int i = 0; i < s.length(); i++)
            s_new[2 * i + 2] = s[i];
        int mam = 0;
        int id, mx = 0; // 回文中心及其最长回文右边界
        for (int i = 1; i < s_new.length(); i++)
        {
            if (i < mx)
                p[i] = min(p[2 * id - i], mx - i);
            else
                p[i] = 1;
            // 不需要判断边界,因为具有唯一左右边界'$'和'\0'
            while (s_new[i - p[i]] == s_new[i + p[i]])
                p[i]++;
            // i每进一步，尝试推进mx
            if (mx < i + p[i])
            {
                id = i;
                mx = i + p[i];
            }
            mam = max(mam, p[i] - 1);
        }
        if (verbose) {
            print(s_new);
            print(p);
        }
        return mam;
    }

    void print(vector<int> next)
    {
        for (int n : next)
            cout << n << " ";
        cout << endl;
    }

    void print(string& str)
    {
        for (char c : str)
            cout << c << " ";
        cout << endl;
    }
};

int main() {
    Solution so;
    vector<string> strs = {"abcd", "ababa", "abccb"};
    for (string& s : strs)
        cout << so.pure_search(s) << " "
             << so.bi_search(s)   << " "
             << so.manacher(s)    << endl;
    so.manacher(strs[2], true);
    return 0;
}


