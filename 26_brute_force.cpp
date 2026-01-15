#include <iostream>
using namespace std;

// 暴力字符串匹配
int BruteForce(const string &text, const string &pattern)
{
    int n = text.size(), m = pattern.size();
    if (m == 0)
        return 0;
    for (int i = 0; i <= n - m; ++i)
    {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
            ++j;
        if (j == m)
            return i; // 找到匹配，返回起始下标
    }
    return -1; // 未找到
}

int main()
{
    string text = "ababcabcacbab";
    string pattern = "abcac";
    int pos = BruteForce(text, pattern);
    cout << "匹配位置: " << pos << endl; // 输出: 5
    return 0;
}