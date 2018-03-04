/*
Description
The French author Georges Perec (1936–1982) once wrote a book, La disparition, without the letter 'e'. He was a member of the Oulipo group. A quote from the book:
Tout avait Pair normal, mais tout s’affirmait faux. Tout avait Fair normal, d’abord, puis surgissait l’inhumain, l’affolant. Il aurait voulu savoir où s’articulait l’association qui l’unissait au roman : stir son tapis, assaillant à tout instant son imagination, l’intuition d’un tabou, la vision d’un mal obscur, d’un quoi vacant, d’un non-dit : la vision, l’avision d’un oubli commandant tout, où s’abolissait la raison : tout avait l’air normal mais…
Perec would probably have scored high (or rather, low) in the following contest. People are asked to write a perhaps even meaningful text on some subject with as few occurrences of a given “word” as possible. Our task is to provide the jury with a program that counts these occurrences, in order to obtain a ranking of the competitors. These competitors often write very long texts with nonsense meaning; a sequence of 500,000 consecutive 'T's is not unusual. And they never use spaces.
So we want to quickly find out how often a word, i.e., a given string, occurs in a text. More formally: given the alphabet {'A', 'B', 'C', …, 'Z'} and two finite strings over that alphabet, a word W and a text T, count the number of occurrences of W in T. All the consecutive characters of W must exactly match consecutive characters of T. Occurrences may overlap.
Input
The first line of the input file contains a single number: the number of test cases to follow. Each test case has the following format:
One line with the word W, a string over {'A', 'B', 'C', …, 'Z'}, with 1 ≤ |W| ≤ 10,000 (here |W| denotes the length of the string W).
One line with the text T, a string over {'A', 'B', 'C', …, 'Z'}, with |W| ≤ |T| ≤ 1,000,000.
Output
For every test case in the input file, the output should contain a single number, on a single line: the number of occurrences of the word W in the text T.
Sample Input
3
BAPC
BAPC
AZA
AZAZAZA
VERDI
AVERDXIVYERDIAN
Sample Output
1
3
0
*/
#include <stdio.h>
#include <string.h>

int next[10005];
char str1[1000005],str2[10005];
int cnt;

void get_next(int len2)//生成next数组
{
    int i = 0,j = -1;
    next[0] = -1;
    while (i<len2)
    {
        if(j == -1 || str2[i] == str2[j])//AZAZAZA AZA 
        {
         /*   i++;
              j++;
            if(str2[i]!=str2[j])//	 	j=  0 1 2 3 4 5 6 7 8 9
                next[i] = j;//i      	i=  1 2 3 4 5 6 7 8 9 10
            else
                next[i] = next[j];//next -1 0 
			*/
			next[++i] = ++j;
        }
        else
            j = next[j];
    }
}

void kmp(int len1,int len2)//kmp算法
{
    int i=0,j=0;
    get_next(len2);
    while(i<len1)
    {
        if(j==-1||str1[i]==str2[j])
        {
            ++i;
            ++j;
        }
        else
            j=next[j];
        if(j == len2)
        {
            cnt++;
            j = next[j];
        }
    }
}

int main()
{
    int n;
    int len1,len2;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(str2);
        gets(str1);
        len1 = strlen(str1);
        len2 = strlen(str2);
        cnt = 0;
        kmp(len1,len2);
        printf("%d\n",cnt);
    }
    return 0;
}

