#include <iostream>
#include <memory>
#include <string>
using namespace std;
class StrVec
{
  public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {} //构造函数
    StrVec(const StrVec &);                                            //拷贝构造
    // 移动构造函数
    StrVec(StrVec &&s) noexcept;
    StrVec &operator=(const StrVec &); //赋值运算符
    StrVec &StrVec::operator=(StrVec &&rhs) noexcept;
    ~StrVec();                                            //析构函数
    void push_back(const std::string &);                  //向尾部添加字符串
    size_t size() const { return first_free - elements; } //返回尺寸
    size_t capacity() const { return cap - elements; }    //返回容量
    std::string *begin() const { return elements; }       //返回首迭代器
    std::string *end() const { return first_free; }       //返回尾后迭代器
    std::string *begin() { return elements; }
    std::string *end() { return first_free; }

  private:
    //allocator对象，用于分配string空间
    static std::allocator<std::string> alloc;
    void chk_n_alloc() //检查是否分配空间
    {
        if ((size() == capacity()))
            reallocate();
    } //如果空间已满，重新分配空间
    //用于分配空间
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *); //ok
    void free();                                                                                    //释放空间，用于析构函数
    void reallocate();                                                                              //重新分配空间
    std::string *elements;                                                                          //首地址
    std::string *first_free;                                                                        //尾后地址
    std::string *cap;                                                                               //最后的地址
};

StrVec::StrVec(StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}

void StrVec::push_back(const string &s) //向尾部添加字符串
{
    chk_n_alloc();                    //检查剩余空间是否充足
    alloc.construct(first_free++, s); //在尾后指针构造对象，指针后移
}

pair<string *, string *>
StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(e - b); //分配空间
    //首指针        复制内容并返回尾后指针
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);                     //析构每个string对象
        alloc.deallocate(elements, cap - elements); //释放空间
    }
}

StrVec::StrVec(const StrVec &s) //拷贝构造函数
{
    //为新对象分配空间
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); } //析构函数

StrVec &StrVec::operator=(const StrVec &rhs) //赋值运算符
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end()); //分配新空间
    free();                                           //释放旧空间
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? size() * 2 : 1;
    auto newdata = alloc.allocate(newcapacity); //分配空间
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) //将原内存对象移动到新内存
        alloc.construct(dest++, std::move(*elem++));
    free(); //释放原内存
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}
int main()
{
    return 0;
}