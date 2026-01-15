#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 题目描述
// 给你一个链表数组，每个链表都已经按升序排列。请你将所有链表合并成一个升序链表，并返回合并后的链表。
// 示例
// 示例 1：
// 输入：lists = [[1,4,5],[1,3,4],[2,6]]
// 输出：[1,1,2,3,4,4,5,6]
// 解释：将 3 个升序链表合并为一个新的升序链表。

// 示例 2：
// 输入：lists = []
// 输出：[]

// 示例 3：
// 输入：lists = [[]]
// 输出：[]
class Node
{
public:
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};

class MyComapre
{
public:
    bool operator()(const Node *left, const Node *right)
    {
        return left->val > right->val;
    }
};

// 这里的 lists 是一个链表头指针的数组
Node *mergeKLists(vector<Node *> &lists)
{
    priority_queue<Node *, vector<Node *>, MyComapre> pq;
    for (auto node : lists)
    {
        if (node)
            pq.push(node);
    }
    Node *dummy = new Node(0);
    Node *tail = dummy;
    while (!pq.empty())
    {
        Node *node = pq.top();
        pq.pop();
        tail->next = node;
        tail = tail->next;
        if (node->next)
            pq.push(node->next); // 下一个节点入堆
    }
    return dummy->next;
}
int main()
{
    // 构造链表1: 1 -> 4 -> 5
    Node *l1 = new Node(1);
    l1->next = new Node(4);
    l1->next->next = new Node(5);

    // 构造链表2: 1 -> 3 -> 4
    Node *l2 = new Node(1);
    l2->next = new Node(3);
    l2->next->next = new Node(4);

    // 构造链表3: 2 -> 6
    Node *l3 = new Node(2);
    l3->next = new Node(6);

    vector<Node *> lists = {l1, l2, l3};

    Node *merged = mergeKLists(lists);

    // 打印合并后的链表
    while (merged)
    {
        cout << merged->val << " ";
        merged = merged->next;
    }
    cout << endl;

    // 释放内存（略）
    return 0;
}