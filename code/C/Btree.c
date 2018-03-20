#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define M 5
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
int deleteKey(BTree p, Value e);
int borrow(BTree p, int flag); //向左边还是右边借。
int deleteChild(BTree p, int index);
int whichSon(BTree p);
int mergeTwoChild(BTree p, int pos, int flag);
Status insert(BTree p, int index, Value e, BTree child);
void deleteLeafKey(BTree *T, BTree p, int index);

void adjustFather(BTree *T, BTree p)
{
    BTree father = p->p;
    int i, pos;
    if (p->keynum >= (M + 1) / 2)
        return;
    else
    {
    }
}

int mergeTwoChild(BTree p, int pos, int flag)
{
    BTree father = p->p;
    //flag = 0, p和左兄弟合并
    int i;
    if (flag == 0)
    {
        int left = pos - 1;
        BTree leftBother = father->ptr[left];
        int downValue = father->key[pos];
        //        printf("down value = %d\n", downValue);
        insert(leftBother, leftBother->keynum, downValue, p->ptr[0]);
        for (i = 1; i <= p->keynum; i++)
            insert(leftBother, leftBother->keynum, p->key[i], p->ptr[i]);
        deleteChild(father, pos);
        deleteKey(father, pos);
    }
    else if (flag == 1)
    {
        int right = pos + 1;
        int downValue = father->key[pos + 1];
        BTree rightBother = father->ptr[right];
        insert(p, p->keynum, downValue, rightBother->ptr[0]);
        for (i = 1; i <= rightBother->keynum; i++)
            insert(p, p->keynum, rightBother->key[i], rightBother->ptr[i]);
        deleteChild(father, right);
        deleteKey(father, right);
    }
    else
    {
        fprintf(stderr, "mergeTwoChild error\n");
        exit(-1);
    }
    return 1;
}

int deleteChild(BTree p, int index)
{
    int i;
    free(p->ptr[index]);
    for (i = index; i < p->keynum; i++)
        p->ptr[i] = p->ptr[i + 1];
    p->ptr[i] = NULL;
    return 1;
}

int whichSon(BTree p)
{
    BTree father = p->p;
    int i;
    for (i = 0; i <= father->keynum + 1; i++)
    {
        if (father->ptr[i] == p)
            return i;
    }
    fprintf(stderr, "whichSon error\n");
    exit(-1);
}

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
    {
        p->ptr[index + 1] = child;
        child->p = p;
    }
    return SUCCESS;
}

