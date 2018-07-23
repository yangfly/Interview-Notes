#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
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
    struct Edge {
        int u, v, w;
        Edge(int u, int v, int w) :
            u(u), v(v), w(w) {}
    };

    // ************* 单源点最短路径 *************

    // Dijkstra算法 贪心 时间复杂度O(n^2)
    // 内存：mat结点距离临接矩阵，dist最短路程，visited结束标记
    //      * path记录最短路径
    // 缺点：效率低，空间占用大;对负权回路失效。
    void dijkstra(int n, int s, vector<Edge> & edges) 
    {
        // 使用邻接矩阵存储
        vector<vector<int>> mat(n, vector<int>(n, INT_MAX));
        for (auto & edge : edges)
            mat[edge.u][edge.v] = edge.w;
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

        print(s, dist, path);
    } 

    // Bellman_Ford算法 时间复杂度O(mn) 可以检查负回路
    // 内存：dist最短路程，path记录最短路径
    // 缺点：效率低。
    void bellman_ford(int n, int s, vector<Edge> & edges) 
    {
        vector<int> dist(n, INT_MAX); // 源点到顶点i的最短路程
        dist[s] = 0;
        vector<int> path(n, s); // 记录最短路径
        // 循环 n-1 次求最短路径
        for (int i = 0; i < n; i++)
            for (auto & edge : edges) {
                // cout << dist[edge[1]] << " " << dist[edge[0]] + edge[2] << endl;
                if (dist[edge.v] > dist[edge.u] + edge.w)
                {
                    // cout << "in" << endl;
                    dist[edge.v] = dist[edge.u] + edge.w;
                    path[edge.v] = edge.u;
                }
            }

        bool flag = true; // 标记负回路
        // 第 n 次 循环检查负权回路
        for (auto & edge : edges)
            if (dist[edge.v] > dist[edge.u] + edge.w)
            {
                flag = false;
                break;
            }

        if (flag)
            print(s, dist, path);
        else
            cout << "存在负权回路!\n" << endl;
    }

    // SPFA算法 (Shortest Path Faster Algorithm) 可以检查负回路
    // 用队列记录待优化的“后”结点。
    // 内存：mat结点距离临接矩阵，dist最短路程，path记录最短路径
    //      * Q存储待优化队列，inqueue标记v是否在优化队列中。
    // 缺点：运行时间非常不稳定，容易被坏数据卡
    void SPFA(int n, int s, vector<Edge> & edges)
    {
        // 使用邻接矩阵存储
        vector<vector<int>> mat(n, vector<int>(n, INT_MAX));
        for (auto & edge : edges)
            mat[edge.u][edge.v] = edge.w;
        vector<int> dist(n); // 源点到顶点i的最短路程
        for (int i = 0; i < n; i++)
            dist[i] = mat[s][i];
        vector<bool> inqueue(n, false); // 求解结束标记数组
        vector<int> path(n, s); // 记录最短路径
        vector<int> enter_num(n, 0); // 记录入队次数
        bool flag = true; // 标记负回路
        
        queue<int> Q; // 待优化队列
        Q.push(s);
        inqueue[s] = true;
        dist[s] = 0;
        enter_num[s]++;

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            inqueue[u] = false;
            for (int v = 0; v < n; v++) {
                if (mat[u][v] < INT_MAX) { // 直接邻接
                    if (dist[u] + mat[u][v] < dist[v]) {
                        dist[v] = dist[u] + mat[u][v];
                        path[v] = u;
                    }
                    if (!inqueue[v]) {
                        Q.push(v);
                        enter_num[v]++;
                        if (enter_num[v] >= n) {
                            flag = false;
                            break;
                        }
                        inqueue[v] = true;
                    }
                }
            }
            if (!flag)
                break;
        }

        if (flag)
            print(s, dist, path);
        else
            cout << "存在负权回路!\n" << endl;
    } 

    void print(int s, vector<int>& dist, vector<int>& path)
    {
        for (int i = 0; i < dist.size(); i++)
            if (i != s && dist[i] < INT_MAX)
            {
                cout << s << "-->" << i << " : " << dist[i]
                     << " (" << i;
                int t = path[i];
                while (t != s) {
                    cout << " <- " << t;
                    t = path[t];
                }
                cout << " <- " << s << ")" << endl;
            }
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
    // 无负权回路图
    vector<Solution::Edge> edges1;
    edges1.emplace_back(0, 1, 3);
    edges1.emplace_back(0, 2, 1);
    edges1.emplace_back(0, 3, 2);
    edges1.emplace_back(1, 3, 3);
    edges1.emplace_back(2, 3, 2);
    edges1.emplace_back(3, 4, 3);
    edges1.emplace_back(2, 4, 3);
    // 有负权回路图
    vector<Solution::Edge> edges2;
    edges2.emplace_back(0, 1, 20);
    edges2.emplace_back(0, 2, 5);
    edges2.emplace_back(3, 0, -200);
    edges2.emplace_back(1, 3, 4);
    edges2.emplace_back(3, 1, 4);
    edges2.emplace_back(2, 3, 2);

    // 测试

    so.dijkstra(5, 0, edges1);

    so.bellman_ford(5, 0, edges1);
    so.bellman_ford(4, 0, edges2);

    so.SPFA(5, 0, edges1);
    so.SPFA(4, 0, edges2);
    return 0;
}


