//方法一
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int col,row;
int map[8][8];
int mark[8][8];

struct node
{
	int x,y,t_use,t_remine;  //t_use所走步数，t_remine为bomb离爆炸时间
}start;

void store_map()
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cin>>map[i][j];
			if(map[i][j]==2)
			{
				start.x=i;
				start.y=j;
				start.t_use=0;
				start.t_remine=6;
			}
		}
	}
}

void bfs()
{
	const int help[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

	queue<node> myqueue;
	myqueue.push(start);
	memset(mark,0,sizeof(mark));    //开始时都是0
	mark[start.x][start.y]=6;       //起点是6

	bool flag = false;
	int t_remine=0,t_use=0;
	while(!myqueue.empty() && !flag)
	{
		node tmp=myqueue.front();
		myqueue.pop();

		for(int i=0;i<4;i++)
		{
			node temp;
			temp.x=tmp.x+help[i][0];
			temp.y=tmp.y+help[i][1];

			if(map[temp.x][temp.y]!=0 && temp.x>=0 && temp.x<row && temp.y>=0 && temp.y<col)  //没越界并不是0，才可访问
			{
				temp.t_use=tmp.t_use+1;
                temp.t_remine=tmp.t_remine-1;

			    if(map[temp.x][temp.y]==4)
				{
					temp.t_remine=6;
				}
				else if(map[temp.x][temp.y]==3)
				{
					t_remine=tmp.t_remine-1;
                    t_use=tmp.t_use+1;
					flag=true;
				}

				if(temp.t_remine>1 && mark[temp.x][temp.y]<temp.t_remine)   //满足条件才入队
				{
					mark[temp.x][temp.y]=temp.t_remine;
				    myqueue.push(temp);
				}
			}
			if(flag) break;
		}
	}

	if(flag)
	{
		if(t_remine>0)
			cout<<t_use;
		else
			cout<<-1;
	}
	else
		cout<<-1;
	cout<<endl;
}

int main()
{
	int t_case;
	freopen("t.in","r",stdin);
	cin>>t_case;
	while(t_case--)
	{
		cin>>row>>col;

		store_map();

		bfs();
	}
	return 0;
}
/* 方法二
#include<iostream>
#include<queue>
using namespace std;

int map[8][8];
int row,col;

struct node
{
	int x,y,step,time;  //step为走的步数，time为bomb离爆炸时间
}start;

void store_map()
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cin>>map[i][j];
			if(map[i][j]==2)
			{
				start.x=i;
				start.y=j;
				start.step=0;
				start.time=6;
			}
		}
	}
}

void bfs()
{
    const int help[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    
	queue<node> q;
	q.push(start);

    node p1,p2;
	int i;
	while(!q.empty())
	{
		p1=q.front();
		q.pop();

		for(i=0;i<4;i++)
		{
			p2.step=p1.step+1;
			p2.time=p1.time-1;
			p2.x=p1.x+help[i][0];
			p2.y=p1.y+help[i][1];

			if(p2.x>=0 && p2.x<row && p2.y>=0 && p2.y<col && map[p2.x][p2.y]!=0 && p2.time>0)   //注意这里的p2.time>0
			{
				if(map[p2.x][p2.y]==3)
				{
					cout<<p2.step<<endl;
					return;
				}
				else if(map[p2.x][p2.y]==4)
				{
					p2.time=6;
					map[p2.x][p2.y]=0;    //该位置4不能再访问了
				}
				q.push(p2);
			}
		}
	}

	cout<<-1<<endl;
}		

int main()
{
	int t_case;

	cin>>t_case;
	while(t_case--)
	{
		cin>>row>>col;

		store_map();

		bfs();
	}

	return 0;
}
*/
