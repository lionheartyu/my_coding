#include <iostream>
using namespace std;

void *memmove(void *dest, void *src, size_t count)
{
    // 空指针保护
    if (dest == nullptr || src == nullptr)
    {
        return nullptr;
    }

    // 转化为字节指针(char*)，保证按字节拷贝，适配所有数据类型
    unsigned char *d = static_cast<unsigned char *>(dest);
    unsigned char *s = static_cast<unsigned char *>(src);

    // 判断内存是否重叠，决定拷贝方向
    if (d < s || d > s + count)
    {
        // 无重叠，从前向后拷贝
        for (size_t i = 0; i < count; i++)
        {
            d[i] = s[i];
        }
    }
    else
    {
        // 有重叠，从后向前拷贝
        for (size_t i = count; i > 0; i--)
        {
            d[i - 1] = s[i - 1];
        }
    }
    return dest;
}

int main()
{ // 初始化测试数组
    int data[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    const size_t cnt = 10;
    int *src = &data[0];  // 源数据：{0,1,2,3,4,5,6,7,8,9}
    int *dest = &data[5]; // 目标位置：初始是{5,6,7,8,9,10,11,12,13,14}

    // 调用自定义的 memmove
    memmove(dest, src, cnt * sizeof(int));

    // 输出结果，验证是否正确
    std::cout << "拷贝后 dest 指向的内容：";
    for (size_t i = 0; i < cnt; ++i)
    {
        std::cout << dest[i] << " ";
    }
    std::cout << std::endl;
    // 预期输出：0 1 2 3 4 5 6 7 8 9
    return 0;
}