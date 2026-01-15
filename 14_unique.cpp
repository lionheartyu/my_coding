#include <iostream>
using namespace std;
//题目描述:手写一个unique_ptr
template <typename T>
class MyUniquePtr
{
public:
    explicit MyUniquePtr(T *ptr = nullptr) : ptr_(ptr) {}

    // 禁止拷贝
    MyUniquePtr(const MyUniquePtr &) = delete;
    MyUniquePtr &operator=(const MyUniquePtr &) = delete;

    // 允许移动
    MyUniquePtr(MyUniquePtr &&other) noexcept : ptr_(other.ptr_)
    {
        other.ptr_ = nullptr;
    }
    MyUniquePtr &operator=(MyUniquePtr &&other) noexcept
    {
        if (this != &other)
        {
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    ~MyUniquePtr()
    {
        delete ptr_;
    }

    T *get() const { return ptr_; }
    T &operator*() const { return *ptr_; }
    T *operator->() const { return ptr_; }

private:
    T *ptr_;
};

int main()
{
    MyUniquePtr<int> p1(new int(42));
    cout << *p1 << endl;

    MyUniquePtr<int> p2 = std::move(p1);
    if (!p1.get())
        cout << "p1 is null" << endl;
    cout << *p2 << endl;

    return 0;
}