#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

static const auto ______ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


/** 背景：二叉树的常用操作
 * 1. 前序遍历，中序遍历，后序遍历。
 * 2. 层次遍历
 * 3. 求树的结点个数
 * 4. 求树的叶子数
 * 5. 求树的深度
 * 6. 求二叉树的第k层的结点个数
 * 7. 判断两棵二叉树是否结构相同
 * 8. 求二叉树的镜像
 * 9. 求两个节点的最小公共祖先结点
 * 10. 求任意两节点的距离
 * 11. 找出二叉树中某个结点的所有祖先结点
 * 12. 不适用递归和栈遍历二叉树
 * 13. 二叉树前序中序推后序
 * 14. 判断二叉树是不是完全二叉树
 * 15. 判断是否是二叉树的后序遍历结果
 * 16. 给定一个二叉查找树中的节点，找出在中序遍历下它的后继和前驱
 * 17. 二分查找树转化为排序的循环双链表
 * 18. 有序链表转化为平衡的二分查找树
 * 19. 判断是否是二叉查找树
 **/
class Solution {
public:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    // 1.1 前序遍历递归版：中左右
    void preOrder1(Node* root)
    {
        if (root != nullptr) {
            cout << root->data << " ";
            preOrder1(root->left);
            preOrder1(root->right);
        }
    }

    // 1.2 前序遍历非递归版：DFS
    void preOrder2(Node* root)
    {
        stack<Node*> S;
        while (root != nullptr || !S.empty()) {
            while (root != nullptr) {
                cout << root->data << " ";
                S.push(root);
                root = root->left;
            }
            if (!S.empty()) {
                root = S.top();
                S.pop();
                root = root->right;
            }
        }
    }

    // 1.3 中序遍历递归版：左中右、
    void inOrder1(Node* root)
    {
        if (root != nullptr) {
            inOrder1(root->left);
            cout << root->data << " ";
            inOrder1(root->right);
        }
    }

    // 1.4 中序遍历非递归版：DFS
    void inOrder2(Node* root)
    {
        stack<Node*> S;
        while (root != nullptr || !S.empty()) {
            while (root != nullptr) {
                S.push(root);
                root = root->left;
            }
            if (!S.empty()) {
                root = S.top();
                cout << root->data << " ";
                S.pop();
                root = root->right;
            }
        }
    }

    // 1.5 后续遍历递归版：左右中
    void postOrder1(Node* root)
    {
        if (root != nullptr) {
            postOrder1(root->left);
            postOrder1(root->right);
            cout << root->data << " ";
        }
    }

    // 1.6 后续遍历非递归版：DFS
    void postOrder2(Node* root)
    {
        stack<Node*> S;
        Node *cur, *pre = nullptr; // 前一个访问的结点
        S.push(root);
        while (!S.empty()) {
            cur = S.top();
            // 保证输出前，左右孩子都已经被访问到，否则先将左右孩子入栈。
            // 初始输出：既没有左孩子，也没有右孩子；
            // 后续输出：回溯(从左边或右边)上来，表示左右孩子为空或都访问了
            if ((cur->left == nullptr && cur->right == nullptr) ||
                (pre != nullptr && (pre == cur->left || pre == cur->right)))
            {
                cout << cur->data << " ";
                S.pop();
                pre = cur;
            }
            else {
                if (cur->left != nullptr)
                    S.push(cur->left);
                if (cur->right != nullptr)
                    S.push(cur->right);
            }
        }
    }

    // 2. 层次遍历 BFS
    void levelOrder(Node* root)
    {
        queue<Node*> Q;
        Q.push(root);
        while (!Q.empty()) {
            root = Q.front();
            Q.pop();
            cout << root->data << " ";
            if (root->left != nullptr)
                Q.push(root->left);
            if (root->right != nullptr)
                Q.push(root->right);
        }
    }

    // 3. 求树的结点数
    int countNodes(Node* root)
    {
        if (root != nullptr)
            return 1 + countNodes(root->left) + countNodes(root->right);
        else
            return 0;
    }

    // 4. 求树的叶子数
    int countLeaves(Node* root)
    {
        if (root == nullptr)
            return 0;
        else if (root->left == nullptr && root->right == nullptr)
            return 1;
        else
            return countLeaves(root->left) + countLeaves(root->right);
    }

    // 5. 求树的深度
    int getDepth(Node* root)
    {
        if (root == nullptr)
            return 0;
        else
            return max(getDepth(root->left), getDepth(root->right)) + 1;
    }

    // 6. 求二叉树第k层的结点个数
    int getKLevel(Node* root, int k)
    {
        if (root == nullptr)
            return 0;
        else if (k == 1)
            return 1;
        else
            return getKLevel(root->left, k-1) + getKLevel(root->right, k-1);
    }

    // 7. 判断两棵二叉树是否结构相同
    bool structCmp(Node* root1, Node* root2)
    {
        if (root1 == nullptr && root2 == nullptr)
            return true;
        else if (root1 != nullptr || root2 != nullptr)
            return false;
        else
            return structCmp(root1->left, root2->left) && structCmp(root1->right, root2->right);
    }

    // 8. 求二叉树的镜像
    void mirror(Node* root)
    {
        if (root != nullptr) {
            swap(root->left, root->right);
            mirror(root->left);
            mirror(root->right);
        }
    }

    // 9. 求两个结点的最低公共祖先结点:LCA(lowest Common Ancestor)
    Node* findLCA(Node* root, Node* a, Node* b)
    {
        if (root == nullptr)
            return nullptr;
        if (a == root || b == root) // 遇到就返回
            return root;
        Node* left = findLCA(root->left, a, b);
        Node* right = findLCA(root->right, a, b);
        if (left && right) // 分别在两个子树上
            return root;
        else
            return left != nullptr ? left : right; 
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
    // vector<string> strs = {"abcd", "ababa", "abccb"};
    // for (string& s : strs)
    //     cout << so.pure_search(s) << " "
    //          << so.bi_search(s)   << " "
    //          << so.manacher(s)    << endl;
    // so.manacher(strs[2], true);
    return 0;
}


