#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
using namespace std;  
  
char str[111];  
int dpa[111],dpb[111];  
  
int main()  
{  
    int t,i,len,flag;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%s",str+1);  
        dpa[0] = 0;  
        dpb[0] = 1;  
        for(i = 1; str[i]; i++)  
        {  
            if(str[i]>='a' && str[i]<='z')  
            {  
                dpa[i] = min(dpa[i-1]+1,dpb[i-1]+2);//����������ֱ�Ӱ���ĸ������������ĸ�ٿ���  
                dpb[i] = min(dpa[i-1]+2,dpb[i-1]+2);//����������Ҫ�Ȱ���ĸ�ٹصƣ���������shift+��ĸ  
            }  
            else if(str[i]>='A' && str[i]<='Z')  
            {  
                dpa[i] = min(dpa[i-1]+2,dpb[i-1]+2);  
                dpb[i] = min(dpa[i-1]+2,dpb[i-1]+1);  
            }  
        }  
        printf("%d\n",min(dpb[i-1]+1,dpa[i-1]));//���Ҫ�صƣ�dpbҪ+1  
    }  
  
    return 0;  
}