Best Cow Line

Description

FJ is about to take his N (1 ≤ N ≤ 2,000) cows to the annual"Farmer of the Year" competition. In this contest every farmer arranges his cows in a line and herds them past the judges.

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
    *这题主要是用贪心，目标主要是从已知的字符串构造出字典序尽可能小的字符串 
    *从字典序性质来看，无论字符串末尾有多大，只要保证前面部分较小就可以咯！ 
    *假设原来字符串为S，目标字符串为T，那么，不断取出S的开头和末尾较小的一个 
    *字符放到T的末尾。上面的没有针对开头与结尾相同，如果，遇到这样动情况，应 
    *该比较下一个字符的大小。如果，下一个字符也相同，那么可以得到下面的算法： 
    *按照字典序比较S和将S反转后的字符串S’ 
    *如果，S较小，那么取出S开头字符，追加到T的末尾 
    *如果，S'较小，那么取出S结尾字符，追加到T的末尾 
    *如果，相同则取出那一个都可以。 
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
        while(start <= end)   // 将从左起和从右起的字符串比较  
        {  
            bool flag = false;  
            for(int i = 0; i <= end - start; i++)  // 字符串的开头与结尾相同，则继续比较下一个  
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