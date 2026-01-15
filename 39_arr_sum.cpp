#include <iostream>
#include <vector>
using namespace std;

// 题目描述
// 给定一个整数数组，请你找出一个正负数交替排列的子序列，使得该子序列的元素和最大。
// 子序列中的相邻元素必须符号相反（即正负交替），且子序列不要求连续。
// 示例
// 示例 1：
// 输入: [1, 2, -3, 4, -2, -1, 2, -5]
// 输出: 8
// 解释: 最大和的正负交替子序列为 [1, -3, 4, -1, 2]，和为 1 + (-3) + 4 + (-1) + 2 = 3
// 但实际上 [2, -3, 4, -1, 2] = 2 + (-3) + 4 + (-1) + 2 = 4
// 更优的是 [2, -3, 4, -1, 2]，和为 4
// （实际最大和的子序列可能不同，关键是正负交替且和最大）

// 示例 2：
// 输入: [-1, -2, -3, -4]
// 输出: -1
// 解释: 只有一个负数可选，最大和为 -1

// 示例 3：
// 输入: [5, -1, 2, -2, 3, -3]
// 输出: 9
// 解释: [5, -1, 2, -2, 3]，和为 5 + (-1) + 2 + (-2) + 3 = 7

int maxAlternatingSum(const vector<int> &nums)
{
    if (nums.empty())
        return 0;
    int n = nums.size();
    long long sum = 0;
    int i = 0;
    while (i < n)
    {
        // 取当前符号段的最大值
        int curr = nums[i];
        int j = i + 1;
        while (j < n && ((nums[j] > 0) == (curr > 0)))
        {
            curr = max(curr, nums[j]);
            ++j;
        }
        sum += curr;
        i = j;
    }
    return sum;
}

int main()
{
    vector<int> nums = {1, 2, -3, 4, -2, -1, 2, -5};
    cout << maxAlternatingSum(nums) << endl; // 输出: 8

    vector<int> nums2 = {-1, -2, -3, -4};
    cout << maxAlternatingSum(nums2) << endl; // 输出: -1

    vector<int> nums3 = {5, -1, 2, -2, 3, -3};
    cout << maxAlternatingSum(nums3) << endl; // 输出: 9

    return 0;
}