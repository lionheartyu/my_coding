#include <iostream>
#include <vector>
using namespace std;
// 题目描述:旋转链表
// 给定一个链表，和一个非负整数 k，要求将链表向右旋转 k 个位置。

// 输入：
// 链表头节点 head，旋转次数 k。

// 输出：
// 返回旋转后的链表头节点。

// 示例：
// 输入：链表 1 → 2 → 3 → 4 → 5，k = 2
// 输出：链表 4 → 5 → 1 → 2 → 3

// 时间复杂度为总共是 O(n) + O(n) + O(n) = O(n)。
class Node
{
public:
    int val;
    Node *next;
    Node(int x) : val(x) {}
};

Node *RotateList(Node *head, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    vector<int> nums;
    Node *cur = head;
    while (cur != nullptr)
    {
        nums.push_back(cur->val);
        cur = cur->next;
    }
    int n = nums.size();
    if (k == 0 || n == 1)
    {
        return head;
    }
    vector<int> rotated(n);
    for (int i = 0; i < nums.size(); i++)
    {
        rotated[(i + k) % n] = nums[i];
    }
    Node *dummy = new Node(0);
    Node *tail = dummy;
    for (int i = 0; i < rotated.size(); i++)
    {
        Node *node = new Node(rotated[i]);
        tail->next = node;
        tail = tail->next;
    }
    return dummy->next;
}

int main()
{
    // 构造链表 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;
    Node *rotated = RotateList(head, k);

    // 打印旋转后的链表
    Node *cur = rotated;
    while (cur)
    {
        cout << cur->val << " ";
        Node *tmp = cur;
        cur = cur->next;
        delete tmp; // 释放内存
    }
    cout << endl;

    // 释放原链表内存
    cur = head;
    while (cur)
    {
        Node *tmp = cur;
        cur = cur->next;
        delete tmp;
    }

    return 0;
}