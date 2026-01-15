#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 题目描述
// 给定一个未排序的整数数组 nums，请你找到其中第 k 大的元素。
// 请注意，你需要找的是数组排序后第 k 大的元素，而不是第 k 个不同的元素。
// 示例 1：
// 输入: nums = [3,2,1,5,6,4], k = 2
// 输出: 5

// 定义比较器->实现最大堆
class MyCompare
{
public:
    bool operator()(const int a, const int b)
    {
        return a < b;
    }
};

// const + &可以避免不必要的拷贝
// 用 const & 传递大型对象，可以避免拷贝，提高效率。
int findKthLargest(const vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, MyCompare> pri_que;
    for (int i = 0; i < nums.size(); i++)
    {
        pri_que.push(nums[i]);
    }
    k = k - 1;
    while (k--)
    {
        pri_que.pop();
    }
    return pri_que.top();
}

int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(4);
    cout << findKthLargest(nums, 2);
    cout << endl;
    return 0;
}