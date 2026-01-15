#include <iostream>
using namespace std;

// 题目描述:反转链表
// 示例：
//  输入：1 -> 2 -> 3 -> 4 -> 5
//  输出：5 -> 4 -> 3 -> 2 -> 1
class Node
{
public:
    int val;
    Node *next;
    Node(int x) : val(x) {}
};

Node *ReverseList(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    Node *cur = head;
    Node *pre = nullptr;
    while (cur != nullptr)
    {
        Node *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    Node *newhead = ReverseList(head);
    Node *cur1 = newhead;
    while (cur1 != nullptr)
    {
        cout << cur1->val << " ";
        Node *next = cur1->next;
        delete cur1;
        cur1 = next;
    }
    cout << endl;
    return 0;
}