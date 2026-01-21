#include <iostream>
#include <stack>
using namespace std;
// 题目描述：

// 请你仅使用两个栈实现一个队列。队列应支持以下操作：push(x)——将元素 x 推到队列的末尾；
// pop()——移除队列最前面的元素并返回该元素；
// peek()——返回队列最前面的元素；
// empty()——返回队列是否为空。

// 示例:
//  MyQueue *queue = new MyQueue();
//  queue->push(1);
//  queue->push(2);
//  queue->peek();    // 返回 1
//  queue->pop();     // 返回 1
//  queue->empty();   // 返回 false

class MyQueue
{
public:
    MyQueue() {}
    // push
    void push(int x)
    {
        stIn.push(x);
    }
    // pop
    int pop()
    {
        if (stOut.empty())
        {
            while (!stIn.empty())
            {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int res = stOut.top();
        stOut.pop();
        return res;
    }

    // peek
    int peek()
    {
        int res = this->pop();
        stOut.push(res);
        return res;
    }
    // empty
    bool empty()
    {
        return stIn.empty() && stOut.empty();
    }

private:
    stack<int> stIn;
    stack<int> stOut;
};

int main()
{
    MyQueue *que = new MyQueue();
    que->push(1);
    que->push(2);
    cout << que->pop() << endl;
    cout << que->pop() << endl;
    delete que;
    return 0;
}