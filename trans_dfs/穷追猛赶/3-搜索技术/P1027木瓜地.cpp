/*
���� Description
Bessie��С���ε���Farmer John����أ����߽������ڵ�ũ��ĵء�������һ��ľ�ϣ�ľ
�϶���ţ��˵���ǲ��ɶ�õ���ζ�����ľ������һ�����˹�����ݵ����һ�����ָ��һ��
R��C�е�����(1 <= R <= 40, 1 <= C <= 40)��Bessie���Դ�һ��������һ����X���
Y��ƽ�е�ֱ���ߵ��ڽӵ���һ����Bessie����һ��ʼ���Լ���ľ���ֵ�(1,1)��Ҳ���ǵ�
һ�е�һ�������Ƶؾ׽���ľ�ϡ�

Bessie����������������˫Ͳ��Զ��ȥ��ÿһ���ڽӵĸ�ĵ͒�����ľ�ϵ���Ŀ��Ȼ��������
�����Ǹ������û�б��Ե���ľ�ϵ��ڽӵĸ��ӣ���֤����ĸ���ֻ��һ������

���������ƶ�����������Bessie���ǻ���(R,C)ֹͣȻ��Ե����e��ľ�ϡ�

�������ľ���ֵĴ�С��ÿ�����ľ����F_ij(1 <= F_ij <= 100), Ҫ��Bessieһ������
���ٸ�ľ�ϡ�
 
�����ʽ InputFormat
* ��һ��: �����ո����������R��C.

* ��2��R+1��: ��i+1����C���ո��������������ʾ��i�е�ÿ�����ˮ������Ҳ����F_i1, 
F_i2, ..., F_iC.
 
�����ʽ OutputFormat
* ��һ��: һ����������������ʾ��Bessie�������½�(R,C)��ľ�ϻص�ţ���ʱ���ֹ��
һ����ľ���ֳԵ��˶��ٸ�ľ�ϡ�
 
�������� SampleInput [��������]

3 4
3 3 4 5
4 5 3 2
1 7 4 2

 

������� SampleOutput [��������]

39

 
���ݷ�Χ��ע�� Hint
Bessie������ͼ�����Աߵ���ĸ��˳��Ե�ľ�ϡ�

     (1,1) ---> (1,C)
(1,1) 3a  3   4g  5h  (1,C)
  |   4b  5c  3f  2i    |
(R,1) 1   7d  4e  2j  (R,C)
     (R,1) ---> (R,C)

������39��ľ�ϣ�ʣ��4��û�гԣ�Ҳ����˵����2����������ѣ�ʣ�µĸ��Ӷ���Bessieɨ
�����ˣ���
*/
#include <stdbool.h>
#include <stdio.h>
int main(void)
{
    int i,j,r,c,a[41][41],xi=1,yi=1,maxx=1,maxy=1,max;
    bool b[41][41]={false};
    long sum=0;
    scanf("%d%d\n",&r,&c);
    for (i=1;i<=r;i++)
    { 
        for (j=1;j<=c;j++)
        {
         scanf("%d",&a[i][j]);
         b[i][j]=true;
        }
     }
   
            
   sum=sum+a[1][1];
     b[1][1]=false;
    while (true)
    {
        
        max=-1;
        if ((b[xi][yi+1]==true)&&(a[xi][yi+1]>max))
        {
            maxx=xi;maxy=yi+1;
            max=a[xi][yi+1];
        }
         if ((b[xi][yi-1]==true)&&(a[xi][yi-1]>max))
        {
            maxx=xi;maxy=yi-1;
            max=a[xi][yi-1];
        }
          if ((b[xi+1][yi]==true)&&(a[xi+1][yi]>max))
        {
            maxx=xi+1;maxy=yi;
            max=a[xi+1][yi];
        }
           if ((b[xi-1][yi]==true)&&(a[xi-1][yi]>max))
        {
            maxx=xi-1;maxy=yi;
            max=a[xi-1][yi];
        }
           b[maxx][maxy]=false;
           sum=sum+a[maxx][maxy];
           xi=maxx;yi=maxy;
           if ((maxx==r)&&(maxy==c)) break;
            
    }
    
printf("%d\n",sum);
return 0;
        
        
}