#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */

/* 二叉树的二叉链表结点结构定义 */
typedef struct BitNode /* 结点结构 */
{
    int data;                        /* 结点数据 */
    int bf;                          /*  结点的平衡因子 */
    struct BitNode *lchild, *rchild; /* 左右孩子指针 */
} BitNode, *BiTree;

/* 对以p为根的二叉排序树作右旋处理 */
/* 处理之后p指向新的树根结点，即旋转处理之前的左子树的根结点 */
//右旋-顺时针旋转(如LL型就得对根结点做该旋转)
void R_Rotate(BiTree *P)
{
    BiTree L;
    L = (*P)->lchild;         /*  L指向P的左子树根结点 */
    (*P)->lchild = L->rchild; /*  L的右子树挂接为P的左子树 */
    L->rchild = (*P);
    *P = L; /*  P指向新的根结点 */
}

/* 对以P为根的二叉排序树作左旋处理， */
/* 处理之后P指向新的树根结点，即旋转处理之前的右子树的根结点0  */
//左旋-逆时针旋转(如RR型就得对根结点做该旋转)
void L_Rotate(BiTree *P)
{
    BiTree R;
    R = (*P)->rchild;         /* R指向P的右子树根结点 */
    (*P)->rchild = R->lchild; /* R的左子树挂接为P的右子树 */
    R->lchild = (*P);
    *P = R; /* P指向新的根结点 */
}

#define LH +1 /*  左高 */
#define EH 0  /*  等高 */
#define RH -1 /*  右高 */

/*  对以指针T所指结点为根的二叉树作左平衡旋转处理 */
/*  本算法结束时，指针T指向新的根结点 */

void LeftBalance(BiTree *T)
{
    BiTree L, Lr;
    L = (*T)->lchild;
    switch (L->bf)
    {
    case LH:
        L->bf = (*T)->bf = EH;
        R_Rotate(T);
        break;
    case RH:
        Lr = L->rchild;
        switch (Lr->bf)
        {
        case LH:
            (*T)->bf = RH;
            L->bf = EH;
            break;
        case EH:
            (*T)->bf = RH;
            L->bf = EH;
            break;
        case RH:
            (*T)->bf = EH;
            L->bf = LH;
        }
        Lr->bf = EH;
        L_Rotate(&(*T)->lchild);
        R_Rotate(T);
    }
}

void RightBalance(BiTree *T)
{

    BiTree R, Rl;
    R = (*T)->rchild;
    switch (R->bf)
    {
    case RH:
        (*T)->bf = R->bf = EH;
        L_Rotate(T);
        break;
    case EH:
        (*T)->bf = R->bf = EH;
        break;
    case LH:
        Rl = R->lchild;
        switch (Rl->bf)
        {
        case RH:
            (*T)->bf = LH;
            R->bf = EH;
            break;
        case EH:
            (*T)->bf = EH;
            R->bf = EH;
            break;
        case LH:
            (*T)->bf = EH;
            R->bf = RH;
            break;
        }
        Rl->bf = EH;
        R_Rotate(&(*T)->rchild);
        L_Rotate(T);
    }
}

Status InsertAVL(BiTree *T, int e, Status *taller)
{
    if (!(*T))
    {
        *T = (BiTree)malloc(sizeof(BitNode));
        (*T)->data = e;
        (*T)->lchild = (*T)->rchild = NULL;
        (*T)->bf = EH;
        *taller = TRUE;
    }
    else
    {

        if (e == (*T)->data)
        {
            *taller = FALSE;
            return FALSE;
        }
        else if (e < (*T)->data)
        {
            if (!InsertAVL(&(*T)->lchild, e, taller))
            {
                return FALSE;
            }

            if (taller)
            {
                switch ((*T)->bf)
                {
                case LH:
                    LeftBalance(T);
                    taller = FALSE;
                    break;
                case EH:
                    (*T)->bf = LH;
                    taller = TRUE;
                    break;
                case RH:
                    (*T)->bf = EH;
                    taller = FALSE;
                    break;
                }
            }
        }
        else
        {
            if (!InsertAVL(&(*T)->rchild, e, taller))
            {
                return FALSE;
            }

            if (taller)
            {
                switch ((*T)->bf)
                {
                case LH:
                    (*T)->bf = EH;
                    taller = FALSE;
                    break;
                case EH:
                    (*T)->bf = RH;
                    taller = TRUE;
                    break;
                case RH:
                    RightBalance(T);
                    taller = FALSE;
                    break;
                }
            }
        }
    }

    return TRUE;
}

void deleteAVL(BiTree *T, int e, Status taller)
{

}

void InOrderTraverse(BiTree t)
{
    if (t)
    {
        InOrderTraverse(t->lchild);
        printf("%d\n", t->data);
        InOrderTraverse(t->rchild);
    }
}
