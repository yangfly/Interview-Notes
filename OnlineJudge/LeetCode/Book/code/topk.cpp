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
    int stl_topk(vector<int> nums, int k)
    {   
        sort(nums.begin(), nums.end());
        return nums[k - 1];
    }

    // 时间复杂度：O(nlogn)
    int naive_topk(vector<int> nums, int k)
    {
        Solution::qsort(nums.begin(), nums.end());
        return nums[k - 1];
    }

    static void qsort(vector<int>::iterator start, vector<int>::iterator end)
    {
        if (end - start < 2) return;
        vector<int>::iterator left(start), right(end-1);
        int key = *left;
        while (left < right) {
            while (left < right && *right >= key) right--;
            *left = *right;
            while (left < right && *left <= key) left++;
            *right = *left;
        }
        *left = key;
        qsort(start, left);
        qsort(right + 1, end);
    }

    int insert_sort(vector<int>& nums, int start, int end)
    {
        for (int i = start + 1; i < end; i++)
        {
            int j, temp = nums[i];
            for (j = i; j > start && nums[j-1] > temp; j--)
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
        for (int i = start; i + 5 <= end; i += 5)
        {
            int m = insert_sort(nums, i, i + 5);
            swap(nums[index++], nums[m]);
        }
        return BFPRT(nums, start, index, ((index - start) >> 1) + 1);
    }

    int partition(vector<int>& nums, int start, int end, int pivot_index)
    {
        int key = nums[pivot_index];
        nums[pivot_index] = nums[start]; // move pivot to start
        end--; // make sure nums[end] valid
        while (start < end) 
        {
            while (start < end && nums[end] >= key) end--;
            nums[start] = nums[end];
            while (start < end && nums[start] <= key) start++;
            nums[end] = nums[start];
        }
        nums[start] = key;
        return start;
    }

    // BFPRT算法：中位数的中位数。平均O(logn),最坏O(n)
    // 1.选择主元：分(n/5)组，插入排序求中位数。递归求中位数的中位数。
    // 2.以中位数为分界点，类似于qsort中partition
    // 3.判断主元的位置与k的大小关系，选择对左边或者右边递归。
    int BFPRT(vector<int> nums, int start, int end, int k)
    {
        int pivot_index = get_pivot_index(nums, start, end);
        int mid = partition(nums, start, end, pivot_index);
        int rank = mid - start + 1;
        if (rank == k)
            return mid;
        else if (rank > k)
            return BFPRT(nums, start, mid, k);
        else
            return BFPRT(nums, mid + 1, end, k-rank);
    }

    // binary search
    // 最好O(logn),最坏O(n)
    int bis_topk(vector<int> nums, int k)
    {
        int start = 0, end = nums.size();
        k--;
        while (start < end) {
            int index = partition(nums, start, end);
            if (index == k)
                return nums[index];
            else if (index > k)
                end = index;
            else
                start = index + 1;
        }
        return -1;
    }

    int partition(vector<int>& nums, int start, int end)
    {
        int key = nums[start];
        end--;
        while (start < end) {
            while (start < end && nums[end] >= key) end--;
            nums[start] = nums[end];
            while (start < end && nums[start] <= key) start++;
            nums[end] = nums[start]; 
        }
        nums[start] = key;
        return start;
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
    vector<int> nums = {11,9,10,1,13,8,15,0,16,2,17,5,14,3,6,18,12,7,19,4};
    cout << so.naive_topk(nums, 8) << endl;
    cout << so.stl_topk(nums, 8) << endl;
    cout << so.BFPRT(nums, 0, nums.size(), 8) << endl;
    cout << so.bis_topk(nums, 8) << endl;
    so.qsort(nums.begin(), nums.end());
    so.print(nums);
    return 0;
}


