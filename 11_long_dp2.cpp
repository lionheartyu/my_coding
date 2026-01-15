#include <iostream>
#include <vector>
using namespace std;

// 题目描述:最长递增子序列
// 输入：
// [10, 9, 2, 5, 3, 7, 101, 18]

// 输出：
// 4
int lengthOfLIS(vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }
    vector<int> dp(nums.size(), 1);
    int res = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "最长递增子序列长度: " << lengthOfLIS(nums) << endl;
    return 0;
}