#include <iostream>
#include <set>
using namespace std;
// 题目描述
// 给定两个版本号字符串 version1 和 version2，请你比较它们的大小。

// 版本号由若干数字和点 . 组成，数字之间由点分隔。比较时，
// 从左到右逐段比较对应的数字，若某一段不同，则较大的版本号更大；如果某一段缺失，则视为 0。
// 返回结果：

// 如果 version1 > version2，返回 1
// 如果 version1 < version2，返回 -1
// 如果相等，返回 0

// 示例
// 示例 1：
// 输入: version1 = "1.01", version2 = "1.001"
// 输出: 0
// 解释: "01" 和 "001" 都代表数字 1

// 示例 2：
// 输入: version1 = "1.0", version2 = "1.0.0"
// 输出: 0
// 解释: 末尾多出的 0 不影响大小

// 示例 3：
// 输入: version1 = "0.1", version2 = "1.1"
// 输出: -1
// 解释: version1 < version2

int CompareVersion(string v1, string v2)
{
    int left = 0;
    int right = 0;
    int n1 = v1.size();
    int n2 = v2.size();
    while (left < n1 || right < n2)
    {
        int num1 = 0;
        int num2 = 0;
        while (left < n1 && v1[left] != '.')
        {
            num1 = num1 * 10 + (v1[left] - '0');
            left++;
        }
        while (right < n2 && v2[right] != '.')
        {
            num2 = num2 * 10 + (v2[right] - '0');
            right++;
        }
        if (num1 > num2)
            return 1;
        if (num1 < num2)
            return -1;
        left++;
        right++;
    }
    return 0;
}

int main()
{
    string version1 = "1.01";
    string version2 = "1.001";
    cout << CompareVersion(version1, version2) << endl; // 输出: 0

    version1 = "1.0";
    version2 = "1.0.0";
    cout << CompareVersion(version1, version2) << endl; // 输出: 0

    version1 = "0.1";
    version2 = "1.1";
    cout << CompareVersion(version1, version2) << endl; // 输出: -1

    version1 = "1.2.3";
    version2 = "1.2.2";
    cout << CompareVersion(version1, version2) << endl; // 输出: 1

    return 0;
}