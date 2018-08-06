#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class SortCollection {
  public:
    // 1.冒泡排序：O(n^2) 稳定
    vector<int> bubble_sort(vector<int> nums) {
        int n = nums.size();
        for (int i = 0; i < n-1; i++)
            for (int j = 0; j < n-1-i; j++)
                if (nums[j] > nums[j+1])
                    swap(nums[j], nums[j+1]);
        return nums;
    }

    // 2.选择排序: O(n^2) 不稳定
    vector<int> select_sort(vector<int> nums) {
        int n = nums.size();
        for (int i = 0; i < n-1; i++) {
            int minIdx = i;
            for (int j = i+1; j < n; j++)
                if (nums[j] < nums[minIdx])
                    minIdx = j;
            swap(nums[i], nums[minIdx]);
        }
        return nums;
    }

    // 3.插入排序：O(n^2) 稳定
    vector<int> insert_sort(vector<int> nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int k = nums[i];
            int j = i - 1;
            while (j >= 0 && nums[j] > k)
                nums[j+1] = nums[j--];
            nums[j+1] = k;
        }
        return nums;
    }

    // 4.希尔排序：O(n^{3/2}) 不稳定
    vector<int> shell_sort(vector<int> nums) {
        int n = nums.size();
        int step = 0;
        while (step < n/3)
            step = step * 3 + 1;
        for (; step >= 1; step /= 3) { // 动态步长
            for (int i = step; i < n; i++) { // 插入排序
                int k = nums[i];
                int j = i - step;
                while (j >= 0 && nums[j] > k) {
                    nums[j+step] = nums[j];
                    j -= step;
                }
                nums[j+step] = k;
            }
        }
        return nums;
    }    

    // 5.归并排序：O(nlogn) 需要额外空间开销 稳定
    vector<int> merge_sort(vector<int> nums) {
        int n = nums.size();
        if (n < 2)
            return nums;
        int mid = n / 2;
        _merge_sort(nums.begin(), nums.end());
        return nums;
    }
    void _merge_sort(vector<int>::iterator begin, vector<int>::iterator end) {
        int n = end - begin;
        if (n < 2)
            return;
        auto mid = begin + n / 2;
        _merge_sort(begin, mid);
        _merge_sort(mid, end);
        _merge(begin, mid, end);
    }
    void _merge(vector<int>::iterator begin, vector<int>::iterator mid, vector<int>::iterator end) {
        vector<int> temp(end-begin);
        vector<int>::iterator it1(begin), it2(mid), it(temp.begin());
        while (it1 < mid || it2 < end) {
            if (it2 == end || (it1 < mid && it2 < end && *it1 < *it2))
                *(it++) = *(it1++);
            else
                *(it++) = *(it2++);
        }
        it = temp.begin();
        while (it < temp.end())
            *(begin++) = *(it++);
    }

    // 6.快速排序: O(nlogn) 不稳定
    vector<int> quick_sort(vector<int> nums) {
        _quick_sort(nums.begin(), nums.end());
        return nums;
    }
    void _quick_sort(vector<int>::iterator begin, vector<int>::iterator end) {
        if (end - begin < 2) return;
        vector<int>::iterator left(begin), right(end-1);
        int key = *left;
        while (left < right) {
            while (left < right && *right >= key) right--;
            *left = *right;
            while (left < right && *left <= key) left++;
            *right = *left;
        }
        *left = key;
        _quick_sort(begin, left);
        _quick_sort(left+1, end);
    }

    // 7.堆排序：O(nlogn) 不稳定
    vector<int> heap_sort(vector<int> nums) {
        int n = nums.size();
        // build mam heap
        for (int i = n/2-1; i >= 0; i--)
            heapify(nums, i, n);
        for (int i = n-1; i > 0; i--) {
            swap(nums[i], nums[0]);
            heapify(nums, 0, i);
        }
        return nums;
    }
    void heapify(vector<int>& nums, int s, int e) {    // 堆调整
        int mam = s;
        int left = 2 * s + 1;
        if (left < e && nums[left] > nums[mam])
            mam = left;
        int right = left + 1;
        if (right < e && nums[right] > nums[mam])
            mam = right;
        if (mam != s) {
            swap(nums[s], nums[mam]);
            heapify(nums, mam, e);
        }
    }

    // 8.计数排序：O(n+m) 空间复杂度 O(m) 稳定
    vector<int> count_sort(vector<int> nums, int maxValue=100) {
        vector<int> bucket(maxValue+1, 0);
        int n = nums.size();
        for (int i = 0; i < n; i++)
            bucket[nums[i]]++;
        for (int i = 0, j = 0; j < bucket.size(); j++) {
            while (bucket[j]-- > 0)
                nums[i++] = j;
        }
        return nums;
    }

    // 9.桶排序：O(n+m) 空间复杂度 O(m) 稳定
    vector<int> bucket_sort(vector<int> nums, int bucket_size=5) {
        int n = nums.size();
        if (n < 2)
            return nums;
        // 求最大最小值
        int mim = nums[0], mam = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < mim) mim = nums[i];
            else if (nums[i] > mam) mam = nums[i];
        }
        // 初始化桶
        int bucket_cnt = (mam - mim) / bucket_size;
        vector<vector<int>> buckets(bucket_cnt);
        // 映射到桶中
        for (int i : nums)
            buckets[(i-mim)/bucket_cnt].push_back(i);
        // 桶内插入排序
        int k = 0;
        for (auto& bucket : buckets) {
            bucket = insert_sort(bucket);
            for (int i : bucket)
                nums[k++] = i;
        }
        return nums;
    }

    // 10.基数排序：O(n*k) O(n) 稳定
    vector<int> radix_sort(vector<int> nums, int mod=10) {
        int mam = INT_MIN;
        for (int num : nums)
            if (num > mam) mam = num;
        int bit = get_bit(mam, mod);
        int n = nums.size();
        vector<queue<int>> counters(mod);
        int radix = 1;
        for (int i = 0; i < bit; i++) {
            for (int num : nums)
                counters[(num/radix)%mod].push(num);
            int k = 0;
            for (auto & counter : counters)
                while (!counter.empty()) {
                    nums[k++] = counter.front();
                    counter.pop();
                }
            radix *= mod;
        }
        return nums;
    }
    int get_bit(int num, int mod) {
        int n = 0;
        while (num > 0) {
            num /= mod;
            n++;
        }
        return n;
    }

    void print(string name, vector<int> nums) {
        cout << name << ": ";
        for (int num : nums)
            cout << num << " ";
        cout << endl;
    }

    void test_all() {
        vector<int> nums = {23, 44, 66, 76, 98, 11, 3, 9, 7};
        print("冒泡", bubble_sort(nums));
        print("选择", select_sort(nums));
        print("插入", insert_sort(nums));
        print("希尔", shell_sort(nums));
        print("归并", merge_sort(nums));
        print("快排", quick_sort(nums));
        print("堆排", heap_sort(nums));
        print("计数", count_sort(nums));
        print("桶排", bucket_sort(nums));
        print("基数", radix_sort(nums));
    }
};

int main() {
    SortCollection sc;
    sc.test_all();
    return 0;
}