#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    vector<int> get_next(const string T) {
        int n = T.length();
        vector<int> next(n);
        if (n > 0) {
            int j = next[0] = -1;
            for (int i = 1; i < n; i++) {
                while (j >= 0 && T[j] != T[i-1])
                    j = next[j];
                next[i] = ++j;
            }
        }
        return next;
    }

    vector<int> get_nextval(const string T) {
        int n = T.length();
        vector<int> nextval(n);
        if (n > 0) {
            int j = nextval[0] = -1;
            for (int i = 1; i < n; i++) {
                while (j >= 0 && T[j] != T[i-1])
                    j = nextval[j];
                if (T[++j] == T[i])
                    nextval[i] = nextval[j];
                else
                    nextval[i] = j;
            }
        }
        return nextval;
    }

    int KMP(const string S, const string T, const vector<int> next) {
        int n = S.length();
        int m = T.length();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (j == -1 || S[i] == T[j]) {
                i++;
                j++;
            }
            else // mismatch
                j = next[j];
        }
        if (j == m)
            return i - j; // success
        else
            return -1; // failure
    }

    int KMP_count(const string S, const string T, const vector<int> next) {
        int n = S.length();
        int m = T.length();
        int i = 0, j = 0;
        int cnt = 0;
        while (i < n) {
            if (j == -1 || S[i] == T[j]) {
                i++;
                j++;
            }
            else
                j = next[j];
            if (j == m) {
                i -= j - 1;
                j = 0;
                cnt++;
            }
        }
        return cnt;
    }

    void print(const vector<int> next) {
        for (int i : next)
            cout << i+1 << " ";
        cout << endl;
    }
};

int main() {
    Solution so;
    so.print(so.get_next("ababaaaba"));
    so.print(so.get_nextval("ababaaaba"));
    so.print(so.get_next("aaaaaaaab"));
    so.print(so.get_nextval("aaaaaaaab"));

    string s = "bbc abcdab abcdabcdabde";
    string t = "abcdabd";
    cout << so.KMP(s, t, so.get_next(t)) << endl;
    cout << so.KMP(s, t, so.get_nextval(t)) << endl;

    s = "abaabcacabaabcacabaabcacabaabcacabaabcac";
    t = "ab";
    cout << so.KMP_count(s, t, so.get_next(t)) << endl;
    cout << so.KMP_count(s, t, so.get_nextval(t)) << endl;
    return 0;
}