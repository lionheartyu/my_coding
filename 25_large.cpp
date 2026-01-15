#include <iostream>
#include <vector>
using namespace std;
//...
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    int maxArea = 0;
    for (int i = 0; i < n; ++i)
    {
        int minH = heights[i];
        for (int j = i; j < n; ++j)
        {
            minH = min(minH, heights[j]);
            int area = minH * (j - i + 1);
            maxArea = max(maxArea, area);
        }
    }
    return maxArea;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(heights) << endl; // 输出: 10
    return 0;
}