Description
Farmer John is assigning some of his N (1 <= N <= 25,000) cows to do some cleaning chores around the barn. He always wants to have one cow working on cleaning things up and has divided the day into T shifts (1 <= T <= 1,000,000), the first being shift 1 and the last being shift T. 

Each cow is only available at some interval of times during the day for work on cleaning. Any cow that is selected for cleaning duty will work for the entirety of her interval. 

Your job is to help Farmer John assign some cows to shifts so that (i) every shift has at least one cow assigned to it, and (ii) as few cows as possible are involved in cleaning. If it is not possible to assign a cow to each shift, print -1.

Input
* Line 1: Two space-separated integers: N and T 

* Lines 2..N+1: Each line contains the start and end times of the interval during which a cow can work. A cow starts work at the start time and finishes after the end time.

Output
* Line 1: The minimum number of cows Farmer John needs to hire or -1 if it is not possible to assign a cow to each shift.

Sample Input

3 10
1 7
3 6
6 10

Sample Output

2

Hint
This problem has huge input data,use scanf() instead of cin to read data to avoid time limit exceed. 

INPUT DETAILS: 

There are 3 cows and 10 shifts. Cow #1 can work shifts 1..7, cow #2 can work shifts 3..6, and cow #3 can work shifts 6..10. 

OUTPUT DETAILS: 

By selecting cows #1 and #3, all shifts are covered. There is no way to cover all the shifts using fewer than 2 cows.
���еĻ������1~T������ɣ�ÿͷţ���� ��a[i].begain~a[i].endʱ���ڸɻ�ֽ���Ÿ�ţȥ���������������ٵ�ţȥ��ɡ�

̰������ĵ������ӣ���С���串�����⣺��ÿͷţ��ʼ��ʱ��Ϊ��׼����С����Ϊţ����Ȼ�󣬶���û���ҹ���ţ��ѡȡbeginС��Max��end����Max��������䣨ţ����ֱ��end>=TΪֹ��

���룺

[cpp] view plain copy
��CODE�ϲ鿴����Ƭ�������ҵĴ���Ƭ

    #include <iostream>  
    #include <string.h>  
    #include <stdio.h>  
    #include <algorithm>  
    using namespace std;  
    struct A  
    {  
        int left,right;  
    };  
    int cmp(const A &a,const A &b)  
    {  
        if(a.left==b.left)  
          return a.right<b.right;  
        return a.left <b.left;  
    }  
    int main()  
    {  
        A a[25005],b[25005];  
        int m,n,c;  
        while(~scanf("%d%d",&n,&c))  
        {  
            for(int i=0; i<n; i++)  
            {  
                cin >> a[i].left>>a[i].right;  
                if(a[i].left>a[i].right)  
                    swap(a[i].left,a[i].right);  
            }  
            sort(a,a+n,cmp);  
            /*for(int i=0;i<n;i++) 
              cout << a[i].left <<" "<< a[i].right<<endl;*/  
            int max=0;  
            int sum=0;  
            int top=0;  
            while(max<c)  
            {  
                int min=max+1;  
                for(int i=top; i<n; i++)  
                    if(a[i].left<=min&&a[i].right>=min)  
                           max=max>a[i].right?max:a[i].right;  
                    else if(a[i].left>min)  
                    {  
                        top=i;  
                        break;  
                    }  
                if(min>max)  
                   break;  
                else  
                   sum++;  
            }  
            if(max>=c)  
             cout << sum <<endl;  
            else  
             cout << "-1\n";  
        }  
        return 0;  
    }  