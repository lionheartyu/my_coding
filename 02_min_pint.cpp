#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 题目描述：
// 给定一个包含若干非负整数的数组，请你找出其中最小的未出现的非负整数，并返回它。
// 输入：
// [0, 1, 3, 100]

// 输出：
// 2
int MinPint(vector<int> nums)
{
    int min = 1;
    // O(n log n)
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (min == nums[i])
        {
            min++;
        }
    }
    return min;
}
int main()
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(100);
    cout << MinPint(nums) << endl;
    return 0;
}