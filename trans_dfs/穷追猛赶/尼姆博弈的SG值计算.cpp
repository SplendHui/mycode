

/*
��ķ����
��N�Ѹ����ɸ���Ʒ��������������ĳһ��ȡ������
��Ʒ���涨ÿ������ȡһ�������߲��ޣ����ȡ���ߵ�ʤ��

mex(S)��ʾ��С�Ĳ����ڼ���S�ķǸ�����
SG[s]=mex({SG[s0],SG[s1],SG[s2],SG[s3]...})������s1,s2,s3...��s��һ�����ߵ��ľ���
*/

#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 111

int sg[111];
int get_sg(int s){ // ���仯����

    if(sg[s]!=-1) return sg[s]; // ��Ϊ-1��˵��s��sgֵ�Ѿ��������ˣ����仯�������������������ˣ�ֱ�ӷ����Ѿ�������Ľ��

    bool vis[MAXN]={0}; // ��Ǹ������Ƿ񱻷��ʹ�������ʵ��mex����

    for(int i=1; i<=s; ++i){ // ö��ȡ����ʯ�ӣ�ת�Ƶ���һ������
        vis[get_sg(s-i)]=1; // �����һ������s-i��sgֵ
    }

    for(int i=0; ; ++i){ // �ҵ���С��û�б���ǵķǸ�����������mex�����ʵ��
        if(!vis[i]){ // û�б����
            return sg[s]=i; // ��ǰ�����s��sgֵ�͵�����С��û�б���ǵ�sgֵ
        }
    }
}

void get_sg(){ // ��С����ö�٣����μ���SGֵ
    // ͬ��
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
