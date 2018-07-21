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

    // BFPRT算法：中位数的中位数。平均O(logn),最坏O(n)
    // 1.选择主元：分(n/5)组，插入排序求中位数。递归求中位数的中位数。
    // 2.以中位数为分界点，类似于qsort中partition
    // 3.判断主元的位置与k的大小关系，选择对左边或者右边递归。
    int manacher(string& s, bool verbose=false)
    {
        // Todo
        return 0;
    }

    int insert_sort(vector<int>& nums, int start, int end)
    {
        for (int i = start + 1; i < end; i++)
        {
            int j, temp = nums[i];
            for (j = i; j > 0 && nums[j-1] > temp; j--)
                nums[j] = nums[j-1];
            nums[j] = temp;
        }
        return start + ((end - start) >> 1);
    }

    int get_pivot_index(vector<int>& nums, int start, int end)
    {
        if (end - start < 5)
            return insert_sort(nums, start, end);
        // 每5个为一组，求出中位数，并将这些中位数全部交换到数组左边
        int index = start;
        for (int i = start; i + 5 <= end; i++)
        {
            int m = insert_sort(nums, i, i + 4);
            swap(nums[index++], nums[m]);
        }
        return BFPRT(nums, start, end, (index - start) >> 1);
    }

    int partition(vector<int>& nums, int start, int end, int pivot_index)
    {
        swap(nums[pivot_index], nums[end]);
        int mid = start;
        for (int i = start; i < end; i++)
            if (nums[i] < nums[end])
                swap(nums[i], nums[mid]);
        swap(nums[mid], nums[end]);
        return mid;
    }

    int BFPRT(vector<int>& nums, int start, int end, int k)
    {
        int pivot_index = get_pivot_index(nums, start, end);
        int mid = partition(nums, start, end, pivot_index);
        int rank = mid - start + 1;
        if (rank == k)
            return mid;
        else if (rank > k)
            return BFPRT(nums, start, mid, k);
        else
            return BFPRT(nums, mid+1, end, k-rank);
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


