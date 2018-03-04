/*
��Ŀ���� Description

    ��N*N���Թ��ڣ���#��Ϊǽ����.��Ϊ·����s��Ϊ��㣬��e��Ϊ�յ㣬һ��4����������ߡ������Ͻǣ�(0,0)��s����λ�ô��ߵ����½ǣ�(n-1,n-1)��e����λ�ô���������ͨ�����YES���������������NO��

�������� Input Description

    ����ĵ�һ��Ϊһ������m����ʾ�Թ��������� 
    ���ÿ���Թ����ݵĵ�һ��Ϊһ������n��n��16������ʾ�Թ��ı߳�����������n��ÿ��n���ַ����ַ�֮��û�пո�ָ���

������� Output Description

    �����m�У�ÿ�ж�Ӧ���Թ����ߣ������YES���������NO��

�������� Sample Input

    1 
    7 
    s...##. 
    .#..... 
    ....... 
    ..#.... 
    ..#...# 
    ###...# 
    ......e

������� Sample Output

    YES


�������һ�������BFS��Ŀ����Ȼʹ��DFSҲ�������������Ǳض��ᳬʱ��BFS�����Ž������������������֣��Ҳο��ٶȰٿƵ�BFSԴ���룬ʹ�ýṹ�屣��ÿ������״̬��queue���д��㣬ÿ�β���ȡ�����׵Ľ�㣬������ɺ󣬽���������ĵ�ȫ����ӣ����ǽ�����������BFS��ʱ�����Ҳ�Ǿ��˵ģ����Բ����������صķ�ʽ��ֹ�ظ���������Ȼ���������Թ�ֻ��ı���λ�ã�����ֻ��Ҫ�ж������ϵĵ��Ƿ���ʹ��������Ƿ���ʹ�һ��״̬�����̣�����ʹ�ù�ϣ�����ء�ͨ������⣬�Ҷ�BFS�������˸���һ������ʶ��

 ����һ�£�����������̫���ˣ�ÿ�����m�ƺ�����1���ҵ�һ���ύ�Ĵ�����û����ѭ���ｫvisit�������㣬��Ȼ�����ˣ��е���£�����������
*/
    #include <stdio.h>  
    #include <string.h>  
    #include <stdlib.h>  
    #include <queue>  
    #define MAXN 20  
    using namespace std;  
    int map[MAXN][MAXN],n; //map[��i��][��j��]=0:�ø����ϰ���1:�ø����ϰ�,mx=����Ҫ����ĵ��������my=����Ҫ����ĵ������  
    int visit[MAXN][MAXN];//visit�����¼�ø��Ƿ��Ѿ������ʹ�����ֹ�ظ����ʣ����ݷǳ���ʱ  
    int steparr[4][2]={{-1,0},{1,0},{0,-1},{0,1}}; //steparr�����¼�ĸ�������ƶ�����  
    struct Node  
    {  
     int x,y,step; //x=��ǰ������� y=��ǰ������� step=��ǰ�Ѿ��ߵĲ���  
     Node(int x1,int y1,int step1):x(x1),y(y1),step(step1){}  
    };  
    int bfs()  
    {  
     Node node(0,0,0);//������ʼ���node  
     queue<Node> q; //����Node���͵Ķ���q  
     while(!q.empty()) q.pop(); //������q���  
     q.push(node); //����ʼ���node(������)���  
     while(!q.empty())  
     {  
      node=q.front(); //��ö��׵Ľ��node(��ʱ��ʼ����Ѿ���ӣ�nodeû�����ˣ�����node��¼���Ƕ��׵Ľ��)  
      q.pop(); //�����׽�����  
      if(node.x==n-1&&node.y==n-1)  
       return node.step; //����Ŀ��(n-1,n-1)������BFS���������ص�ǰ���Ĳ���  
      visit[node.x][node.y]=1; //���򣬱�ǵ�ǰλ���Ѿ����ʹ�����ֹ�Ժ��ظ�����  
      for(int i=0;i<4;i++) //�����������ĸ���������  
      {  
       int x=node.x+steparr[i][0];  
       int y=node.y+steparr[i][1];  
       if(x>=0&&x<n&&y>=0&&y<n&&visit[x][y]==0&&map[x][y]==0) //ֻҪ�ƶ���ĵ�û�г������̷�Χ�����µĵ�û�б����ʹ����µĵ����ϰ���������  
       {  
        visit[x][y]=1; //��ǵ�ǰ���Ѿ����ʹ�  
        Node next(x,y,node.step+1);  
        q.push(next); //���µĵ����  
       }  
      }  
     }  
     return -1; //ȫ������һ����Ҳ����⣬����-1  
    }  
    int main()  
    {  
     int i,j,k,m;  
     char in[MAXN];  
     scanf("%d",&m);  
     while(m--)  
     {  
      memset(map,0,sizeof(map));  
      memset(visit,0,sizeof(visit));  
      scanf("%d",&n);  
      for(i=0;i<n;i++) //��i�е�ѭ��  
      {  
       memset(in,0,sizeof(in));  
       scanf("%s",in);  
       for(j=0;j<n;j++) //��j�е�ѭ��  
       {  
        switch(in[j])  
        {  
         case 's':  
         {  
          map[i][j]=0;  
          break;  
         }  
         case '.':  
         {  
          map[i][j]=0;  
          break;  
         }  
         case '#':  
         {  
          map[i][j]=1;  
          break;  
         }  
         case 'e':  
         {  
          map[i][j]=0;  
          break;  
         }  
        }  
       }  
      }  
      if(bfs()==-1)  
       printf("NO\n");  
      else  
       printf("YES\n");  
     }  
     return 0;  
    }   