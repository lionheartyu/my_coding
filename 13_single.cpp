#include <iostream>
#include <mutex>
using namespace std;
//题目描述:手写线程安全的单例模式
class Singleton
{
public:
    static Singleton *getInstance()
    {
        // C++11后静态局部变量初始化是线程安全的
        static Singleton instance;
        return &instance;
    }
    void show()
    {
        cout << "This is a thread-safe Singleton." << endl;
    }

private:
    Singleton() {} // 构造函数私有化
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
};

int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    s1->show();
    cout << (s1 == s2) << endl;
    return 0;
}