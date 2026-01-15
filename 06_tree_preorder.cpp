#include <iostream>
#include <vector>
using namespace std;
// 题目描述:二叉树的前序遍历
//  输入：
//  构造如下二叉树：
//       1
//      / \
//     2   3
//    / \
//   4   5
//  输出：
//  1 2 4 5 3
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void Prefunc(TreeNode *node, vector<int> &nums)
{
    if (node == nullptr)
    {
        return;
    }
    // 中 左 右
    nums.push_back(node->val);
    Prefunc(node->left, nums);
    Prefunc(node->right, nums);
}

vector<int> Preorder(TreeNode *root)
{
    vector<int> nums;
    Prefunc(root, nums);
    return nums;
}

int main()
{
    // 构造如下二叉树
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> res = Preorder(root);
    for (int v : res)
    {
        cout << v << " ";
    }
    cout << endl;

    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}