/*
Problem Description
某省调查城镇交通状况，得到现有城镇道路统计表，表中列出了每条道路直接连通的城镇。省政府“畅通工程”的目标是使全省任何两个城镇间都可以实现交通（但不一定有直接的道路相连，只要互相间接通过道路可达即可）。问最少还需要建设多少条道路？ 
 

Input
测试输入包含若干测试用例。每个测试用例的第1行给出两个正整数，分别是城镇数目N ( < 1000 )和道路数目M；随后的M行对应M条道路，每行给出一对正整数，分别是该条道路直接连通的两个城镇的编号。为简单起见，城镇从1到N编号。 
注意:两个城市之间可以有多条道路相通,也就是说
3 3
1 2
1 2
2 1
这种输入也是合法的
当N为0时，输入结束，该用例不被处理。 
 

Output
对每个测试用例，在1行里输出最少还需要建设的道路数目。 
 

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
浙大计算机研究生复试上机考试-2005年
 

Recommend
JGShining
 
      开始的时候的确不知道该如何下手，不过有幸看了杭电ACM的PPT（关于并查集的），里面有一句话让我印象深刻，这道题就是赤裸裸的并查集啊！不会做的同学看一下他们的ppt吧！讲得的确很好！我分享一下PPT吧！
下载地址：http://pan.baidu.com/share/link?shareid=197999&uk=1831241436
     有需要的同学好好看看吧！这里就不多说了！
     我的代码就是直接套用的！
     
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


































































































































