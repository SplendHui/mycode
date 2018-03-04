/*
 Problem Description
Mr Wang wants some boys to help him with a project. Because the project is rather complex, the more boys come, the better it will be. Of course there are certain requirements.

Mr Wang selected a room big enough to hold the boys. The boy who are not been chosen has to leave the room immediately. There are 10000000 boys in the room numbered from 1 to 10000000 at the very beginning. After Mr Wang's selection any two of them who are still in this room should be friends (direct or indirect), or there is only one boy left. Given all the direct friend-pairs, you should decide the best way.
 

Input
The first line of the input contains an integer n (0 ¡Ü n ¡Ü 100 000) - the number of direct friend-pairs. The following n lines each contains a pair of numbers A and B separated by a single space that suggests A and B are direct friends. (A ¡Ù B, 1 ¡Ü A, B ¡Ü 10000000)
 

Output
The output in one line contains exactly one integer equals to the maximum number of boys Mr Wang may keep. 
 

Sample Input

4
1 2
3 4
5 6
1 6
4
1 2
3 4
5 6
7 8

 

Sample Output

4
2

Hint

A and B are friends(direct or indirect), B and C are friends(direct or indirect), 
then A and C are also friends(indirect).

 In the first sample {1,2,5,6} is the result.
In the second sample {1,2},{3,4},{5,6},{7,8} are four kinds of answers.
*/
    #include <cstdio>  
    #include <cstdlib>  
    #include <climits>  
      
    const int MAX = 10000005;  
    int pre[MAX],rank[MAX],maxx;  
      
      
    void init(){  
        int i;  
        for(i=1;i<MAX;++i){  
            pre[i] = i;  
            rank[i] = 1;  
        }  
    }  
      
    int root(int x){  
        if(x!=pre[x]){  
            pre[x] = root(pre[x]);  
        }  
        return pre[x];  
    }  
      
    void merge(int x,int y){  
        int fx = root(x);  
        int fy = root(y);  
        if(fx!=fy){  
            pre[fx] = fy;  
            rank[fy] += rank[fx];  
            if(rank[fy]>maxx)maxx = rank[fy];  
        }  
    }  
      
      
    int main(){  
        //freopen("in.txt","r",stdin);  
        int i,n,x,y;  
        while(scanf("%d",&n)!=EOF){  
            if(n==0){  
                printf("1\n");  
                continue;  
            }  
            init();  
            maxx = INT_MIN;  
            for(i=0;i<n;++i){  
                scanf("%d %d",&x,&y);  
                merge(x,y);  
            }  
            printf("%d\n",maxx);  
        }  
        return 0;  
    }  