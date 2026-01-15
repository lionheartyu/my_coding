#include <iostream>
#include <vector>
using namespace std;
// 题目描述
// 给定一个整数数组，请你编写一个函数，将数组中的所有奇数移动到数组的前面，
// 所有偶数移动到数组的后面，要求在原数组上操作，可以不保证奇数和偶数之间的相对顺序。
// 示例 1：
// 输入: [1, 2, 3, 4, 5, 6]
// 输出: [1, 3, 5, 4, 2, 6]
// （输出顺序可能不同，只要奇数都在前，偶数都在后即可）

void MoveArr(vector<int> &nums)
{
    int left = 0;
    int right = 0;
    while (right < nums.size())
    {
        if (nums[right] % 2 != 0)
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
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    MoveArr(nums);
    for (auto it : nums)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}