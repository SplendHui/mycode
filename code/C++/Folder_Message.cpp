#include <set>
#include <string>

/****************以下是Folder类的完全声明***************************/
//编写Folder类，数据成员是指向Message类的指针集
class Message; //前向声明，用于在Folder中定义指向Message的指针
class Folder
{
  private:
    std::set<Message *> messages; //该目录的消息集
    //复制控制成员所用到的实用函数:
    //将目录加到形参所指的消息集中
    void put_Fldr_in_Messages(const std::set<Message *> &);
    //从目录所含的消息集中删除该目录
    void remove_Fldr_in_Messages();

  public:
    //默认构造函数
    Folder(){};
    //复制控制成员
    Folder(const Folder &r);
    Folder &operator=(const Folder &);
    ~Folder();
    //在指定Message的目录集中添加/删除该目录
    void save(Message &);
    void remove(Message &);
    //在该目录的消息集中添加/删除指定消息
    void addMsg(Message *);
    void remMsg(Message *);
};
/****************以上是Folder类的完全声明***************************/

/***************以下是Message类的完全声明***************************/
class Message
{
  private:
    std::string contents;       //实际消息文本
    std::set<Folder *> folders; //包含该消息的目录
    //复制构造函数、赋值操作符和析构函数所使用的实用函数：
    //将消息加到形参所指的目录集中，即在目录中添加指向该消息的指针
    void put_Msg_in_Folders(const std::set<Folder *> &);
    //从消息所在的目录中删除该消息,即删除指向该消息的指针
    void remove_Msg_from_Folders();

  public:
    //folders自动初始化为空集
    Message(const std::string &str = "") : contents(str) {}
    //复制控制成员
    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();
    //save操作，在指定Folder的消息集中添加该消息
    void save(Folder &);
    //remove操作，在指定Folder的消息集中删除该消息
    void remove(Folder &);
    //在包含该消息的目录集（set<Folder*> folders）中添加/删除Folder指针
    void addFldr(Folder *);
    void remFldr(Folder *);
};
/***************以上是Message类的完全声明***************************/

/***************以下是Folder类成员函数的定义************************/
//复制构造函数，假设将目录fldr1复制给fldr2:
//1.内容复制：将目录fldr1的内容复制给fldr2，可以自动完成
//2.在目录fldr1包含的消息集中添加指向fldr2的指针
Folder::Folder(const Folder &f) : messages(f.messages)
{
    put_Fldr_in_Messages(f.messages);
}
//赋值操作符，假设将目录fldr3赋值给fldr4:
//1.删除目录fldr4：在fldr4包含的消息集中删除指向fldr4的指针
//2.内容复制：将fldr3的内容复制给fldr4
//3.添加目录：在fldr3包含的消息集中添加指向fldr4的指针
Folder &Folder::operator=(const Folder &rhs)
{
    if (&rhs != this)
    {
        remove_Fldr_in_Messages();
    }
    return *this;
}
//析构函数
//1.删除目录内容，自动完成
//2.在该目录所包含的消息集中删除指向该目录的指针
Folder::~Folder()
{
    remove_Fldr_in_Messages();
}
//将目录加到形参所指的消息集中，即要在Message类的set<Folder*>中添加
//指向该目录的指针元素，这需要调用类Message的成员函数addFldr()
void Folder::put_Fldr_in_Messages(const std::set<Message *> &rhs)
{
    for (std::set<Message *>::const_iterator beg = rhs.begin();
         beg != rhs.end(); ++beg) //循环遍历形参所指的消息集
        (*beg)->addFldr(this);
}
//从目录所含的消息集中删除该目录，即在Message类的set<Folder*>中删除
//指向该目录的指针，这需要调用类Message的成员函数remFldr()
void Folder::remove_Fldr_in_Messages()
{
    for (std::set<Message *>::const_iterator beg = messages.begin();
         beg != messages.end(); ++beg)
        (*beg)->remFldr(this);
}
//save操作
void Folder::save(Message &msg)
{
    addMsg(&msg);
    msg.addFldr(this); //更新相应的消息
}
//remove操作
void Folder::remove(Message &msg)
{
    remMsg(&msg);
    msg.remFldr(this); //更新相应的消息
}
//接受一个指向消息Message的指针，并添加消息集set<Message*>中
void Folder::addMsg(Message *msg)
{
    messages.insert(msg);
}
//接受一个指向消息Message的指针，并在消息集set<Message*>中删除该指针
void Folder::remMsg(Message *msg)
{
    messages.erase(msg);
}
/***************以上是Folder类成员函数的定义************************/

