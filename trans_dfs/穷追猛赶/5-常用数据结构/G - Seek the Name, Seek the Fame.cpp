/*
Description
The little cat is so famous, that many couples tramp over hill and dale to Byteland, and asked the little cat to give names to their newly-born babies. They seek the name, and at the same time seek the fame. In order to escape from such boring job, the innovative little cat works out an easy but fantastic algorithm: 

Step1. Connect the father's name and the mother's name, to a new string S. 
Step2. Find a proper prefix-suffix string of S (which is not only the prefix, but also the suffix of S). 

Example: Father='ala', Mother='la', we have S = 'ala'+'la' = 'alala'. Potential prefix-suffix strings of S are {'a', 'ala', 'alala'}. Given the string S, could you help the little cat to write a program to calculate the length of possible prefix-suffix strings of S? (He might thank you by giving your baby a name:) 
Input
The input contains a number of test cases. Each test case occupies a single line that contains the string S described above. 

Restrictions: Only lowercase letters may appear in the input. 1 <= Length of S <= 400000. 
Output
For each test case, output a single line with integer numbers in increasing order, denoting the possible length of the new baby's name. 
Sample Input
ababcababababcabab
aaaaa
Sample Output
2 4 9 18
1 2 3 4 5
*/
#include<cstdio>
#include<cstring>
using namespace std;
char s[1000000];
int a[1000000];
int next[1000000];
void getnext()
{
    int i=0,j=-1;
    next[0]=-1;
    while (s[i])
    {
        if (j==-1||s[i]==s[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else j=next[j];
    }
}
int main()
{
    int i,j;
    while (~scanf("%s",&s))
    {
        getnext();
        j=0;
        for (i=strlen(s);i!=0;)
        {
            a[j++]=next[i];
            i=next[i];
        }
        for (i=j-2;i>=0;i--)
         printf("%d ",a[i]);
         printf("%d\n",strlen(s));
    }
}