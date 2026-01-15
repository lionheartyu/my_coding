#include <iostream>
#include <vector>
using namespace std;

// 快排分割函数
int postion(vector<int> &nums, int left, int right)
{
    int val = nums[left];
    while (left < right)
    {
        while (nums[right] > val && left < right)
        {
            right--;
        }
        if (left < right)
        {
            nums[left] = nums[right];
            left++;
        }
        while (nums[left] < val && left < right)
        {
            left++;
        }
        if (left < right)
        {
            nums[right] = nums[left];
            right--;
        }
    }
    if (left == right)
    {
        nums[left] = val;
    }
    return left;
}

void QuickSort(vector<int> &nums, int begin, int end)
{
    if (begin >= end)
    {
        return;
    }
    int midpos = postion(nums, begin, end);
    QuickSort(nums, begin, midpos - 1);
    QuickSort(nums, midpos + 1, end);
}

int main()
{
    vector<int> nums = {5, 2, 9, 1, 5, 6, 7, 3};
    QuickSort(nums, 0, nums.size() - 1);
    for (int n : nums)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}