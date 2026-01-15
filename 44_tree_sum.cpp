#include <iostream>
#include <vector>
using namespace std;
// 题目描述
// 给定一个二叉树和一个目标值 targetSum，请你找出所有从根节点到叶子节点路径上节点值之和等于目标值的路径。

// 每条路径必须从根节点出发，到叶子节点结束。
// 示例
// 示例 1：
// 输入:
// 二叉树:
//       5
//      / \
//     4   8
//    /   / \
//  11  13  4
//  / \     / \
// 7   2   5   1
// targetSum = 22
// 输出:
// [ [5,4,11,2], [5,8,4,5] ]

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void dfs(TreeNode *node, int targetsum, vector<int> &path, vector<vector<int>> &res, int sum)
{
    if (node == nullptr)
        return;
    path.push_back(node->val);
    sum += node->val;
    // 到达叶子节点且和等于目标值
    if (node->left == nullptr && node->right == nullptr && sum == targetsum)
    {
        res.push_back(path);
    }
    dfs(node->left, targetsum, path, res, sum);
    dfs(node->right, targetsum, path, res, sum);
    path.pop_back(); // 回溯
}

vector<vector<int>> FindTargetSum(TreeNode *root, int targetsum)
{
    vector<vector<int>> res;
    vector<int> path;
    dfs(root, targetsum, path, res, 0);
    return res;
}

int main()
{
    // 构造示例二叉树
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;
    vector<vector<int>> res = FindTargetSum(root, targetSum);

    for (const auto &path : res)
    {
        for (int v : path)
            cout << v << " ";
        cout << endl;
    }

    // 释放内存（略）
    return 0;
}