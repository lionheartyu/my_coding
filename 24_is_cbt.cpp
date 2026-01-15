#include <iostream>
#include <queue>
using namespace std;

// 题目描述:判断一棵树是否为完全二叉树
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool IsCBT(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }
    queue<TreeNode *> que;
    que.push(root);
    bool leaf = false; // 只在循环体内用，不用return前赋值
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = que.front();
            que.pop();
            if (leaf && (node->left || node->right))
            {
                return false;
            }
            if (node->left)
            {
                que.push(node->left);
            }
            else
            {
                leaf = true;
            }
            if (node->right)
            {
                if (leaf)
                    return false;
                que.push(node->right);
            }
            else
            {
                leaf = true;
            }
        }
    }
    return true;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << IsCBT(root) << endl;
    return 0;
}