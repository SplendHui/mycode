#include <iostream>
#include <vector>
#include <memory>
using namespace std;

template <typename T>
class BlobPtr;
template <typename T>
class Blob;

template <typename T>
bool operator==(const Blob<T> &, const Blob<T> &);

template <typename T>
class Blob
{
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T> &, const Blob<T> &);

  public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    Blob();
    Blob(std::initializer_list<T> il);
    size_type size() const { return data->size(); }

    bool empty() const { return data->empty(); }

    void push_back(const T &t)
    {
        data->push_back(t);
    }
    void push_back(T &&t)
    {
        data->push_back(std::move(t));
    }

    void pop_back();

    T &back();

    T &operator[](size_type i);

  private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T>
T &Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
T &Blob<T>::back()
{
    check(0, "on empty Blob");
    return data->back();
}
/*
int main()
{

    Blob<string> articles = {"a", "an", "the"};
    cout << articles.back();
    return 0;
}
*/