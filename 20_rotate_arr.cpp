#include <iostream>
#include <vector>
using namespace std;

// 题目描述: 旋转数组找最小值
// 输入: 一个原本递增排序的数组被旋转若干次，找出其中的最小值
// 示例: [4,5,6,7,0,1,2] 输出: 0

int findMin(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return nums[left];
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << "最小值: " << findMin(nums) << endl; // 输出0
    return 0;
}