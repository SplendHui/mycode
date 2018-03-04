Description

Farmer John wants to repair a small length of the fence around the pasture. He measures the fence and finds that he needs N (1 ≤ N ≤ 20,000) planks of wood, each having some integer length Li (1 ≤ Li ≤ 50,000) units. He then purchases a single long board just long enough to saw into the N planks (i.e., whose length is the sum of the lengths Li). FJ is ignoring the "kerf", the extra length lost to sawdust when a sawcut is made; you should ignore it, too.

FJ sadly realizes that he doesn't own a saw with which to cut the wood, so he mosies over to Farmer Don's Farm with this long board and politely asks if he may borrow a saw.

Farmer Don, a closet capitalist, doesn't lend FJ a saw but instead offers to charge Farmer John for each of the N-1 cuts in the plank. The charge to cut a piece of wood is exactly equal to its length. Cutting a plank of length 21 costs 21 cents.

Farmer Don then lets Farmer John decide the order and locations to cut the plank. Help Farmer John determine the minimum amount of money he can spend to create the N planks. FJ knows that he can cut the board in various different orders which will result in different charges since the resulting intermediate planks are of different lengths.

Input
Line 1: One integer N, the number of planks
Lines 2..N+1: Each line contains a single integer describing the length of a needed plank

Output
Line 1: One integer: the minimum amount of money he must spend to make N-1 cuts

Sample Input

3
8
5
8

Sample Output

34

Hint
He wants to cut a board of length 21 into pieces of lengths 8, 5, and 8.
The original board measures 8+5+8=21. The first cut will cost 21, and should be used to cut the board into pieces measuring 13 and 8. The second cut will cost 13, and should be used to cut the 13 into 8 and 5. This would cost 21+13=34. If the 21 was cut into 16 and 5 instead, the second cut would cost 16 for a total of 37 (which is more than 34).
 
复制代码

  1 /* 
  2    功能Function Description:     POJ-3253
  3    开发环境Environment:          DEV C++ 4.9.9.1
  4    技术特点Technique:
  5    版本Version:
  6    作者Author:                   可笑痴狂
  7    日期Date:                      20120801
  8    备注Notes:
  9     大致题意：
 10         有一个农夫要把一个木板钜成几块给定长度的小木板，每次锯都要收取一定费用，这个费用就是当前锯的这个木版的长度
 11         给定各个要求的小木板的长度，及小木板的个数n，求最小费用
 12 */
 13 
 14 /*
 15 //代码一：(Wrong answer)   ----思路都不正确，我以为每次只要把最长的先切去所花费用就最短，这种想法是错的
 16 #include<iostream>           //因为每次切不一定就可以切出一块所需的木板，可以先把整体切成两部分再分别对这两部分进行切割
 17 #include<algorithm>
 18 using namespace std;
 19 
 20 int main()
 21 {
 22     int a[20010];
 23     int i,n,ans,sum;
 24     while(cin>>n)
 25     {
 26         for(i=0;i<n;++i)
 27         {
 28             cin>>a[i];
 29             sum+=a[i];
 30         }
 31         sort(a,a+n);
 32         for(i=n-1;i>0;--i)
 33         {
 34             ans+=sum;
 35             sum-=a[i];
 36         }
 37         cout<<ans<<endl;
 38     }
 39     return 0;
 40 }
 41 */
 42 //代码二：
 43 /*
 44 网上的解题思路：
 45 利用Huffman思想，要使总费用最小，那么每次只选取最小长度的两块木板相加，再把这些“和”累加到总费用中即可
 46 本题虽然利用了Huffman思想，但是直接用HuffmanTree做会超时，可以用优先队列做（有待学习）
 47 因为朴素的HuffmanTree思想是：
 48 （1）先把输入的所有元素升序排序，再选取最小的两个元素，把他们的和值累加到总费用
 49 （2）把这两个最小元素出队，他们的和值入队，重新排列所有元素，重复（1），直至队列中元素个数<=1，则累计的费用就是最小费用
 50 
 51   HuffmanTree超时的原因是每次都要重新排序，极度浪费时间，即使是用快排。
 52 
 53 一个优化的处理是：
 54 （1）只在输入全部数据后，进行一次升序排序  (以后不再排序)
 55 （2）队列指针p指向队列第1个元素，然后取出队首的前2个元素，把他们的和值累计到总费用，再把和值sum作为一个新元素插入到队列适当的位置
 56      由于原队首的前2个元素已被取出，因此这两个位置被废弃，我们可以在插入操作时，利用后一个元素位置，先把队列指针p+1，使他指向第2个废弃元素的位置，
 57      然后把sum从第3个位置开始向后逐一与各个元素比较，若大于该元素，则该元素前移一位，否则sum插入当前正在比较元素
 58     （队列中大于等于sum的第一个元素）的前一个位置
 59 （3）以当前p的位置作为新队列的队首，重复上述操作
 60 
 61  
 62 另一种处理方法是利用STL的优先队列，priority_queue，非常方便简单高效，虽然priority_queue的基本理论思想还是上述的优化思想，但是STL可以直接用相关的功能函数实现这些操作，
 63 相对简单
 64 注意priority_queue与qsort的比较规则的返回值的意义刚好相反
 65 */
 66 
 67 #include<iostream>
 68 #include<cstdio>        
 69 #include<algorithm>
 70 using namespace std;
 71 
 72 int main()
 73 {
 74     int *a;
 75     int i,j,n,sum;
 76     __int64 ans;   //不用64位过不了
 77     while(~scanf("%d",&n))
 78     {
 79         a=new int[n];   //每个模板的价值
 80         for(i=0;i<n;++i)
 81             scanf("%d",&a[i]);
 82         sort(a,a+n);
 83         ans=0;
 84         for(i=0;i<n-1;++i)
 85         {
 86             sum=a[i]+a[i+1];
 87             ans+=sum;
 88             for(j=i+2;j<n;++j)
 89             {
 90                 if(sum>a[j])
 91                     a[j-1]=a[j];
 92                 else
 93                 {
 94                     a[j-1]=sum;
 95                     break;
 96                 }
 97             }
 98             if(j==n)   //说明sum比所有元素都大,把sum直接放在最后
 99                 a[j-1]=sum;
100         }
101         printf("%I64d\n",ans);;
102     }
103     return 0;
104 }


1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
	
//代码三：----STL  优先队列----（转）
/*STL 优先队列*/
 
//Memory Time
//512K   47MS
 
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 
//比较规则，最小优先
class cmp
{
public:
    bool operator()(const __int64 a,const __int64 b)const
    {
        return a>b;
    }
};
 
int main(void)
{
    int n;  //需要切割的木板个数
    while(cin>>n)
    {
        priority_queue<__int64,vector<__int64>,cmp>Queue;  //定义优先队列
 
        for(int i=1;i<=n;i++)
        {
            __int64 temp;
            scanf("%I64d",&temp);
            Queue.push(temp);       //输入要求的木板长度（费用）并入队
        }
 
        __int64 mincost=0;   //最小费用
        while(Queue.size()>1)  //当队列中小于等于一个元素时跳出
        {
            __int64 a=Queue.top();  //得到队首元素的值，并使其出队
            Queue.pop();
            __int64 b=Queue.top();  //两次取队首，即得到最小的两个值
            Queue.pop();
 
            Queue.push(a+b);  //入队
            mincost+=a+b;
        }
 
        printf("%I64d\n",mincost);
 
        while(!Queue.empty())  //清空队列
            Queue.pop();
    }
    return 0;
}