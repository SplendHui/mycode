/*
��Ŀ��һЩѧ����һ��ԲȦ�����ǵ���ʦ��Բ�ġ�ÿ��ѧ���������ż�����ǹ�������ʦ��һ�����ڣ�ÿ��ѧ��ͬʱ����������һ��   �ǹ����ұߵ��ھӡ����ĳ��ѧ�������ǹ��ĸ���Ϊ��������ʦ�ͻ��һ���ǹ�������������������ʱ������ѧ�������ǹ�������ͬ������Ҫ�������ʦ���ڵĴ������Լ�ÿ��ѧ�������ǹ�����

���룺����������ݣ���0������ÿ��������nΪѧ��������������n�����������ѧ����ԭʼ�ǹ���������ʱ�뷽��

�����ÿ����Զ������ʦ���ڵĴ������Լ�ÿ��ѧ�������ǹ�����

������ø�����Ϳ�������ˣ���ĿҪ����ѭ������������ɣ��Ҫ�Լ�дһ������...������������Ҳ��ģ������
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
struct node  //���   
{  
    int val;  
    node * next;  
};  
  
bool judge(node *head) //�ж�ÿ��ѧ�����ǹ����Ƿ����   
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
        node* head = new node;   //����ѭ������  
        node * p = head;  
        cin >> v;      
        p -> val = v;      
        int s = v;      //s���ڼ�¼���ǹ���   
        for(int i=0;i<n-1;i++){  
            cin >> v;  
            node *temp = new node;  
            temp -> val = v;  
            p ->next = temp;  
            p = p->next;  
            s += v;  
        }
        p -> next = head;          
          
        int k = s/n;  //kΪ�ǹ�ƽ����������Ϸ�Ƿ����   
        num = 0;   
        while(!judge(head))     
        {          
             p = head->next;  
             int tem = head->val / 2;   
             for(int i=0;i<n;i++)     
             {  
                int save = p->val; //����ԭ�ǹ���   
                p->val = save/2 + tem;    //ע�������ǹ����ұ��ھӣ��ٽ�������ھӵ��ǹ���  
                tem = save/2;   //�����ͳ����ǹ���   
                if(p->val%2 == 1)   
                    p->val += 1;  
                p = p-> next;                      
             }  
            num++;  
        }  
          
        cout<<num<<" "<<head->val<<endl;  //���� 6


    }  
    return 0;  
}