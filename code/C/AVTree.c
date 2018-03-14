#include <stdio.h>
typedef int ElemType;
typedef struct BSTNode
{
    ElemType data;
    int bf;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

void R_rotate(BSTree *p)
{
    BSTree lc = (*p)->lchild;
    (*p)->lchild = lc->rchild;
    lc->rchild = *p;
    *p = lc;
}

void L_rotate(BSTree *p)
{
    BSTree rc = (*p)->rchild;
    (*p)->
}
int main()
{
    return 0;
}