/***************以下是Message类成员函数的定义************************/
//复制构造函数，假设将消息Ms1复制给新消息Ms2,j即Ms2(Ms1)：
//1.将Ms1的内容复制复制给Ms2
//2.在消息Ms1所属目录集中添加指向消息Ms2的指针
Message::Message(const Message &m) : contents(m.contents), folders(folders) //复制内容
{
    put_Msg_in_Folders(m.folders); //调用函数在目录集中添加指向新消息的指针
}
//赋值操作符,假设将消息Ms3赋值给Ms4,即Ms4=Ms3:
//1.首先删除Ms4所属目录集中指向Ms4的指针
//2.然后将Ms3的内容复制给Ms4
//3.最后，在Ms3所属的目录集中添加指向Ms4的指针
Message &Message::operator=(const Message &rhs)
{
    if (&rhs != this) //两个消息不相等，赋值才有意义
                      //这里的&rhs是取rhs对象的地址，而不是rhs的引用
    //因为this就是一个指向对象的指针，它的值就是所指对象的地址
    {
        //从消息所在的目录集中删除该消息,即删除指向该消息的指针
        remove_Msg_from_Folders();
        //复制rhs中的内容
        contents = rhs.contents;
        folders = rhs.folders;
        //将消息加到形参所指的目录集中
        put_Msg_in_Folders(rhs.folders);
    }
    return *this;
}
/******************************************************************************
 为什么在复制构造函数不首先删除Ms2所属目录集中指向Ms2的指针，而赋值操作符中却要
 首先删除Ms4所属目录集中指向Ms4的指针呢?这就涉及到复制构造函数和赋值操作符的区别：
 复制构造函数用于产生新对象，给新对象初始化。故Ms2是新对象，它不属于任何目录集。
 而赋值操作符则是用于两个本已存在的对象，故需要首先删除。
 ******************************************************************************/
//析构函数:
//1.删除Message的内容，可以自动完成
//2.在消息所属的目录集中删除该消息，即删除指向该消息的指针
Message::~Message()
{
    void remove_Msg_from_Folders();
}
//将消息加到形参所指的目录集中,即在目录中添加指向该消息的指针
void Message::put_Msg_in_Folders(const std::set<Folder *> &rhs)
{
    for (std::set<Folder *>::const_iterator beg = rhs.begin();
         beg != rhs.end(); ++beg) //循环遍历形参所指的目录集
        (*beg)->addMsg(this);     //在目录中添加指向该消息的指针：
                                  //beg是指向消息所属的目录的指针，*beg就是该目录
                                  //它属于类Folder，然后调用用目录成员函数addMsg
}
//在消息所属的目录集中删除该消息，即删除指向该消息的指针
void Message::remove_Msg_from_Folders()
{
    for (std::set<Folder *>::const_iterator beg = folders.begin();
         beg != folders.end(); ++beg) //遍历消息所属的目录集
        (*beg)->remMsg(this);
}
//save操作，在指定目录的消息集中添加该消息:
//1.将该目录添加到Message的目录集中，即在Message的目录集set<Folder*>添加一个指针，
//  指向该目录
//2.更新目录以反映它指向该Message，即在目录中添加一个指向该Message的指针
void Message::save(Folder &fldr)
{
    addFldr(&fldr);    //1.调用消息类Message的成员函数addFldr()添加指向目录的指针
    fldr.addMsg(this); //2.调用目录类Folder的成员函数addMsg()添加指向消息的指针
}
//remove操作，在指定Folder的消息集中删除该消息
//1.在消息所属目录集中删除该目录，即在set<Folder*>中删除指向该目录的指针
//2.更新目录：在目录中删除指向该消息的指针
void Message::remove(Folder &fldr)
{
    remFldr(&fldr);    //1.调用消息类Message的成员函数remFldr()删除指向目录的指针
    fldr.remMsg(this); //2.调用目录类Folder的成员函数remMsg()删除指向该消息的指针
}
//接受一个指向目录Folder的指针，并添加目录集set<Folder*>中
void Message::addFldr(Folder *fldr)
{
    folders.insert(fldr);
}
//接受一个指向目录Folder的指针，并在目录集set<Folder*>中删除该指针
void Message::remFldr(Folder *fldr)
{
    folders.erase(fldr);
}
/***************以上是Message类成员函数的定义************************/