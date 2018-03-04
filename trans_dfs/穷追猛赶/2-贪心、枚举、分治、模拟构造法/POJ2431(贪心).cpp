Description
A group of cows grabbed a truck and ventured on an expedition deep into the jungle. Being rather poor drivers, the cows unfortunately managed to run over a rock and puncture the truck's fuel tank. The truck now leaks one unit of fuel every unit of distance it travels. 

To repair the truck, the cows need to drive to the nearest town (no more than 1,000,000 units distant) down a long, winding road. On this road, between the town and the current location of the truck, there are N (1 <= N <= 10,000) fuel stops where the cows can stop to acquire additional fuel (1..100 units at each stop). 

The jungle is a dangerous place for humans and is especially dangerous for cows. Therefore, the cows want to make the minimum possible number of stops for fuel on the way to the town. Fortunately, the capacity of the fuel tank on their truck is so large that there is effectively no limit to the amount of fuel it can hold. The truck is currently L units away from the town and has P units of fuel (1 <= P <= 1,000,000). 

Determine the minimum number of stops needed to reach the town, or if the cows cannot reach the town at all. 

Input
* Line 1: A single integer, N 

* Lines 2..N+1: Each line contains two space-separated integers describing a fuel stop: The first integer is the distance from the town to the stop; the second is the amount of fuel available at that stop. 

* Line N+2: Two space-separated integers, L and P

Output
* Line 1: A single integer giving the minimum number of fuel stops necessary to reach the town. If it is not possible to reach the town, output -1.

Sample Input

4
4 4
5 2
11 5
15 10
25 10

Sample Output

2

Hint
INPUT DETAILS: 

The truck is 25 units away from the town; the truck has 10 units of fuel. Along the road, there are 4 fuel stops at distances 4, 5, 11, and 15 from the town (so these are initially at distances 21, 20, 14, and 10 from the truck). These fuel stops can supply up to 4, 2, 5, and 10 units of fuel, respectively. 

OUTPUT DETAILS: 

Drive 10 units, stop to acquire 10 more units of fuel, drive 4 more units, stop to acquire 5 more units of fuel, then drive to the town.

���⣺һ������Ҫ��ʻL��λ���롣�ʼʱ����������P��λ���ͣ�ÿ��ǰ��ʻ1��λ��������1��λ���͡������;�г��ϵ����ͺľ����������޷�����ǰ�У����޷������յ㡣;�й���N������վ������վ�ṩ���������ޣ��������������޴����ۼӶ����Ͷ�û���⡣����ÿ������վ�����յ�ľ�����ܹ��ṩ���������ʿ�������㵽�յ�����Ҫ�Ӽ����ͣ�������ܵ����յ㣬���-1��
����������N�Ƚϴ�Ӧ����һ����Ч�Ľⷨ����΢ת��һ��˼����ʽ���ڿ��������յ��;�У�ֻ���ڼ���վ�ſ��Լ��͡����ǣ������Ϊ���ڵ������վiʱ���ͻ����һ����֮����κ�ʱ�򶼿��Լ�Bi��λ���͵�Ȩ�������ڽ��������Ҳ��һ���ġ�����֮����Ҫ����ʱ������Ϊ����֮ǰ�����ļ���վ�ӵ��;Ϳ����ˡ���Ϊϣ�����ʹ����������٣����Ե�ȼ��Ϊ0��֮���ټ�������õ�ѡ�񡣻���̰�ĵ�˼�룬��ȼ��Ϊ0ʱ��ѡ���ܼ��������ļ���վ�����Կ�����һ�����ȶ��������澭���ļ���վ������������Ҫ����ʱ��ȡ�������е����Ԫ�ؼ��ɡ�

�ο����룺
[cpp] view plain copy
��CODE�ϲ鿴����Ƭ�������ҵĴ���Ƭ

    #include<stdio.h>  
    #include<queue>  
    #include<algorithm>  
    using namespace std;  
    struct stop  
    {  
        int x;  
        int v;  
    }s[10010];  
    bool comp(stop s1, stop s2)  
    {  
        return s1.x < s2.x;  
    }  
    int main()  
    {  
        int n, i, L, P;  
        while(~scanf("%d",&n))  
        {  
            for(i = 0; i < n; i++)  
                scanf("%d%d",&s[i].x, &s[i].v);  
            scanf("%d%d",&L,&P);  
            for(i = 0; i < n; i++)  
                s[i].x = L - s[i].x; //ת��Ϊ����վ�����ľ���  
            s[n].x = L;  
            s[n++].v = 0; //���յ�Ҳ��Ϊ�Ǽ���վ  
            sort(s, s+n, comp);  
            priority_queue<int, vector<int>, less<int> > Q; //ֵ�������  
            int rest = P; //ʣ������  
            int ans = 0; //���ʹ���  
            int pos = 0; //�������ڵ���һ��λ��  
            for(i = 0; i < n; i++)  
            {  
                int dis = s[i].x - pos; //���ϸ�����վ����λ��Ҫ��ʻ�ľ���  
                while(rest - dis < 0) //ʣ���������ܵ����λ��  
                {  
                    if(Q.empty()) //û���Ϳɼ�  
                    {  
                        ans = -1;  
                        break;  
                    }  
                    rest += Q.top();  
                    Q.pop();  
                    ans++;  
                }  
                if(ans == -1)  
                    break;  
                rest = rest - dis;  
                pos = s[i].x;  
                Q.push(s[i].v);  
            }  
            printf("%d\n",ans);  
        }  
        return 0;  
    }  