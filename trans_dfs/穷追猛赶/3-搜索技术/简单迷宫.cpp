/*
题目描述 Description

    在N*N的迷宫内，“#”为墙，“.”为路，“s”为起点，“e”为终点，一共4个方向可以走。从左上角（(0,0)“s”）位置处走到右下角（(n-1,n-1)“e”）位置处，可以走通则输出YES，不可以走则输出NO。

输入描述 Input Description

    输入的第一行为一个整数m，表示迷宫的数量。 
    其后每个迷宫数据的第一行为一个整数n（n≤16），表示迷宫的边长，接下来的n行每行n个字符，字符之间没有空格分隔。

输出描述 Output Description

    输出有m行，每行对应的迷宫能走，则输出YES，否则输出NO。

样例输入 Sample Input

    1 
    7 
    s...##. 
    .#..... 
    ....... 
    ..#.... 
    ..#...# 
    ###...# 
    ......e

样例输出 Sample Output

    YES


这个题是一道经典的BFS题目，当然使用DFS也能做出来，但是必定会超时，BFS求最优解的优势在这里得以显现，我参考百度百科的BFS源代码，使用结构体保存每个结点的状态，queue队列存结点，每次操作取出队首的结点，处理完成后，将处理输出的点全部入队，但是仅仅这样做，BFS的时间损耗也是惊人的，可以采用数组判重的方式防止重复搜索，当然，鉴于走迷宫只会改变点的位置，这里只需要判定棋盘上的点是否访问过，而非是否访问过一个状态的棋盘，不必使用哈希表判重。通过这道题，我对BFS搜索有了更进一步的认识。

 补充一下：这个题的数据太弱了，每个点的m似乎都是1，我第一次提交的代码中没有在循环里将visit数组清零，居然还过了，有点后怕，罪过啊罪过。
*/
    #include <stdio.h>  
    #include <string.h>  
    #include <stdlib.h>  
    #include <queue>  
    #define MAXN 20  
    using namespace std;  
    int map[MAXN][MAXN],n; //map[第i行][第j列]=0:该格无障碍，1:该格有障碍,mx=最终要到达的点的行数，my=最终要到达的点的列数  
    int visit[MAXN][MAXN];//visit数组记录该格是否已经被访问过，防止重复访问，回溯非常耗时  
    int steparr[4][2]={{-1,0},{1,0},{0,-1},{0,1}}; //steparr数组记录四个方向的移动方法  
    struct Node  
    {  
     int x,y,step; //x=当前点的行数 y=当前点的列数 step=当前已经走的步数  
     Node(int x1,int y1,int step1):x(x1),y(y1),step(step1){}  
    };  
    int bfs()  
    {  
     Node node(0,0,0);//声明初始结点node  
     queue<Node> q; //声明Node类型的队列q  
     while(!q.empty()) q.pop(); //将队列q清空  
     q.push(node); //将初始结点node(出发点)入队  
     while(!q.empty())  
     {  
      node=q.front(); //获得队首的结点node(此时初始结点已经入队，node没有用了，现在node记录的是队首的结点)  
      q.pop(); //将队首结点出队  
      if(node.x==n-1&&node.y==n-1)  
       return node.step; //到达目标(n-1,n-1)，结束BFS搜索，返回当前结点的步数  
      visit[node.x][node.y]=1; //否则，标记当前位置已经访问过，防止以后重复搜索  
      for(int i=0;i<4;i++) //向上下左右四个方向搜索  
      {  
       int x=node.x+steparr[i][0];  
       int y=node.y+steparr[i][1];  
       if(x>=0&&x<n&&y>=0&&y<n&&visit[x][y]==0&&map[x][y]==0) //只要移动后的点没有超出棋盘范围，且新的点没有被访问过，新的点无障碍，就搜索  
       {  
        visit[x][y]=1; //标记当前点已经访问过  
        Node next(x,y,node.step+1);  
        q.push(next); //将新的点入队  
       }  
      }  
     }  
     return -1; //全部搜索一遍后找不到解，返回-1  
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
      for(i=0;i<n;i++) //第i行的循环  
      {  
       memset(in,0,sizeof(in));  
       scanf("%s",in);  
       for(j=0;j<n;j++) //第j列的循环  
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