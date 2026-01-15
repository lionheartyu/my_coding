#include <iostream>
#include <vector>
using namespace std;
// 题目描述
// 斐波那契数列（Fibonacci Sequence）指的是这样一个数列：
// 第 0 项是 0，第 1 项是 1，从第 2 项开始，每一项都等于前两项之和。

// 给定一个整数 n，请你计算并返回斐波那契数列的第 n 项（从 0 开始编号）。

// 示例
// 输入：
// n = 5

// 输出：
// 5

// 解释：
// 斐波那契数列为 0, 1, 1, 2, 3, 5，第 5 项是 5。

// 输入：
// n = 10

// 输出：
// 55
int Fibfunc(int n)
{
    // dp数组初始化及其下标的含义
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    // 确定遍历顺序
    for (int i = 2; i <= n; i++)
    {
        // 递推公式
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int res = 0;
    res = Fibfunc(10);
    cout << res << endl;
    return 0;
}