#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
// 题目描述
// 给定一个整数数组 nums 和一个整数 k，请你返回其中出现频率前 k 高的元素。
// 你可以按任意顺序返回答案。

// 示例 1：
//  输入: nums = [1,1,1,2,2,3], k = 2
//  输出: [1,2]
// 定义比较器->实现最小堆
class MyCompare
{
public:
    bool operator()(const pair<int, int> lhs, const pair<int, int> rhs)
    {
        return lhs.second > rhs.second;
    }
};

vector<int> topKFrequent(vector<int> nums, int k)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare> pri_que;
    for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++)
    {
        pri_que.push(*it);
        if (pri_que.size() > k)
        {
            pri_que.pop();
        }
    }
    vector<int> res;
    for (int i = 0; i < k; i++)
    {
        res.push_back(pri_que.top().first);
        pri_que.pop();
    }
    return res;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    vector<int> res;
    res = topKFrequent(nums, 2);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}