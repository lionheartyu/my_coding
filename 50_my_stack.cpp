#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
public:
    queue<int> que1;
    queue<int> que2;
    MyStack() {}

    void push(int x) { que1.push(x); }

    int pop()
    {
        int size = que1.size();
        size--;
        while (size--)
        {
            que2.push(que1.front());
            que1.pop();
        }
        int res = que1.front();
        que1.pop();
        que1 = que2;
        while (!que2.empty())
        {
            que2.pop();
        }
        return res;
    }

    int top()
    {
        int size = que1.size();
        size--;
        while (size--)
        {
            que2.push(que1.front());
            que1.pop();
        }
        int res = que1.front();
        que2.push(que1.front());
        que1 = que2;
        while (!que2.empty())
        {
            que2.pop();
        }
        return res;
    }

    bool empty() { return que1.empty(); }
};

int main()
{
    MyStack st;
    st.push(1);
    st.push(2);
    cout << st.top() << endl;   // 输出 2
    cout << st.pop() << endl;   // 输出 2
    cout << st.empty() << endl; // 输出 0（false）
    cout << st.pop() << endl;   // 输出 1
    cout << st.empty() << endl; // 输出 1（true）
    return 0;
}
