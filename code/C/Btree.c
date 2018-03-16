#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define M 3
#define Status int
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define SUCCESS 1
#define FAILURE 0
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

void NewRoot(BTree *T, BTree l, int x, BTree r);
int Search(BTree T, Value e);
Result SearchBTree(BTree T, Value e);
BTree NewNode();

int Search(BTree T, Value e)
{
    int i;

    for (i = 1; i <= T->keynum; i++)
    {
        if (e < T->key[i])
            break;
    }
    return i - 1;
}

Result SearchBTree(BTree T, Value e)
{
    Result r;
    int i, found;
    i = found = 0;
    BTree p = T, q = NULL;
    while (p != NULL && !found)
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
    if (!child)
        p->ptr[index + 1] = child;
    return SUCCESS;
}

void splitBTree(BTree *T, int mid, BTree *ap)
{
    int i, index;
    *ap = NewNode();
    /*
    for (i = mid; i <= (*T)->keynum; i++)
    {
        (*ap)->ptr[i - mid] = (*T)->ptr[i];
    }
    for (i = mid + 1; i <= (*T)->keynum; i++)
    {
        (*ap)->key[i - mid] = (*T)->key[i];
    }
    */
    (*ap)->ptr[0] = (*T)->ptr[mid];
    for (i = mid + 1, index = 1; i <= (*T)->keynum; i++, index++)
    {
        (*ap)->ptr[index] = (*T)->ptr[i];
        (*ap)->key[index] = (*T)->key[i];
    }
    (*ap)->keynum = (*T)->keynum - mid;
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
    return t;
}
Status insertBTree(BTree *T, Value e, BTree q, int i)
{
    int x = e;
    int finished = 0;
    BTree p, ap;
    p = ap = NULL;
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
            p = q;
            q = q->p;
            if (q)
                i = Search(q, x); //搜索x在该加入在父节点的哪个位置
        }
    }
    if (!finished)
    {
        NewRoot(T, p, x, ap);
    }
    return SUCCESS;
}
void NewRoot(BTree *T, BTree l, int midValue, BTree r)
{
    *T = NewNode();
    (*T)->keynum = 1;
    (*T)->key[1] = midValue;
    (*T)->ptr[0] = l;
    (*T)->ptr[1] = r;
}

int main()
{
    BTree T = NULL;
    insertBTree(&T, 10, NULL, 0);
    Result rs = SearchBTree(T, 20);
    insertBTree(&T, 20, rs.pt, rs.i);
    rs = SearchBTree(T, 30);
    insertBTree(&T, 30, rs.pt, rs.i);
    printf("keynum = %d key = %d\n", T->keynum, T->key[1]);
    printf("keynum = %d key = %d\n", (T->ptr[0])->keynum, (T->ptr[0])->key[1]);
    printf("keynum = %d key = %d\n", (T->ptr[1])->keynum, (T->ptr[1])->key[1]);
    return 0;
}