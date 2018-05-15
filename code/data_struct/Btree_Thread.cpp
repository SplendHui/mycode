#include <iostream>
using namespace std;
/*这里是线索化二叉树的结构*/

enum Flag
{
    LINK, //一般指针的标记
    CLUE  //线索化指针的标记
};

template <class T>
struct Clue_Node //线索化二叉树的节点的结构
{
    Clue_Node(const T &value)
        : _value(value), _left(NULL), _right(NULL),
          _left_flag(LINK), _right_flag(LINK)
    {
    }

    T _value;
    Clue_Node *_left;
    Clue_Node *_right;
    Flag _left_flag;
    Flag _right_flag;
};
/*前序线索的构建*/
template <class T>
void Clue_Binary_Tree<T>::_Prev_Creat(Clue_Node<T> *root, Clue_Node<T> *&prev)
{
    if (root)
    {
        if (root->_left == NULL)
        {
            root->_left_flag = CLUE;
            root->_left = prev;
        }
        if (prev && prev->_right == NULL)
        {
            prev->_right_flag = CLUE;
            prev->_right = root;
        }
        prev = root;
        if (!root->_left_flag)
        {
            _Prev_Creat(root->_left, prev);
        }
        _Prev_Creat(root->_right, prev);
    }
}

/*前序线索下的遍历*/
template <class T>
void Clue_Binary_Tree<T>::_Prev_Order(Clue_Node<T> *root)
{
    cout << "在前序线索下的遍历:" << endl;
    while (root)
    {
        while (root->_left_flag != CLUE)
        {
            cout << root->_value << " ";
            root = root->_left;
        }
        cout << root->_value << " ";
        root = root->_right;
    }
    cout << endl;
}

/*中序线索的构建*/
template <class T>
void Clue_Binary_Tree<T>::_In_Creat(Clue_Node<T> *root, Clue_Node<T> *&prev)
{
    if (root)
    {
        _In_Creat(root->_left, prev); //左子树
        if (root->_left == NULL)
        {
            root->_left_flag = CLUE;
            root->_left = prev;
        }
        if (prev && prev->_right == NULL)
        {
            prev->_right_flag = CLUE;
            prev->_right = root;
        }
        prev = root;
        _In_Creat(root->_right, prev); //右子树
    }
}

/*中序线索下的遍历*/
template <class T>
void Clue_Binary_Tree<T>::_In_Order(Clue_Node<T> *root)
{
    cout << "中序遍历：" << endl;
    while (root)
    {
        while (root->_left_flag != CLUE)
        {
            root = root->_left;
        }
        cout << root->_value << " ";
        while (root->_right_flag != LINK)
        {
            root = root->_right;
            cout << root->_value << " ";
        }
        root = root->_right;
    }
    cout << endl;
}
int main()
{

}