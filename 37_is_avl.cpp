#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void Postorder(TreeNode *node, int &height)
{
    if (node == nullptr)
    {
        return;
    }
    // 后序遍历左右中
    int lh = 0;
    int rh = 0;
    Postorder(node->left, lh);
    Postorder(node->right, rh);
    height = max(lh, rh) + 1;
    if (abs(lh - rh) > 1)
    {
        height = -9999;
    }
}

bool IsAvlTree(TreeNode *root)
{
    int height = 0;
    Postorder(root, height);
    if (height == -9999)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(3);
    // root->left->left->left = new TreeNode(4);
    root->right = new TreeNode(2);

    if (IsAvlTree(root))
        cout << "是AVL树" << endl;
    else
        cout << "不是AVL树" << endl;

    // 释放内存（可选）
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}