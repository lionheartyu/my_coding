#include <iostream>
#include <string>
using namespace std;
// 题目描述
// 编写一个函数，将输入的字符串原地反转（即不使用额外的字符串或数组），并输出反转后的结果。
// 示例 1：
// 输入: "helloworld"
// 输出: "dlrowolleh"
// 示例2:
// 输入: "abc"
// 输出: "cba"
// 示例3:
// 输入: "a"
// 输出: "a"
void ReverString(string &str)
{
    int i = 0;
    int j = str.size() - 1;
    for (; i < str.size() / 2; i++, j--)
    {
        swap(str[i], str[j]);
    }
}
int main()
{
    string s1 = "helloworld";
    ReverString(s1);
    cout << s1 << endl;
    return 0;
}