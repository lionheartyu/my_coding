#include <iostream>
#include <unordered_set>
using namespace std;
// 题目描述
// 给定一个字符串 s，请你找出其中不含有重复字符的最长子串的长度。

// 示例
// 示例 1：
// 输入: s = "abcabcbb"
// 输出: 3
// 解释: 无重复字符的最长子串是 "abc"，其长度为 3。

// 示例 2：
// 输入: s = "bbbbb"
// 输出: 1
// 解释: 无重复字符的最长子串是 "b"，其长度为 1。
int lengthOfLongestSubstring(string s)
{
    int left = 0;
    int right = 0;
    int length = 0;
    unordered_set<char> set;
    while (right < s.size())
    {
        while (set.count(s[right]))
        {
            set.erase(s[left]);
            left++;
        }
        set.insert(s[right]);
        length = max(length, right - left + 1);
        right++;
    }
    return length;
}
int main()
{
    string s1 = "abcabcbb";
    cout << lengthOfLongestSubstring(s1) << endl;
    return 0;
}