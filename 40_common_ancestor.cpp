#include <iostream>
using namespace std;
// 题目描述
// 给定一棵二叉树，和树中的两个节点 p 和 q，请你找到这两个节点的最近公共祖先（Lowest Common Ancestor, LCA）。

// 最近公共祖先是指同时包含 p 和 q 的最深的那个节点（可以是它们自己）。

// 示例 1：
// 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// 输出: 3
// 解释: 节点 5 和 1 的最近公共祖先是节点 3。
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *Postorder(TreeNode *node, TreeNode *p, TreeNode *q)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node == p || node == q)
    {
        return node;
    }
    // 后序遍历
    TreeNode *left = Postorder(node->left, p, q);
    TreeNode *right = Postorder(node->right, p, q);
    if (left != nullptr && right != nullptr)
    {
        return node;
    }
    return left ? left : right;
}

TreeNode *CommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    return Postorder(root, p, q);
}

int main()
{
    // 构造示例二叉树
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode *p = root->left;  // 节点5
    TreeNode *q = root->right; // 节点1

    TreeNode *ancestor = CommonAncestor(root, p, q);
    if (ancestor)
        cout << ancestor->val << endl; // 输出: 3
    else
        cout << "未找到公共祖先" << endl;

    // 释放内存（略）
    return 0;
}