/*
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (41.10%)
 * Total Accepted:    181.6K
 * Total Submissions: 441.9K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */

static const auto ________ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        vector<int> head;
        head.push_back(1);
        for (int i = 0; i < numRows; i++)
            triangle.push_back(head);
        for (int i = 1; i < numRows; i++) {
            triangle[i].push_back(1);
            for (int j = i + 1; j < numRows; j++)
                triangle[j].push_back(triangle[j-1][i-1] + triangle[j-1][i]);
        }
        return triangle;
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        vector<int> head;
        head.push_back(1);
        if (numRows > 0)
            triangle.push_back(head);
        for (int i = 1; i < numRows; i++) {
            triangle.push_back(head);
            for (int j = 1; j < i; j++)
                triangle[i].push_back(triangle[i-1][j-1] + triangle[i-1][j]);
            triangle[i].push_back(1);
        }
        return triangle;
    }
};

