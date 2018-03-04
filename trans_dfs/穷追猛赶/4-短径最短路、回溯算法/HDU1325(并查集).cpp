/*
				is it a tree ？    
A tree is a well-known data structure that is either empty (null, void, nothing) or is a set of one or more nodes connected by directed edges between nodes satisfying the following properties.

    There is exactly one node, called the root, to which no directed edges point. 
    Every node except the root has exactly one edge pointing to it. 
    There is a unique sequence of directed edges from the root to each node. 
    For example, consider the illustrations below, in which nodes are represented by circles and edges are represented by lines with arrowheads. The first two of these are trees, but the last is not.


    In this problem you will be given several descriptions of collections of nodes connected by directed edges. For each of these you are to determine if the collection satisfies the definition of a tree or not.

输入：

    The input will consist of a sequence of descriptions (test cases) followed by a pair of negative integers. Each test case will consist of a sequence of edge descriptions followed by a pair of zeroes Each edge description will consist of a pair of integers; the first integer identifies the node from which the edge begins, and the second integer identifies the node to which the edge is directed. Node numbers will always be greater than zero and less than 10000.

输出：

    For each test case display the line "Case k is a tree." or the line "Case k is not a tree.", where k corresponds to the test case number (they are sequentially numbered starting with 1).

样例输入：

    6 8  5 3  5 2  6 4
    5 6  0 0

    8 1  7 3  6 2  8 9  7 5
    7 4  7 8  7 6  0 0

    3 8  6 8  6 4
    5 3  5 6  5 2  0 0
    -1 -1

样例输出：

    Case 1 is a tree.
    Case 2 is a tree.
    Case 3 is not a tree.
*/
#include "stdio.h"  
#include<iostream>  
#define m 100001  
using namespace std;  
int a,b,flag;  
int set[m];  
int v[m];  
int i;  
int main()  
{  
    int count=1;  
    int flag2;  
    while(cin>>a>>b)  
    {  
        if(a<0&&b<0)  
        {break;}  
        flag=0;  
        flag2=0;  
        for(i=1;i<m;i++)  
        {  
            set[i]=0;  
            v[i]=0;  
        }  
        int e=0;  
        while(a&&b)  
        {  
            flag2=1;  
            if(!v[a])  
            {  
                v[a]=1;  
                e++;  
            }  
            if(!v[b])  
            {  
                v[b]=1;  
                e++;  
            }  
            e--;  
            if(set[b]==0)//b is root  
            {  
                set[b]=1;  
            }  
            else  
            {  
                flag=1;  
                break;  
            }  
            cin>>a>>b;  
        }  
        while(a && b) { scanf("%d %d",&a,&b);}   
        if((!flag&&e==1)||flag2==0)  
        printf("Case %d is a tree.\n",count);  
        else  
        printf("Case %d is not a tree.\n",count);   
        count++;  
    }  
    return 0;  
}  