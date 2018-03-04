/*
题目：一些学生成一个圆圈，他们的老师在圆心。每个学生最初具有偶数个糖果。当老师吹一个口哨，每名学生同时给出了他的一半   糖果到右边的邻居。如果某个学生最终糖果的个数为奇数，老师就会给一块糖果给他。本场比赛结束时，所有学生都有糖果件数相同。你需要计算出老师吹哨的次数，以及每个学生最后的糖果数。

输入：多组测试数据，以0结束。每组先输入n为学生个数，接下来n行依次输入该学生的原始糖果数，沿逆时针方向。

输出：每组测试都输出老师吹哨的次数，以及每个学生最后的糖果数。

这道题用个数组就可以秒掉了，题目要求用循环链表真是忧桑，要自己写一遍链表...不过，用数组也是模拟链表。
intput
6
36
2
2
2
2
2
11
22
20
18
16
14
12
10
8
6
4
2
4
2
4
6
8
0
output
15 14
17 22
4 8
*/
#include <iostream>  
using namespace std;  
int n, num,v;  
struct node  //结点   
{  
    int val;  
    node * next;  
};  
  
bool judge(node *head) //判断每个学生的糖果数是否相等   
{  
    node *p = head;  
    for(int i=0;i<n;i++)  
    {  
        if(p->val!=p->next->val)   
          return false;  
        p = p-> next;  
    }  
    return true;  
}  
  
int main()  
{  
    while(cin>>n,n)  
    {  
        node* head = new node;   //创建循环链表  
        node * p = head;  
        cin >> v;      
        p -> val = v;      
        int s = v;      //s用于记录总糖果数   
        for(int i=0;i<n-1;i++){  
            cin >> v;  
            node *temp = new node;  
            temp -> val = v;  
            p ->next = temp;  
            p = p->next;  
            s += v;  
        }
        p -> next = head;          
          
        int k = s/n;  //k为糖果平均数，来游戏是否结束   
        num = 0;   
        while(!judge(head))     
        {          
             p = head->next;  
             int tem = head->val / 2;   
             for(int i=0;i<n;i++)     
             {  
                int save = p->val; //保存原糖果数   
                p->val = save/2 + tem;    //注意是先糖果给右边邻居，再接受左边邻居的糖果。  
                tem = save/2;   //保存送出的糖果数   
                if(p->val%2 == 1)   
                    p->val += 1;  
                p = p-> next;                      
             }  
            num++;  
        }  
          
        cout<<num<<" "<<head->val<<endl;  //样例 6


    }  
    return 0;  
}