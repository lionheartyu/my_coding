#include <iostream>
using namespace std;
// 题目描述:求n的平方数
//  输入：
//  8

// 输出：
// 2
int mySqrt(int n)
{
    int i = 0;
    while ((long long)i * i <= n)
        ++i;
    return i - 1;
}

int main()
{
    int n;
    cin >> n;
    cout << mySqrt(n) << endl;
    return 0;
}