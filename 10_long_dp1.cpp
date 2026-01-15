#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 题目描述:最长连续递增子序列长度
// 示例：
// 输入：[10, 9, 2, 5, 3, 7, 101, 18]
// 输出：4
int findLengthOfLCIS(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    vector<int> dp(nums.size(), 1);
    int res = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
        }
        if (dp[i] > res)
        {
            res = dp[i];
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "最长连续递增子序列长度: " << findLengthOfLCIS(nums) << endl;
    return 0;
}