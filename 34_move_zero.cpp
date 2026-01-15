#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 题目描述
// 给定一个数组 nums，编写一个函数将所有的 0 移动到数组的末尾，同时保持非零元素的相对顺序不变。

// 你必须在原地操作，不能拷贝额外的数组。

// 示例 1：
// 输入: nums = [0,1,0,3,12]
// 输出: [1,3,12,0,0]
void MoveZero(vector<int> &nums)
{
    int left = 0;
    int right = 0;
    while (right < nums.size())
    {
        if (nums[right])
        {
            swap(nums[left], nums[right]);
            left++;
        }
        right++;
    }
}
int main()
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(12);
    MoveZero(nums);
    for (auto it : nums)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}