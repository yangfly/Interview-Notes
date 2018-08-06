#include <iostream>
#include <stack>
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

    // 1.2 前序遍历非递归版
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

    // 1.3 中序遍历递归版：左中右
    // https://subetter.com/articles/2018/04/various-operations-of-the-binary-tree.html
    // https://www.cnblogs.com/SHERO-Vae/p/5800363.html

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


