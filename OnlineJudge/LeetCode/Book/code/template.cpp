#include <iostream>
#include <vector>
using namespace std;

static const auto ______ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


/** 背景：
 * !Todo
 **/
class Solution {
public:
    // 纯暴力：便历字串前后索引，判断是否回文。
    // 时间复杂度：O(n^3)
    int pure_search(string& s)
    {   
        // Todo
        return 0;
    }

    // 暴力: 遍历字符串，以每个字符为中心向两边查找。
    // 时间复杂度：O(n^2)
    int bi_search(string& s)
    {
        // Todo
        return 0;
    }

    // 马拉车算法：O(n)
    // 第一步，在各字符间填充一个额外字符如'#'，将奇回文和偶回文统一为奇回文。
    // 动规计算扩充串的最长回文半径p，则原串的最长回文长度p[i]-1的最大值。
    int manacher(string& s, bool verbose=false)
    {
        // Todo
        return 0;
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


