#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//题目描述:两数之和
vector<int> TwoSum(vector<int> nums, int target)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        auto iter = map.find(target - nums[i]);
        if (iter != map.end())
        {
            return {iter->second, i};
        }
        map.insert(pair<int, int>(nums[i], i));
    }
    return {};
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    vector<int> res;
    res = TwoSum(nums, 3);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}