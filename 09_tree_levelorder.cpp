#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//题目描述:二叉树的层序遍历
// 题目描述:二叉树的前序遍历
//  输入：
//  构造如下二叉树：
//       1
//      / \
//     2   3
//    / \
//   4   5
//  输出：
//  1 2 3 4 5
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> Leverorder(TreeNode *root)
{
    vector<int> res;
    queue<TreeNode *> que;
    if (root != nullptr)
    {
        que.push(root);
    }
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = que.front();
            res.push_back(node->val);
            que.pop();
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
    }
    return res;
}
int main()
{ // 构造如下二叉树
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

    vector<int> res = Leverorder(root);
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