#include <iostream>
#include <algorithm>
using namespace std;
// 题目描述
// 给定一个字符串 s，你可以通过在字符串前面添加一些字符，将其转换为一个回文串。
// 请你找到并返回可以用这种方式转换的最短回文串。

// 示例
// 示例 1：
// 输入: s = "aacecaaa"
// 输出: "aaacecaaa"
// 解释: 在前面添加 "a"，得到回文串 "aaacecaaa"。

// 示例 2：
// 输入: s = "abcd"
// 输出: "dcbabcd"
// 解释: 在前面添加 "dcb"，得到回文串 "dcbabcd"。

bool isPalindrome(const string &s, int end)
{
    int left = 0, right = end;
    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

string shortestPalindrome(string s)
{
    int maxLen = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (isPalindrome(s, i))
        {
            maxLen = i + 1;
        }
    }
    string add = s.substr(maxLen);
    reverse(add.begin(), add.end());
    return add + s;
}

int main()
{
    string s1 = "aacecaaa";
    cout << shortestPalindrome(s1) << endl; // 输出: aaacecaaa

    string s2 = "abcd";
    cout << shortestPalindrome(s2) << endl; // 输出: dcbabcd

    return 0;
}