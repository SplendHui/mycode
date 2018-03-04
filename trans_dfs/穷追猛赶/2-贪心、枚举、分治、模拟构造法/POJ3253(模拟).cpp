Description

Farmer John wants to repair a small length of the fence around the pasture. He measures the fence and finds that he needs N (1 �� N �� 20,000) planks of wood, each having some integer length Li (1 �� Li �� 50,000) units. He then purchases a single long board just long enough to saw into the N planks (i.e., whose length is the sum of the lengths Li). FJ is ignoring the "kerf", the extra length lost to sawdust when a sawcut is made; you should ignore it, too.

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
 
���ƴ���

  1 /* 
  2    ����Function Description:     POJ-3253
  3    ��������Environment:          DEV C++ 4.9.9.1
  4    �����ص�Technique:
  5    �汾Version:
  6    ����Author:                   ��Ц�տ�
  7    ����Date:                      20120801
  8    ��עNotes:
  9     �������⣺
 10         ��һ��ũ��Ҫ��һ��ľ���ҳɼ���������ȵ�Сľ�壬ÿ�ξⶼҪ��ȡһ�����ã�������þ��ǵ�ǰ������ľ��ĳ���
 11         ��������Ҫ���Сľ��ĳ��ȣ���Сľ��ĸ���n������С����
 12 */
 13 
 14 /*
 15 //����һ��(Wrong answer)   ----˼·������ȷ������Ϊÿ��ֻҪ���������ȥ�������þ���̣������뷨�Ǵ��
 16 #include<iostream>           //��Ϊÿ���в�һ���Ϳ����г�һ�������ľ�壬�����Ȱ������г��������ٷֱ���������ֽ����и�
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
 42 //�������
 43 /*
 44 ���ϵĽ���˼·��
 45 ����Huffman˼�룬Ҫʹ�ܷ�����С����ôÿ��ֻѡȡ��С���ȵ�����ľ����ӣ��ٰ���Щ���͡��ۼӵ��ܷ����м���
 46 ������Ȼ������Huffman˼�룬����ֱ����HuffmanTree���ᳬʱ�����������ȶ��������д�ѧϰ��
 47 ��Ϊ���ص�HuffmanTree˼���ǣ�
 48 ��1���Ȱ����������Ԫ������������ѡȡ��С������Ԫ�أ������ǵĺ�ֵ�ۼӵ��ܷ���
 49 ��2������������СԪ�س��ӣ����ǵĺ�ֵ��ӣ�������������Ԫ�أ��ظ���1����ֱ��������Ԫ�ظ���<=1�����ۼƵķ��þ�����С����
 50 
 51   HuffmanTree��ʱ��ԭ����ÿ�ζ�Ҫ�������򣬼����˷�ʱ�䣬��ʹ���ÿ��š�
 52 
 53 һ���Ż��Ĵ����ǣ�
 54 ��1��ֻ������ȫ�����ݺ󣬽���һ����������  (�Ժ�������)
 55 ��2������ָ��pָ����е�1��Ԫ�أ�Ȼ��ȡ�����׵�ǰ2��Ԫ�أ������ǵĺ�ֵ�ۼƵ��ܷ��ã��ٰѺ�ֵsum��Ϊһ����Ԫ�ز��뵽�����ʵ���λ��
 56      ����ԭ���׵�ǰ2��Ԫ���ѱ�ȡ�������������λ�ñ����������ǿ����ڲ������ʱ�����ú�һ��Ԫ��λ�ã��ȰѶ���ָ��p+1��ʹ��ָ���2������Ԫ�ص�λ�ã�
 57      Ȼ���sum�ӵ�3��λ�ÿ�ʼ�����һ�����Ԫ�رȽϣ������ڸ�Ԫ�أ����Ԫ��ǰ��һλ������sum���뵱ǰ���ڱȽ�Ԫ��
 58     �������д��ڵ���sum�ĵ�һ��Ԫ�أ���ǰһ��λ��
 59 ��3���Ե�ǰp��λ����Ϊ�¶��еĶ��ף��ظ���������
 60 
 61  
 62 ��һ�ִ�����������STL�����ȶ��У�priority_queue���ǳ�����򵥸�Ч����Ȼpriority_queue�Ļ�������˼�뻹���������Ż�˼�룬����STL����ֱ������صĹ��ܺ���ʵ����Щ������
 63 ��Լ�
 64 ע��priority_queue��qsort�ıȽϹ���ķ���ֵ������պ��෴
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
 76     __int64 ans;   //����64λ������
 77     while(~scanf("%d",&n))
 78     {
 79         a=new int[n];   //ÿ��ģ��ļ�ֵ
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
 98             if(j==n)   //˵��sum������Ԫ�ض���,��sumֱ�ӷ������
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
	
//��������----STL  ���ȶ���----��ת��
/*STL ���ȶ���*/
 
//Memory Time
//512K   47MS
 
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 
//�ȽϹ�����С����
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
    int n;  //��Ҫ�и��ľ�����
    while(cin>>n)
    {
        priority_queue<__int64,vector<__int64>,cmp>Queue;  //�������ȶ���
 
        for(int i=1;i<=n;i++)
        {
            __int64 temp;
            scanf("%I64d",&temp);
            Queue.push(temp);       //����Ҫ���ľ�峤�ȣ����ã������
        }
 
        __int64 mincost=0;   //��С����
        while(Queue.size()>1)  //��������С�ڵ���һ��Ԫ��ʱ����
        {
            __int64 a=Queue.top();  //�õ�����Ԫ�ص�ֵ����ʹ�����
            Queue.pop();
            __int64 b=Queue.top();  //����ȡ���ף����õ���С������ֵ
            Queue.pop();
 
            Queue.push(a+b);  //���
            mincost+=a+b;
        }
 
        printf("%I64d\n",mincost);
 
        while(!Queue.empty())  //��ն���
            Queue.pop();
    }
    return 0;
}