void splitBTree(BTree *T, int mid, BTree *ap)
{
    int i, index;
    *ap = NewNode();
    (*ap)->ptr[0] = (*T)->ptr[mid];
    //叶子节点的分裂的话，ptr就可能是NULL
    if ((*ap)->ptr[0])
        ((*ap)->ptr[0])->p = (*ap);
    (*T)->ptr[mid] = NULL;
    for (i = mid + 1, index = 1; i <= M; i++, index++)
    {
        (*ap)->ptr[index] = (*T)->ptr[i];
        (*T)->ptr[i] = NULL;
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
        printf("%d exits\n", v);
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

void deleteLeafKey(BTree *T, BTree p, int index)
{
    int i;
    if (p->keynum >= (M + 1) / 2 || p->p == NULL)
    {                        //如果这个节点的keynum过半，可以直接删除.
        deleteKey(p, index); //比如有30 37 删除30后37应该左移。
        if (p->keynum == 0)
            *T = NULL;
    } //如果少于一半，而且邻居节点大于一半，那就借,或者合并。
    else if (p->keynum < (M + 1) / 2)
    {
        //找到这个是父亲节点的哪个一个节点
        BTree p1 = p->p;
        i = whichSon(p);
        deleteKey(p, index);
        // p1 是要删除元素所在节点的父节点
        //找到它父亲的哪一个子节点.然后才能找到兄弟节点。
        //M = 3 keynum = 2可以借，  M= 5 keynum >= 3 能借。
        if ((i + 1) <= p1->keynum && p1->ptr[i + 1] && (p1->ptr[i + 1])->keynum >= (M + 1) / 2)
        { //右兄弟存在，向右兄弟借
            printf("borrow from right\n");
            int bValue = borrow(p1->ptr[i + 1], 1);
            insert(p, p->keynum, p1->key[i + 1], NULL); //父节点的值放入左节点,也就是被删除节
            p1->key[i + 1] = bValue;                    //把借来的值放到父节点
        }
        else if ((i - 1) >= 0 && p1->ptr[i - 1] && (p1->ptr[i - 1])->keynum >= (M + 1) / 2)
        { //左兄弟存在，且大于一半，向他借。
            printf("borrow from left\n");
            int bValue = borrow(p1->ptr[i - 1], 0);
            insert(p, 0, p1->key[i], NULL); //父节点的值放入右节点,也就是被删除节点
            p1->key[i] = bValue;            //把借来的值放到父节点
        }
        else
        { //左兄弟不存在或者有兄弟不存在，就算存在也帮不了。
            printf("merge \n");
            //i 是p节点在父亲节点的索引
            if ((i - 1) >= 0) //左兄弟存在；与左兄弟合并.
            {
                //父节点下降一个
                mergeTwoChild(p, i, 0);
            }
            else if ((i + 1) <= p1->keynum) //右兄弟存在，与右兄弟合并。
            {
                //下降一个
                mergeTwoChild(p, i, 1);
            }
            else
            {
                fprintf(stderr, "error\n");
                exit(-1);
            }
            BTree father = p->p;
            BTree son;
            int pos;
            while (father->keynum < ((M + 1) / 2 - 1) && father->p != NULL)
            {
                printf("while \n");
                son = father;
                pos = whichSon(son);
                father = father->p;
                if ((pos + 1) <= father->keynum && father->keynum >= (M + 1) / 2) //右兄弟
                {
                    if (father->ptr[pos + 1]->keynum >= (M + 1) / 2)
                    {
                        int downValue = father->key[pos + 1];
                        BTree rightBother = father->ptr[pos + 1];
                        father->key[pos + 1] = rightBother->key[1];
                        insert(son, son->keynum - 1, downValue, rightBother->ptr[0]);
                        deleteChild(rightBother, 0);
                        deleteKey(rightBother, 1);
                        return;
                    }
                }
                else if ((pos - 1) >= 0) // 左兄弟
                {
                    if (father->ptr[pos - 1]->keynum >= (M + 1) / 2)
                    {
                        int downValue = father->key[pos];
                        BTree leftBother = father->ptr[pos - 1];
                        father->key[pos] = leftBother->key[leftBother->keynum];
                        insert(son, 0, downValue, NULL);
                        for (int i = son->keynum - 2; i >= 0; i--)
                            son->ptr[i + 1] = son->ptr[i];
                        son->ptr[0] = leftBother->ptr[leftBother->keynum];
                        deleteChild(leftBother, leftBother->keynum);
                        deleteKey(leftBother, leftBother->keynum);
                        return;
                    }
                }
                else
                {
                    if ((pos + 1) <= father->keynum)
                    {
                        mergeTwoChild(son, pos, 1);
                    }
                    else
                    {
                        mergeTwoChild(son, pos, 0);
                    }
                }
            }
            if (father->p == NULL && !father->keynum)
            {
                free(father);
                (*T) = father->ptr[0];
                (*T)->p = NULL;
            }
        }
    }
}

int deleteKey(BTree p, int index)
{
    int i;
    for (i = index; i < p->keynum; i++)
        p->key[i] = p->key[i + 1];
    p->keynum--;
    return 1;
}

int borrow(BTree p, int flag) //向左边还是右边借。
{
    //flag = 0, 左边, 1 右边
    int i, x;
    if (flag)
    {
        //向右边借，借小的
        x = p->key[1]; //借一个最小的，
        for (i = 1; i < p->keynum; i++)
        {
            p->key[i] = p->key[i + 1];
        }
        p->keynum--;
    }
    else
    {
        x = p->key[p->keynum];
        p->keynum--;
        //向左边借，借最大的。
    }
    return x;
}

int main()
{
    BTree T = NULL;
    int i;
    //while (scanf("%d", &i))
    srandom(time(NULL));
    for (int i = 0; i < 6; i++)
    {
        insertBTreeValue(&T, i);
    }

    levelTraverse(T);
    while (scanf("%d", &i) == 1)
    {
        Result r = SearchBTree(T, i);
        printf("%d %d\n", r.i, r.pt->key[1]);
        deleteLeafKey(&T, r.pt, r.i);
        levelTraverse(T);
    }

    //printf("left child %d\n", r.pt->ptr[0]->key[1]);
    /*
    r = SearchBTree(T, 16);
    printf("16 father is %d\n", r.pt->p->key[1]);
    levelTraverse(T);
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    deleteBtreeKey(&T, r.pt, 16);
     **/
    levelTraverse(T);
    return 0;
}