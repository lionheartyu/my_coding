#include <iostream>
#include <vector>
using namespace std;

// 题目描述:判断一棵树是否为二叉搜索树

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// 中序遍历判断是否为二叉搜索树
void TreeInorder(TreeNode *node, vector<int> &nums)
{
    // 递归终止条件
    if (node == nullptr)
    {
        return;
    }
    // 中序遍历  左中右
    TreeInorder(node->left, nums);
    nums.push_back(node->val);
    TreeInorder(node->right, nums);
}

bool IsBST(TreeNode *root)
{
    vector<int> res;
    TreeInorder(root, res);
    // 防止数组越界
    for (int i = 0; i < res.size() - 1; i++)
    {
        if (res[i + 1] < res[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    cout << IsBST(root) << endl;

    // 释放内存
    return 0;
}