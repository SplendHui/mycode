Best Cow Line

Description

FJ is about to take his N (1 �� N �� 2,000) cows to the annual"Farmer of the Year" competition. In this contest every farmer arranges his cows in a line and herds them past the judges.

The contest organizers adopted a new registration scheme this year: simply register the initial letter of every cow in the order they will appear (i.e., If FJ takes Bessie, Sylvia, and Dora in that order he just registers BSD). After the registration phase ends, every group is judged in increasing lexicographic order according to the string of the initials of the cows' names.

FJ is very busy this year and has to hurry back to his farm, so he wants to be judged as early as possible. He decides to rearrange his cows, who have already lined up, before registering them.

FJ marks a location for a new line of the competing cows. He then proceeds to marshal the cows from the old line to the new one by repeatedly sending either the first or last cow in the (remainder of the) original line to the end of the new line. When he's finished, FJ takes his cows for registration in this new order.

Given the initial order of his cows, determine the least lexicographic string of initials he can make this way.

Input

* Line 1: A single integer: N
* Lines 2..N+1: Line i+1 contains a single initial ('A'..'Z') of the cow in theith position in the original line

Output

The least lexicographic string he can make. Every line (except perhaps the last one) contains the initials of 80 cows ('A'..'Z') in the new line.

Sample Input

6
A
C
D
B
C
B

Sample Output

ABCBCD

Source
USACO 2007 November Silver
[cpp] view plain copy

    /* 
    *������Ҫ����̰�ģ�Ŀ����Ҫ�Ǵ���֪���ַ���������ֵ��򾡿���С���ַ��� 
    *���ֵ������������������ַ���ĩβ�ж��ֻҪ��֤ǰ�沿�ֽ�С�Ϳ��Կ��� 
    *����ԭ���ַ���ΪS��Ŀ���ַ���ΪT����ô������ȡ��S�Ŀ�ͷ��ĩβ��С��һ�� 
    *�ַ��ŵ�T��ĩβ�������û����Կ�ͷ���β��ͬ����������������������Ӧ 
    *�ñȽ���һ���ַ��Ĵ�С���������һ���ַ�Ҳ��ͬ����ô���Եõ�������㷨�� 
    *�����ֵ���Ƚ�S�ͽ�S��ת����ַ���S�� 
    *�����S��С����ôȡ��S��ͷ�ַ���׷�ӵ�T��ĩβ 
    *�����S'��С����ôȡ��S��β�ַ���׷�ӵ�T��ĩβ 
    *�������ͬ��ȡ����һ�������ԡ� 
    * 
    * 
    */  
    #include <iostream>  
    #include <string>  
      
    using namespace std;  
      
    int n;  
    char s[2010];  
      
    void solve()  
    {  
        int start = 0, end = n - 1,count = 0;  
        while(start <= end)   // ��������ʹ�������ַ����Ƚ�  
        {  
            bool flag = false;  
            for(int i = 0; i <= end - start; i++)  // �ַ����Ŀ�ͷ���β��ͬ��������Ƚ���һ��  
            {  
                if(s[start+i] < s[end-i])    
                {  
                    flag = true;  
                    count++;  
                    break;  
                }  
                else if(s[start+i] > s[end-i])  
                {  
                    flag = false;  
                    count++;  
                    break;  
                }  
            }  
            if(flag) cout<<s[start++];  
            else cout<<s[end--];  
            if(count % 80 == 0)  
            cout<<endl;  
        }  
        cout<<endl;  
    }  
    int main(void)  
    {  
        cin>>n;  
        for(int i = 0; i < n; i++)  
        cin>>s[i];  
        solve();  
        return 0;  
    }  