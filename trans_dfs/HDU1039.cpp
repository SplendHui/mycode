#include<cstdio>
#include<cstring>
#include<set>
using namespacestd;
chars[]={'a','e','i','o','u'};
bool is_yuan(charx)//�ж���ĸ�Ƿ���Ԫ����ĸ
{
    for(int i=0;i<5;i++)
        if(x==s[i])
            return true;
    return false;
}
char pwd[30];
int main()
{
    while( scanf("%s",pwd)==1&& strcmp(pwd,"end")!=0 )//����һ������
    {
        bool ok1=false,ok2=true,ok3=true;//ok1��ok2��ok3�ֱ����3�������Ƿ����㣬true������
        int len = strlen(pwd);
        for(int i=0;i<len;i++)//�Ƿ�������һ��Ԫ����ĸ
        {
            if(is_yuan( pwd[i] ))
            {
                ok1=true;
                break;
            }
        }
        if(ok1)
        {
            for(int i=0;i<len-2;i++)//��������3��Ԫ��������3��������һ��
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
            for(int i=0;i<len-1;i++)//����������ͬ��ĸ����ee��oo����һ��
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