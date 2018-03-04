/*
Problem Description
ĳʡ�������ͨ״�����õ����г����·ͳ�Ʊ������г���ÿ����·ֱ����ͨ�ĳ���ʡ��������ͨ���̡���Ŀ����ʹȫʡ�κ���������䶼����ʵ�ֽ�ͨ������һ����ֱ�ӵĵ�·������ֻҪ������ͨ����·�ɴＴ�ɣ��������ٻ���Ҫ�����������·�� 
 

Input
��������������ɲ���������ÿ�����������ĵ�1�и����������������ֱ��ǳ�����ĿN ( < 1000 )�͵�·��ĿM������M�ж�ӦM����·��ÿ�и���һ�����������ֱ��Ǹ�����·ֱ����ͨ����������ı�š�Ϊ������������1��N��š� 
ע��:��������֮������ж�����·��ͨ,Ҳ����˵
3 3
1 2
1 2
2 1
��������Ҳ�ǺϷ���
��NΪ0ʱ������������������������� 
 

Output
��ÿ��������������1����������ٻ���Ҫ����ĵ�·��Ŀ�� 
 

Sample Input
4 2
1 3
4 3
3 3
1 2
1 3
2 3
5 2
1 2
3 5
999 0
0
 

Sample Output
1
0
2
998

Hint
Hint
 
Huge input, scanf is recommended.
 

Source
��������о��������ϻ�����-2005��
 

Recommend
JGShining
 
      ��ʼ��ʱ���ȷ��֪����������֣��������ҿ��˺���ACM��PPT�����ڲ��鼯�ģ���������һ�仰����ӡ����̣��������ǳ�����Ĳ��鼯������������ͬѧ��һ�����ǵ�ppt�ɣ����õ�ȷ�ܺã��ҷ���һ��PPT�ɣ�
���ص�ַ��http://pan.baidu.com/share/link?shareid=197999&uk=1831241436
     ����Ҫ��ͬѧ�úÿ����ɣ�����Ͳ���˵�ˣ�
     �ҵĴ������ֱ�����õģ�
     
*/
#include<stdio.h>  
int bin[1002];  
  
int findx(int x)  
{  
    int r=x;  
    while(bin[r]!=r)  
        r=bin[r];  
    return r;  
}  
void merge(int x,int y)  
{  
    int fx,fy;  
    fx = findx(x);  
    fy = findx(y);  
    if(fx != fy)  
      bin[fx]=fy;  
}  
  
  
int main()  
{  
    int n,m,i,x,y,count;  
    while(scanf("%d",&n),n)  
    {  
        for(i=1;i<=n;i++)  
            bin[i] = i;  
        for(scanf("%d",&m);m>0;m--)  
        {  
            scanf("%d %d",&x,&y);  
            merge(x,y);  
        }  
        for(count=-1, i=1;i<=n;i++)  
            if(bin[i]==i)  
                count++;  
        printf("%d\n",count);  
    }  
	return 0;
} 
/*int bin[1002]
#include<stdio.h>
int find(int x){
	int r;
	r=x;
	if( bin[r] != x )
		r=bin[x];
	return r;
	
}
void merge(int x,int y){
	int fx,fy;
	fx = find(x);
	fy = find(y);
	if( fx != fy )
		bin[fx]=fy;

}
int main()
{
	
	
	int n;
	int x,y;
	while(scanf("%d",&n),n)
	{
		for(i=1;i<=n;i++)
			bin[i]=i;
		for( scanf("%d",&m); m>0; m-- )
			{	scanf("%d %d",&x,&y);
				merge(x,y);
			}
		for(count=-1 ,i=1; i<=n; i++)
			if(bin[i]!= i)
				count++;
			printf("%d\n",count);
	}
	
	return 0;
}


































































































































