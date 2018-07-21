#include <iostream>
#include <vector>
using namespace std;

static const auto ______ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    // 暴力匹配
    int violent_search(string& S, string& P)
    {
        int s_len = S.length();
        int p_len = P.length();
        int i = 0, j = 0;
        while (i < s_len && j < p_len)
        {
            if (S[i] == P[j]) { // match
                i++;
                j++;
            }
            else { // mismatch
                i = i - j + 1;
                j = 0;
            }
        }
        if (j == p_len)  // successful
            return i - j;
        else
            -1;
    }

    // KMP: 通过预先计算模式串P的内部匹配信息。
    // 在匹配失败时，最大地移动模式串，从而减少匹配的次数。
    int kmp(string& S, string& P, vector<int> next)
    {
        int s_len = S.length();
        int p_len = P.length();
        int i = 0, j = 0;
        while (i < s_len && j < p_len)
        {
            if (j == -1 || S[i] == P[j]) { // match
                i++;
                j++;
            }
            else { // mismatch
                j = next[j];
            }
        }
        if (j == p_len)  // successful
            return i - j;
        else
            return -1;
    }

    // KMP count: 采用kmp算法统计S中P匹配的次数
    int kmp_count(string& S, string& P, vector<int> next)
    {
        int s_len = S.length();
        int p_len = P.length();
        int i = 0, j = 0, cnt = 0;
        while (i < s_len)
        {
            while (i < s_len && j < p_len)
            {
                if (j == -1 || S[i] == P[j]) {
                    i++;
                    j++;
                }
                else
                    j = next[j];
            }
            if (j == p_len) {
                i -= j - 1;
                j = 0;
                cnt++;
            }
        }
        return cnt;
    }

    // next数组: next[0] = -1
    // next[i] = 最长相同“真”前后缀长度 (不包括i字符)
    // 求解思路：递推，已知next[0...i-1]，求next[i];
    vector<int> naive_next(string& P)
    {
        int p_len = P.length();
        vector<int> next(p_len);
        if (p_len > 0)
        {
            // 已经匹配的真前后串长度
            int j = next[0] = -1; // 初始约定为-1
            for (int i= 1; i < p_len; i++)
            {
                while (j >= 0 && P[i-1] != P[j])
                    j = next[j];
                next[i] = ++j;
            }
        }
        return next;
    }

    // next优化：
    // 调用next的场景是mismatch：即下一个字符不应该匹配
    // 如果在P中下一个匹配，说明必定失败，递归调整一步。
    // *不需要递归调整，因为递归一步的结果也是递归调整过的。
    vector<int> improve_next(string& P)
    {
        int p_len = P.length();
        vector<int> next(p_len);
        if (p_len > 0)
        {
            // 已经匹配的真前后串长度
            int j = next[0] = -1; // 初始约定为-1
            for (int i = 1; i < p_len; i++)
            {
                while (j >= 0 && P[i-1] != P[j])
                    j = next[j];
                j++;
                if (P[i] != P[j]) next[i] = j; // 下一个mismatch，OK
                else next[i] = next[j]; // 下一个match，调整。
            }
        }
        return next;
    }

    void print(vector<int> next)
    {
        for (int n : next)
            cout << n << " ";
        cout << endl;
    }
};

int main() {
    Solution so;
    string P = "abcdaabcab";
    so.print(so.naive_next(P));
    so.print(so.improve_next(P));
    string s = "bbc abcdab abcdabcdabde";
    string p = "abcdabd";
    cout << so.kmp(s, p, so.naive_next(p)) << endl;
    cout << so.kmp(s, p, so.improve_next(p)) << endl;
    s = "abaabcacabaabcacabaabcacabaabcacabaabcac";
    p = "ab";
    cout << so.kmp_count(s, p, so.improve_next(p)) << endl;
    return 0;
}
