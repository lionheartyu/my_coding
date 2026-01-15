#include <iostream>
#include <string>
#include <stack>
using namespace std;
// 题目描述:有效的括号
// 给定一个只包括 '('、')'、'{'、'}'、'['、`']'`` 的字符串 s ，判断字符串是否有效。
//  示例1:
// 输入: s = "()"
//  输出: true
// 示例2:
//  输入: s = "()[]{}"
//  输出: true
// 示例3:
//  输入: s = "(]"
//  输出: false
// 示例4:
// 输入: s = "{[]}"
// 输出: true

bool IsValid(string str)
{
    stack<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '{')
        {
            st.push('}');
        }
        else if (str[i] == '[')
        {
            st.push(']');
        }
        else if (str[i] == '(')
        {
            st.push(')');
        }
        else if (st.empty() || str[i] != st.top())
        {
            return false;
        }
        else
        {
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    string Str1 = "{[]}";
    string Str2 = "(])";
    cout << IsValid(Str1) << endl;
    cout << IsValid(Str2) << endl;
    return 0;
}