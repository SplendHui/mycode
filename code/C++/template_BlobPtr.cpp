#include <iostream>
#include <set>
#include <vector>
#include <memory>
#include "template_StrBlob.cpp"
template <typename T>
class Blob;
template <typename T>
class BlobPtr
{
  public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T> &a, std::size_t sz = 0) : wptr(a.data), curr(sz)
    {
        a.push_back(10);
        cout << a.size() << endl;
    }
    T &operator*() const
    {
        auto p = check(curr, "* error");
        return (*p)[curr];
    }
    BlobPtr &operator++();
    BlobPtr &operator--();

  private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
    std::shared_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T>
std::shared_ptr<std::vector<T>>
BlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
    //检查是否存在
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound BlobPtr");
    if (i < 0 && i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++()
{
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--()
{
    BlobPtr ret = *this;
    --*this;
    return ret;
}

int main()
{

    Blob<int> ca;
    BlobPtr<int> pa(ca);
    return 0;
}