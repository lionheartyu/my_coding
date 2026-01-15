#include <iostream>
#include <unordered_map>
using namespace std;
// 错误码和信息映射
unordered_map<int, string> errorMap = {
    {100, "网络错误"},
    {200, "参数错误"},
    {300, "权限不够"},
    {400, "未找到资源"},
    {500, "服务器内部错误"}};

string getErrorInfo(int errorCode)
{
    auto it = errorMap.find(errorCode);
    if (it != errorMap.end())
    {
        return it->second;
    }
    else
    {
        return "未知错误";
    }
}
int main()
{
    int errorCode;
    cout << "请输入错误号: ";
    cin >> errorCode;
    cout << getErrorInfo(errorCode) << endl;
    return 0;
}