#include <iostream>
#include <vector>
using namespace std;

// 题目描述:合并两个有序链表
// 输入：

// 链表1：1 → 3 → 5
// 链表2：2 → 4 → 6
// 输出：

// 合并后的链表：1 → 2 → 3 → 4 → 5 → 6
class Node
{
public:
    int val;
    Node *next;
    Node(int x) : val(x) {}
};

Node *MergeList(Node *list1, Node *list2)
{
    if (list1 == nullptr && list2 == nullptr)
    {
        return nullptr;
    }
    Node *dummy = new Node(0);
    Node *tail = dummy;
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    tail->next = list1 ? list1 : list2;
    return dummy->next;
}

int main()
{
    // 构造第一个有序链表: 1 -> 3 -> 5
    Node *list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    // 构造第二个有序链表: 2 -> 4 -> 6
    Node *list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    // 合并链表
    Node *merged = MergeList(list1, list2);

    // 打印合并后的链表
    Node *cur = merged;
    while (cur)
    {
        cout << cur->val << " ";
        Node *tmp = cur;
        cur = cur->next;
        delete tmp; // 释放内存
    }
    cout << endl;

    return 0;
}