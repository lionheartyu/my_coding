#include <iostream>
#include <string>
using namespace std;
// 题目描述:实现memcpy
void my_memcpy(string &dest, string src, int n)
{
    dest.resize(n);
    for (int i = 0; i < src.size(); i++)
    {
        dest[i] = src[i];
    }
    return;
}

int main()
{
    string s1 = "hello";
    string s2;
    my_memcpy(s2, s1, 6);
    cout << s2 << endl;
    return 0;
}