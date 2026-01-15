#include <iostream>
#include <vector>
using namespace std;
// 题目描述:二叉树的中序遍历
//  题目描述:二叉树的前序遍历
//   输入：
//   构造如下二叉树：
//        1
//       / \
//      2   3
//     / \
//    4   5
//   输出：
//   4 2 5 1 3
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void Infunc(TreeNode *node, vector<int> &nums)
{
    if (node == nullptr)
    {
        return;
    }
    // 左 中 右
    Infunc(node->left, nums);
    nums.push_back(node->val);
    Infunc(node->right, nums);
}

vector<int> Inorder(TreeNode *root)
{
    vector<int> nums;
    Infunc(root, nums);
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

    vector<int> res = Inorder(root);
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