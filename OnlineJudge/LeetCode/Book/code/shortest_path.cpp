#include <iostream>
#include <vector>
#include <limits>
using namespace std;

static const auto ______ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

/** 背景：
 * 最短路径问题。
 **/

class Solution {
public:
    // ************* 单源点最短路径 *************

    // Dijkstra算法 贪心 时间复杂度O(n^2)
    // 内存：mat结点距离临接矩阵，dist最短路程，visited结束标记
    //      * path记录最短路径
    // 缺点：效率低，空间占用大。
    void dijkstra(int n, int s, vector<vector<int>> & edges) 
    {
        // 使用邻接矩阵存储
        vector<vector<int>> mat(n, vector<int>(n, INT_MAX));
        for (auto edge : edges)
            mat[edge[0]][edge[1]] = edge[2];
        vector<int> dist(n); // 源点到顶点i的最短路程
        for (int i = 0; i < n; i++)
            dist[i] = mat[s][i];
        vector<bool> visited(n, false); // 求解结束标记数组
        visited[s] = true; // 源点
        vector<int> path(n, s); // 记录最短路径
        for (int i = 1; i < n; i++)
        { // 找到源点到i个点的最短路径
            // 标记最近的点
            int min_index = INT_MAX;
            for (int j = 0; j < n; j++)
                if (!visited[j] && dist[j] < dist[min_index])
                    min_index = j;
            visited[min_index] = true;
            // 更新dist数组
            for (int j = 0; j < n; j++) {
                if (!visited[j] && mat[min_index][j] < INT_MAX // 确保边有效
                    && mat[min_index][j] + dist[min_index] < dist[j])
                {
                    dist[j] = mat[min_index][j] + dist[min_index];
                    path[j] = min_index; // 上一个点
                }
            }
        }
    }

    // 纯暴力：便历字串前后索引，判断是否回文。
    // 时间复杂度：O(n^3)
    int pure_search(string& s)
    {   
        // Todo
        return 0;
    }

    // 暴力: 遍历字符串，以每个字符为中心向两边查找。
    // 时间复杂度：O(n^2)
    int bi_search(string& s)
    {
        // Todo
        return 0;
    }

    // 马拉车算法：O(n)
    // 第一步，在各字符间填充一个额外字符如'#'，将奇回文和偶回文统一为奇回文。
    // 动规计算扩充串的最长回文半径p，则原串的最长回文长度p[i]-1的最大值。
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


