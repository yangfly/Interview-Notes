/*
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (38.80%)
 * Total Accepted:    150.5K
 * Total Submissions: 387.7K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 * Example:
 * 
 * 
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 */

// unordered_map<int, bool>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> used;
        for (int num : nums) used[num] = false;
        int longest = 0;
        for (int num : nums) {
            if (used[num]) continue;
            int length = 1;
            used[num] = true;
            for (int i = num - 1; used.find(i) != used.end(); i--) {
                used[i] = true;
                length++;
            }
            for (int i = num + 1; used.find(i) != used.end(); i++) {
                used[i] = true;
                length++;
            }
            longest = max(longest, length);
        }
        return longest;
    }
};

// unorder_set<int> // 去重
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        for (int num : nums)
            uset.insert(num);
        int longest = 0;
        for (int num : uset) {
            if (uset.find(num - 1) == uset.end()) {
                int cnt = 1;
                while (uset.find(num + 1) != uset.end()) {
                    num++;
                    cnt++;
                }
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};

/// unordered_map<int,int>: length
// ** length only need to be ordered by both boundaries.
// neither i+1 nor i-1 has been seen: m[i]=1;
// both i+1 and i-1 have been seen: extend m[i+m[i+1]] and m[i-m[i-1]];
// only i+1 has been seen: extend m[i+m[i+1]] and m[i] to each other;
// only i-1 has been seen: extend m[i-m[i-1]] and m[i] to each other.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        int longest = 0;
        for (int num : nums) {
            if (map[num]) continue;
            int sum = map[num-1] + map[num+1] + 1;
            map[num] = sum;
            map[num-map[num-1]] = sum;
            map[num+map[num+1]] = sum;
            longest = max(longest, sum);
        }
        return longest;
    }
};


// 纯A过：O(nlogn)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int length = 1, longest = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1)
                length++;
            else if (nums[i] > nums[i - 1] + 1) {
                longest = max(longest, length);
                length = 1;
            }
        }
        return max(longest, length);
    }
};
