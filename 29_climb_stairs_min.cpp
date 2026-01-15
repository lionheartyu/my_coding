#include <iostream>
#include <vector>
using namespace std;
// 题目描述
// 给定一个整数数组 cost，其中 cost[i] 是你爬上第 i 个台阶的花费。
// 每次你可以选择爬 1 个或 2 个台阶。请你计算到达楼顶的最小花费。
// 你可以选择从下标 0 或 1 开始爬楼梯。
// 示例
// 示例 1：
// 输入: cost = [10, 15, 20]
// 输出: 15
// 解释: 你可以选择从下标 1 开始，花费 15 到达楼顶。

int minCostClimbingStairs(vector<int> &cost)
{
    // dp[i] 代表第i个阶梯所需要的花费
    // 递推公式dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2])
    // dp[0]=0;dp[1]=0;站在0和1台阶不会花费,跳的时候才会花费
    // 从前向后遍历
    // debug
    vector<int> dp(cost.size() + 1);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= cost.size(); i++)
    {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[cost.size()];
}

int main()
{
    vector<int> cost1 = {10, 15, 20};
    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << minCostClimbingStairs(cost1) << endl; // 输出: 15
    cout << minCostClimbingStairs(cost2) << endl; // 输出: 6
    return 0;
}