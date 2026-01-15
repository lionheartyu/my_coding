#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// 题目描述：
// 给定两个只包含数字字符的字符串，表示两个非负整数。请你计算它们的和，并以字符串形式返回结果。要求不能直接将字符串转换为整数处理（即不能用内置大数库或long long等），要模拟手工加法过程。
// 输入：
// num1 = "1234"
// num2 = "4321"

// 输出：
// "5555"
string
BigStringAdd(const string &num1, const string &num2)
{
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string res;
    while (i >= 0 || j >= 0 || carry)
    {
        int n1 = (i >= 0) ? num1[i--] - '0' : 0;
        int n2 = (j >= 0) ? num2[j--] - '0' : 0;
        int sum = n1 + n2 + carry;
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string num1 = "1234";
    string num2 = "4321";
    cout << BigStringAdd(num1, num2) << endl;
    return 0;
}