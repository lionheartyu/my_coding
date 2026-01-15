#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//题目描述:接雨水
class Solution
{
public:
    int trap(vector<int> &height)
    {
        stack<int> st;
        int result = 0;
        for (int i = 0; i < height.size(); i++)
        {
            while (!st.empty() && height[i] > height[st.top()])
            {
                int mid = st.top();
                st.pop();
                if (st.empty())
                    break;
                int h = min(height[i], height[st.top()]) - height[mid];
                int w = i - st.top() - 1;
                result += h * w;
            }
            st.push(i);
        }
        return result;
    }
};

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution sol;
    cout << sol.trap(height) << endl; // 输出6
    return 0;
}