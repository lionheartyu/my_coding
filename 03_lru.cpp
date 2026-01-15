#include <iostream>
#include <unordered_map>
using namespace std;
// 设计一个数据结构 既能 O(1) 查找 ，又能 O(1) 维护访问顺序，实现了 LRU 缓存。
class Node
{
public:
    int key;
    int value;
    Node *pre;
    Node *next;
    Node(int x, int y) : key(x), value(y), pre(nullptr), next(nullptr) {}
};

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->pre = head;
    }
    ~LRUCache()
    {
        Node *cur = head;
        while (cur != nullptr)
        {
            Node *next = cur->next;
            delete cur;
            cur = next;
        }
    }
    int get(int key)
    {
        if (u_map.count(key))
        {
            Node *node = u_map[key];
            remove(node);
            HeadInsert(node);
            return node->value;
        }
        return -1;
    }
    void put(int key, int value)
    {
        if (u_map.count(key))
        {
            Node *node = u_map[key];
            node->value = value;
            remove(node);
            HeadInsert(node);
        }
        else
        {
            Node *node = new Node(key, value);
            u_map[key] = node;
            HeadInsert(node);

            if (u_map.size() > cap)
            {
                Node *toDelete = tail->pre;
                remove(toDelete);
                u_map.erase(toDelete->key);
                delete toDelete;
            }
        }
    }

    // 用于调试，打印当前缓存内容
    void printCache()
    {
        Node *cur = head->next;
        cout << "Cache: ";
        while (cur != tail)
        {
            cout << "(" << cur->key << "," << cur->value << ") ";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    void HeadInsert(Node *node)
    {
        node->next = head->next;
        node->pre = head;
        head->next->pre = node;
        head->next = node;
    }
    void remove(Node *node)
    {
        node->next->pre = node->pre;
        node->pre->next = node->next;
    }

    int cap;
    Node *head;
    Node *tail;
    unordered_map<int, Node *> u_map;
};

int main()
{
    LRUCache cache(2);
    cache.put(1, 1);
    cache.printCache(); // (1,1)
    cache.put(2, 2);
    cache.printCache();           // (2,2) (1,1)
    cout << cache.get(1) << endl; // 1
    cache.printCache();           // (1,1) (2,2)
    cache.put(3, 3);              // 淘汰key=2
    cache.printCache();           // (3,3) (1,1)
    cout << cache.get(2) << endl; // -1
    cache.put(4, 4);              // 淘汰key=1
    cache.printCache();           // (4,4) (3,3)
    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 3
    cout << cache.get(4) << endl; // 4
    return 0;
}