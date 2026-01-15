#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

// 题目描述
// 给定一个正整数 n，请你生成一个长度为 n 的数组，数组中的元素为 0 到 n-1 的所有整数，且每个数字只出现一次，顺序是随机的（即生成一个 0~n-1 的随机排列）。
// 示例
// 输入：
// n = 5

// 输出：
// [3, 0, 4, 1, 2]
// （输出顺序可能不同，只要包含 0~4 且不重复即可）
// 说明：

// 生成的数组中每个数字都不重复，且顺序随机。
// 可以多次运行，输出结果应不同。

vector<int> RandomNum(int n)
{
    vector<int> res;
    for (int i = 0; i < n; ++i)
        res.push_back(i);
    srand(time(0));
    // Fisher-Yates 洗牌
    for (int i = 0; i < n; i++)
    {
        int j = rand() % (i + 1);
        swap(res[i], res[j]);
    }
    return res;
}

int main()
{
    vector<int> res = RandomNum(5);
    for (auto it : res)
        cout << it << " ";
    cout << endl;
    return 0;
}