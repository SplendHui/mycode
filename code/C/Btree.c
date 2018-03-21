#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define M 5
#define N 10
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

BTree NewNode();
int whichSon(BTree p);
int Search(BTree T, Value e);
Result searchBTreeMin(BTree T);
int deleteKey(BTree p, Value e);
int deleteChild(BTree p, int index);
Result SearchBTree(BTree T, Value e);
void NewRoot(BTree *T, int x, BTree r);
void deleteLeafKey(BTree *T, BTree p, int index);
int mergeTwoChild(BTree left, int mid, BTree right);
int insert(BTree p, int index, Value e, BTree child);
void borrowFromLeftBother(BTree left, int mid, BTree right);
void borrowFromRightBother(BTree left, int mid, BTree right);

int mergeTwoChild(BTree left, int mid, BTree right)
{
    BTree father = left->p;
    int downValue = father->key[mid];
    insert(left, left->keynum, downValue, right->ptr[0]);
    for (int i = 1; i <= right->keynum; i++)
        insert(left, left->keynum, right->key[i], right->ptr[i]);
    deleteChild(father, mid);
    deleteKey(father, mid);
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

int insert(BTree p, int index, Value e, BTree child)
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
    return 1;
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
        fprintf(stderr, "NewNode malloc error\n");
        exit(-1);
    }
    for (int i = 0; i < M + 1; i++)
        t->ptr[i] = NULL;
    t->p = NULL;
    return t;
}

int insertBTree(BTree *T, Value e, BTree q, int i)
{
    int x = e;
    int finished = 0;
    BTree ap;
    ap = NULL;
    while (q && !finished)
    {
        insert(q, i, x, ap);
        if (q->keynum < M)
            finished = 1;
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
    return 1;
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

int insertBTreeValue(BTree *T, Value v)
{
    Result rs = SearchBTree(*T, v);
    if (rs.tag)
    {
        printf("%d exits\n", v);
        return -1;
    }
    insertBTree(T, v, rs.pt, rs.i);
    return 1;
}

void levelTraverse(BTree T)
{
    if (T == NULL)
    {
        printf("T is NULL\n");
        return;
    }
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
        BTree father = p->p;
        int pos = whichSon(p);
        deleteKey(p, index);
        if ((i + 1) <= father->keynum && father->ptr[pos + 1] && (father->ptr[pos + 1])->keynum >= (M + 1) / 2)
        { //右兄弟存在，向右兄弟借
            printf("borrow from right\n");
            borrowFromRightBother(father->ptr[pos], pos + 1, father->ptr[pos + 1]);
        }
        else if ((pos - 1) >= 0 && father->ptr[pos - 1] && (father->ptr[pos - 1])->keynum >= (M + 1) / 2)
        { //左兄弟存在，且大于一半，向他借。
            printf("borrow from left\n");
            borrowFromLeftBother(father->ptr[pos - 1], pos, father->ptr[pos]);
        }
        else
        {                       //左兄弟不存在或者有兄弟不存在，就算存在也帮不了。
            if ((pos - 1) >= 0) //左兄弟存在；与左兄弟合并.
                mergeTwoChild(father->ptr[pos - 1], pos, father->ptr[pos]);
            else if ((pos + 1) <= father->keynum) //右兄弟存在，与右兄弟合并。
                mergeTwoChild(father->ptr[pos], pos + 1, father->ptr[pos + 1]);
            while (father->keynum < ((M + 1) / 2 - 1) && father->p != NULL)
            {
                BTree son = father;
                pos = whichSon(son);
                father = father->p;
                if ((pos + 1) <= father->keynum && (father->ptr[pos + 1]->keynum >= (M + 1) / 2)) //右兄弟
                {
                    borrowFromRightBother(father->ptr[pos], pos + 1, father->ptr[pos + 1]);
                    return;
                }
                else if ((pos - 1) >= 0 && (father->ptr[pos - 1]->keynum >= (M + 1) / 2)) // 左兄弟
                {
                    borrowFromLeftBother(father->ptr[pos - 1], pos, father->ptr[pos]);
                    return;
                }
                else
                {
                    if ((pos + 1) <= father->keynum)
                        mergeTwoChild(son, pos + 1, father->ptr[pos + 1]);
                    else
                        mergeTwoChild(father->ptr[pos - 1], pos, son);
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

void borrowFromRightBother(BTree left, int mid, BTree right)
{
    BTree father = left->p;
    int downValue = father->key[mid];
    insert(left, left->keynum, downValue, right->ptr[0]);
    father->key[mid] = right->key[1];
    deleteChild(right, 0);
    deleteKey(right, 1);
}

void borrowFromLeftBother(BTree left, int mid, BTree right)
{
    BTree father = left->p;
    int downValue = father->key[mid];
    for (int i = right->keynum; i >= 0; i--)
        right->ptr[i + 1] = right->ptr[i];
    insert(right, 0, downValue, NULL);
    right->ptr[0] = left->ptr[left->keynum];
    father->key[mid] = left->key[left->keynum];
    deleteChild(left, left->keynum);
    deleteKey(left, left->keynum);
}

int deleteBTreeKey(BTree *T, Value v)
{
    if ((*T) == NULL)
    {
        fprintf(stderr, "Tree is Empty\n");
        return 0;
    }
    Result r = SearchBTree(*T, v);
    if (r.pt->ptr[0] == NULL && r.tag)
        deleteLeafKey(T, r.pt, r.i);
    else if (r.pt->ptr[0] != NULL && r.tag)
    {
        Result min = searchBTreeMin(r.pt->ptr[r.i]);
        r.pt->key[r.i] = min.pt->key[min.i];
        deleteLeafKey(T, min.pt, min.i);
    }
    else
    {
        printf("no found\n");
        return 0;
    }
    return 1;
}

Result searchBTreeMin(BTree T)
{
    int min;
    Result rs;
    BTree pre = NULL;
    while (T)
    {
        pre = T;
        T = T->ptr[0];
    }
    rs.pt = pre;
    rs.tag = rs.i = 1;
    return rs;
}

int main()
{
    BTree T = NULL;
    int i;
    srandom(time(NULL));
    for (int i = 0; i < N; i++)
    {
        insertBTreeValue(&T, i);
    }

    levelTraverse(T);
    while (scanf("%d", &i) == 1)
    {
        deleteBTreeKey(&T, i);
        levelTraverse(T);
    }
    levelTraverse(T);
    return 0;
}