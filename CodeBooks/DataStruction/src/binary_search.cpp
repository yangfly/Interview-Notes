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
    // 返回第一个找到的 target 所在索引。
    int bsearch(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        if (nums[left] == target)
            return left;
        else
            return -1;
    }

    // 第一个大于等于 target 的数所在索引。
    int left_bsearch(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        if (nums[left] >= target)
            return left;
        else
            return -1;
    }

    // 最后一个小于等于 target 的数所在索引。
    int right_bsearch(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2; // right side
            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid;
        }
        if (nums[right] <= target)
            return right;
        else
            return -1;
    }
};

int main() {
    Solution so;
    vector<int> nums = {0,0,0,1,1,1,3,3,3,3,4,4,4,6,7,7,7};
    int target = 3;
    cout << so.bsearch(nums, target) << endl;
    cout << so.left_bsearch(nums, target) << endl;
    cout << so.right_bsearch(nums, target) << endl;
}
