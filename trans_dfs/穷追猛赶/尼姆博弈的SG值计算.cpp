

/*
尼姆博弈
有N堆各若干个物品，两个人轮流从某一堆取任意多的
物品，规定每次至少取一个，多者不限，最后取光者得胜。

mex(S)表示最小的不属于集合S的非负整数
SG[s]=mex({SG[s0],SG[s1],SG[s2],SG[s3]...})，其中s1,s2,s3...是s下一步能走到的局面
*/

#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 111

int sg[111];
int get_sg(int s){ // 记忆化搜索

    if(sg[s]!=-1) return sg[s]; // 不为-1，说明s的sg值已经被计算了，记忆化搜索不用再搜索计算了，直接返回已经算出来的结果

    bool vis[MAXN]={0}; // 标记各个数是否被访问过，用于实现mex运算

    for(int i=1; i<=s; ++i){ // 枚举取几个石子，转移到下一个局面
        vis[get_sg(s-i)]=1; // 标记下一个局面s-i的sg值
    }

    for(int i=0; ; ++i){ // 找到最小的没有被标记的非负整数，就是mex运算的实现
        if(!vis[i]){ // 没有被标记
            return sg[s]=i; // 当前局面的s的sg值就等于最小的没有被标记的sg值
        }
    }
}

void get_sg(){ // 从小到大枚举，依次计算SG值
    // 同上
    for(int s=0; s<MAXN; ++s){

        bool vis[MAXN]={0};

        for(int i=1; i<=s; ++i){
            vis[sg[s-i]]=1;
        }

        for(int i=0; ; ++i){
            if(!vis[i]){
                sg[s]=i;
                break;
            }
        }
    }
}

int main(){

    memset(sg,-1,sizeof(sg));
    for(int i=0; i<MAXN; ++i){
        printf("%d ",get_sg(i));
    }

    puts("\n");

    get_sg();
    for(int i=0; i<MAXN; ++i){
        printf("%d ",get_sg(i));
    }

    return 0;
}
