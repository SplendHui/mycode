#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define M 3
#define Status int
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define SUCCESS 1
#define FAILURE 0
#define N 30
typedef int Value;
typedef struct BTNode
{
    int keynum;
    int key[M + 1];
    struct BTNode *ptr[M + 1];
    struct BTNode *p;
} BTNode, *BTree;
typedef struct
{
    BTNode *pt; //int which node
    int i;      // index of value in key[xxx]
    int tag;    // tag = 1 success , 0 failed
} Result;

void NewRoot(BTree *T, int x, BTree r);
int Search(BTree T, Value e);
Result SearchBTree(BTree T, Value e);
BTree NewNode();

/*
    在T节点中搜索，使得
    T->[i] <= e < T->[i+1]
*/
int Search(BTree T, Value e)
{
    if (!T)
    {
        fprintf(stderr, "Search error T is NULL");
        exit(-1);
    }
    int i;

    for (i = 1; i <= T->keynum; i++)
    {
        if (e < T->key[i])
        {
            break;
        }
    }
    return i - 1;
}
/*
    在整个Btree中搜索，值为e元素，如果找到就返回
    一个Result Result的pt为e所在节点指针并且tag = 1
    如果没有找到，pt为e应该插入节点指针，并且tag = 0
*/

Result SearchBTree(BTree T, Value e)
{
    Result r;
    int i, found;
    i = found = 0;
    BTree p = T, q = NULL;
    while (p && !found)
    {
        i = Search(p, e);
        if (i > 0 && p->key[i] == e)
        {
            found = 1;
        }
        else
        {
            q = p;
            p = p->ptr[i];
        }
    }
    if (found)
    {
        r.pt = p;
        r.i = i;
        r.tag = 1;
    }
    else
    {
        r.i = i;
        r.pt = q;
        r.tag = 0;
    }
    return r;
}

Status insert(BTree p, int index, Value e, BTree child)
{

    int i;
    for (i = p->keynum; i >= index + 1; i--)
    {
        p->key[i + 1] = p->key[i];
    }
    p->key[index + 1] = e;
    p->keynum++;
    if (child)
        p->ptr[index + 1] = child;
    return SUCCESS;
}

void splitBTree(BTree *T, int mid, BTree *ap)
{
    int i, index;
    *ap = NewNode();
    (*ap)->ptr[0] = (*T)->ptr[mid];
    for (i = mid + 1, index = 1; i <= M; i++, index++)
    {
        (*ap)->ptr[index] = (*T)->ptr[i];
        (*ap)->key[index] = (*T)->key[i];
        //重新设置父节点
        if ((*ap)->ptr[index])
            (*ap)->ptr[index]->p = (*ap);
    }
    (*ap)->keynum = M - mid;
    (*ap)->p = (*T)->p;
    (*T)->keynum = mid - 1;
}

BTree NewNode()
{
    BTree t = NULL;
    t = (BTree)malloc(sizeof(BTNode));
    if (!t)
    {
        fprintf(stderr, "NewNode malloc error");
        exit(-1);
    }
    for (int i = 0; i < M + 1; i++)
        t->ptr[i] = NULL;
    t->p = NULL;
    return t;
}
Status insertBTree(BTree *T, Value e, BTree q, int i)
{
    int x = e;
    int finished = 0;
    BTree ap;
    ap = NULL;
    while (q && !finished)
    {
        insert(q, i, x, ap);
        if (q->keynum < M)
            finished = TRUE;
        else
        {
            int mid = q->keynum / 2 + 1;
            splitBTree(&q, mid, &ap);
            x = q->key[mid];
            q = q->p;
            if (q)
                i = Search(q, x); //搜索x在该加入在父节点的哪个位置
        }
    }
    if (!finished)
    {
        NewRoot(T, x, ap);
    }
    return SUCCESS;
}
void NewRoot(BTree *T, int midValue, BTree ap)
{
    BTree p = *T;
    *T = NewNode();
    (*T)->keynum = 1;
    (*T)->key[1] = midValue;
    (*T)->ptr[0] = p;
    (*T)->ptr[1] = ap;
    //(*T)->ptr[1]->p = (*T);
    if (ap)
        (*T)->ptr[1]->p = (*T);
    if (p)
        (*T)->ptr[0]->p = (*T);
}

Status insertBTreeValue(BTree *T, Value v)
{
    Result rs = SearchBTree(*T, v);
    if (rs.tag)
    {
        return FAILURE;
    }
    insertBTree(T, v, rs.pt, rs.i);
    return SUCCESS;
}

void levelTraverse(BTree T)
{
    int i;
    BTree s1[1024], s2[1024];
    int front1, front2, rear1, rear2;
    rear1 = rear2 = front1 = front2 = 0;
    s1[rear1++] = T;
    BTree p, q;
    printf("\n----------------------\n");
    while ((rear1 != front1) || (rear2 != front2))
    {
        while (rear1 != front1)
        {
            p = s1[front1++];
            printf("[");
            for (i = 1; i <= p->keynum; i++)
            {
                printf("%d ", p->key[i]);
            }
            printf("]");
            for (i = 0; i <= p->keynum; i++)
            {
                if (p->ptr[i])
                {
                    s2[rear2++] = p->ptr[i];
                }
            }
        }
        printf("\n----------------------\n");
        while (rear2 != front2)
        {
            p = s2[front2++];
            printf("[");
            for (i = 1; i <= p->keynum; i++)
            {
                printf("%d ", p->key[i]);
            }
            printf("]");
            for (i = 0; i <= p->keynum; i++)
            {
                if (p->ptr[i])
                {
                    s1[rear1++] = p->ptr[i];
                }
            }
        }
        printf("\n----------------------\n");
    }
}

int main()
{
    BTree T = NULL;
    int i;
    //while (scanf("%d", &i))
    for (int i = 0; i < 30; i++)
    {
        insertBTreeValue(&T, i);
    }

    levelTraverse(T);
    return 0;
}