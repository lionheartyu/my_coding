#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 题目描述:二分搜索插入位置 时间复杂度:O(log n )
// 输入：
// 数组：[1, 2, 7, 5, 6, 9, 10]
// 目标值：5

// 输出：
// 3
int BinarySearch(vector<int> nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return left;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(9);
    nums.push_back(10);
    sort(nums.begin(), nums.end());
    cout << BinarySearch(nums, 5) << endl;
    return 0;
}