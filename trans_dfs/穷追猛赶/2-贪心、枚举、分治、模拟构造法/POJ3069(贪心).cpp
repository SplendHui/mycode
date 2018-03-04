Description

Saruman the White must lead his army along a straight path from Isengard to Helm’s Deep. To keep track of his forces, Saruman distributes seeing stones, known as palantirs, among the troops. Each palantir has a maximum effective range of R units, and must be carried by some troop in the army (i.e., palantirs are not allowed to “free float” in mid-air). Help Saruman take control of Middle Earth by determining the minimum number of palantirs needed for Saruman to ensure that each of his minions is within R units of some palantir.

Input

The input test file will contain multiple cases. Each test case begins with a single line containing an integer R, the maximum effective range of all palantirs (where 0 ≤ R ≤ 1000), and an integer n, the number of troops in Saruman’s army (where 1 ≤ n ≤ 1000). The next line contains n integers, indicating the positions x1, …, xn of each troop (where 0 ≤ xi ≤ 1000). The end-of-file is marked by a test case with R = n = ?1.

Output

For each test case, print a single integer indicating the minimum number of palantirs needed.

Sample Input

0 3
10 20 20
10 7
70 30 1 7 15 20 50
-1 -1

Sample Output

2
4

Hint

In the first test case, Saruman may place a palantir at positions 10 and 20. Here, note that a single palantir with range 0 can cover both of the troops at position 20.

In the second test case, Saruman can place palantirs at position 7 (covering troops at 1, 7, and 15), position 20 (covering positions 20 and 30), position 50, and position 70. Here, note that palantirs must be distributed among troops and are not allowed to “free float.” Thus, Saruman cannot place a palantir at position 60 to cover the troops at positions 50 and 70.

给出数轴上的一些点代表可放置的位置，给出装置的覆盖范围（覆盖的半径），求出最少用多少个装置能把所有给出的位置全部覆盖..........


贪心问题

从一个未覆盖的位置向前遍历，找到满足距离小于 r 的最右边的点，这个点一定作为一个装置的放置位置，然后从这个位置找到右边的最小的不能覆盖到的位置，这个位置作为下一次的起点...循环下去，直到所有的点都被覆盖到


[cpp] view plain copy
print?在CODE上查看代码片派生到我的代码片

    include<stdio.h>  
    #include<algorithm>  
    using namespace std;  
    int n,r,x[1005];  
    void slove()  
    {  
        int i=0,cnt=0;  
        sort(x,x+n);//先排序   
        while(i<n)  
        {  
            int bg=x[i++];//最左边的没有覆盖的点   
            while(i<n&&x[i]<=bg+r)//被覆盖......   
            {  
                ++i;  
            }  
            int st=x[i-1];//最右边的未被覆盖的区域   
            while(i<n&&x[i]<=st+r)//右边被覆盖区域   
            {  
                ++i;  
            }  
            ++cnt;//计数   
        }  
        printf("%d\n",cnt);  
    }  
    int main()  
    {  
        while(scanf("%d%d",&r,&n),r!=-1&&n!=-1)  
        {  
            for(int i=0;i<n;++i)  
            {  
                scanf("%d",x+i);  
            }  
            slove();  
        }  
        return 0;  
    }  