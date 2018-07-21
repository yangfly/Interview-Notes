#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const auto ______ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


/** 背景：
 * 从一堆数中求其前k大或者前k小的数。最有效的是BFPRT算法，基于快排和二分查找。
 **/
class Solution {
public:
    // 基于排序：先排序。
    // 时间复杂度：O(nlogn)
    int stl_topk(vector<int>& nums, int k)
    {   
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }

    // 时间复杂度：O(nlogn)
    int naive_topk(vector<int>& nums, int k)
    {
        Solution::qsort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }

    static void qsort(vector<int>::iterator start, vector<int>::iterator end)
    {
        if (end - start < 2) return;
        vector<int>::iterator left(start), right(end);
        int temp = *left;
        while (left < right) {
            while (left < right) {
                if (*left > *right) {
                    *left = *right;
                    break;
                }
                right--;
            }
            while (left < right) {
                if (*left > *right) {
                    *right = *left;
                    break;
                }
                left++;
            }
        }
        qsort(start, left - 1);
        qsort(right + 1, end);
    }

    // BFPRT算法：平均O(logn),最坏O(n)
    // https://subetter.com/articles/2018/03/bfprt-algorithm.html
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


