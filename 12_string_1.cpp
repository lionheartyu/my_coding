#include <iostream>
#include <string>
using namespace std;
// 题目描述:给一个带空格的字符串,返回去除空格的字符串
// 输入：
// "hello      world"

// 输出：
// "helloworld"
void Delfunc(string &str)
{
    for (int i = 0; i < str.size();)
    {
        if (str[i] == ' ')
        {
            str.erase(i, 1);
        }
        else
        {
            i++;
        }
    }
    return;
}

int main()
{
    string Str = "hello      world";
    Delfunc(Str);
    cout << Str << endl;
    return 0;
}