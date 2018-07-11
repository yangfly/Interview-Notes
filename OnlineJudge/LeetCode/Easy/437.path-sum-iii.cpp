/*
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Easy (40.05%)
 * Total Accepted:    52.2K
 * Total Submissions: 130.2K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * You are given a binary tree in which each node contains an integer value.
 * 
 * Find the number of paths that sum to a given value.
 * 
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards
 * (traveling only from parent nodes to child nodes).
 * 
 * The tree has no more than 1,000 nodes and the values are in the range
 * -1,000,000 to 1,000,000.
 * 
 * Example:
 * 
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 * 
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 * 
 * Return 3. The paths that sum to 8 are:
 * 
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "common.h"

// My Solution 28ms
static auto _________ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
// 暴力递归，简单直观但速度慢。O(n^2)
class Solution {
private:
    int rootStart(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;
        int r = sum - root->val;
        // r == 0 时不结束搜索。
        return (r == 0) + rootStart(root->left, r) + rootStart(root->right, r);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;
        return rootStart(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};

// A Quicker Solution 16ms
// 缓存递归 O(n)
// Consider a path: R -> A -> B -> C
// We first compute: sum(R) and sum(RABC)
// the we need compute: sum(ABC) = sum(RABC) - R(R)
// rather than: sum(ABC) = A + B + C
// so we can cache sumfromRoot all the parents alongside.
// we need to search and count SFR with given rootSum
// so we create a HashMap: rootSum -> count
// https://leetcode.com/problems/path-sum-iii/discuss/91892/Python-solution-with-detailed-explanation
class Solution {
private:
    unordered_map<int, int> map;    // rootSum -> count
    int count, target;
    void dfs(TreeNode* root, int so_far) {
        if (root != NULL) {
            so_far += root->val;  // sum from root
            if (map.count(so_far - target))
                count += map[so_far - target];

            if (map.count(so_far))
                map[so_far]++;  // add root
            else
                map[so_far] = 1;

            dfs(root->left, so_far);
            dfs(root->right, so_far);
            
            map[so_far]--;     // erase root 
            so_far -= root->val;
        }
    }

public:
    int pathSum(TreeNode* root, int sum) {
        count = 0, target = sum;
        map[0] = 1; // for case: SFM = target( + 0)
        dfs(root, 0);
        return count;
    }
};