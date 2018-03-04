#include<cstdio>
#include<cstring>
#include<set>
using namespacestd;
chars[]={'a','e','i','o','u'};
bool is_yuan(charx)//判断字母是否是元音字母
{
    for(int i=0;i<5;i++)
        if(x==s[i])
            return true;
    return false;
}
char pwd[30];
int main()
{
    while( scanf("%s",pwd)==1&& strcmp(pwd,"end")!=0 )//读入一个密码
    {
        bool ok1=false,ok2=true,ok3=true;//ok1，ok2，ok3分别代表3个条件是否满足，true表满足
        int len = strlen(pwd);
        for(int i=0;i<len;i++)//是否有至少一个元音字母
        {
            if(is_yuan( pwd[i] ))
            {
                ok1=true;
                break;
            }
        }
        if(ok1)
        {
            for(int i=0;i<len-2;i++)//不能连续3个元音或连续3个辅音在一起
            {
                if( is_yuan(pwd[i])&&is_yuan(pwd[i+1])&&is_yuan(pwd[i+2]))
                {
                    ok2=false;
                    break;
                }
                else if( !is_yuan(pwd[i])&& !is_yuan(pwd[i+1])&& !is_yuan(pwd[i+2]))
                {
                    ok2=false;
                    break;
                }
            }
        }
        if(ok1&&ok2)
        {
            for(int i=0;i<len-1;i++)//不能两个相同字母（除ee，oo）在一起
            {
               if(pwd[i]==pwd[i+1]&&pwd[i]!='e'&&pwd[i]!='o')
                {
                    ok3=false;
                    break;
                }
            }
        }
        printf("<%s> is",pwd);
       if(ok1&&ok2&&ok3)printf(" acceptable.\n");
        else printf(" notacceptable.\n");
    }
    return 0;
}