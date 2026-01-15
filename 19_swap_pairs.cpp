#include <iostream>
using namespace std;
// 题目描述 两两交换链表节点
//  输入：
//  链表：1 → 2 → 3 → 4

// 输出：
// 链表：2 → 1 → 4 → 3

class Node
{
public:
    int val;
    Node *next;
    Node(int x) : val(x) {}
};

Node *SwapPairs(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    // 虚拟头节点
    Node *dummy = new Node(0);
    dummy->next = head;
    Node *cur = dummy;
    while (cur->next != nullptr && cur->next->next != nullptr)
    {
        Node *tmp = cur->next;              // 记录临时节点
        Node *tmp1 = cur->next->next->next; // 记录临时节点
        cur->next = cur->next->next;        // 步骤一
        cur->next->next = tmp;              // 步骤二
        cur->next->next->next = tmp1;       // 步骤三

        cur = cur->next->next; // cur移动两位，准备下一轮交换
    }
    Node *res = dummy->next;
    delete dummy;
    return res;
}

int main()
{ // 构造链表 1 -> 2 -> 3 -> 4
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    Node *swapped = SwapPairs(head);

    // 打印交换后的链表
    Node *cur = swapped;
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