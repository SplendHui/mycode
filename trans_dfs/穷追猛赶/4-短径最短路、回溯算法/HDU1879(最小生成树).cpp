/*
Description
ʡ��������ͨ���̡���Ŀ����ʹȫʡ�κ�������ׯ�䶼����ʵ�ֹ�·��ͨ������һ����ֱ�ӵĹ�·������ֻҪ�ܼ��ͨ����·�ɴＴ�ɣ����ֵõ������·ͳ�Ʊ������г���������������޽���·�ķ��ã��Լ��õ�·�Ƿ��Ѿ���ͨ��״̬���������д���򣬼����ȫʡ��ͨ��Ҫ����ͳɱ���
 

Input
��������������ɲ���������ÿ�����������ĵ�1�и�����ׯ��ĿN ( 1< N < 100 )������ N(N-1)/2 �ж�Ӧ��ׯ���·�ĳɱ����޽�״̬��ÿ�и�4�����������ֱ���������ׯ�ı�ţ���1��ŵ�N����������ׯ���·�ĳɱ����Լ��޽�״̬��1��ʾ�ѽ���0��ʾδ����

��NΪ0ʱ���������
 

Output
ÿ���������������ռһ�У����ȫʡ��ͨ��Ҫ����ͳɱ���
 

Sample Input

3
1 2 1 0
1 3 2 0
2 3 4 0
3
1 2 1 0
1 3 2 0
2 3 4 1
3
1 2 1 0
1 3 2 1
2 3 4 1
0 

 

Sample Output

3
1
0 
��Ŀ����˼���Ǹ���n���㣬Ȼ���������֮�����ߵĴ��ۣ�����һЩ�������ӣ�����Щ�����������ٴ��۵ı�����������ͼ��ͨ��

˼·������˼·���ǿ�³˹�����㷨��˼·�����μӴ���С�ı߲��ұ����γɻ�·���ֽ����бߵĵ�ϲ����������˲��鼯��������û�����ӵı߰�Ȩֵ��������Ȼ���С����һ�κϲ��㣨���ǲ��鼯����ֱ����������ͼ��ͨ��
*/
    #include <cstdio>  
    #include <cstdlib>  
    #include <cstring>  
      
    const int maxx = 101;  
      
    typedef struct E{  
        int x,y,cost;  
    }E;  
      
    int pre[maxx];  
    E edg[5200];  
      
    void init(int n){  
        int i;  
        for(i=1;i<=n;++i){  
            pre[i] = i;  
        }  
    }  
      
    int root(int x){  
        if(x!=pre[x]){  
            pre[x] = root(pre[x]);  
        }  
        return pre[x];  
    }  
      
    int merge(int x,int y){  
        int ret = 0;  
        int fa = root(x);  
        int fb = root(y);  
        if(fa!=fb){  
            ret = 1;  
            pre[fa] = fb;  
        }  
        return ret;  
    }  
      
    int cmp(const void *a,const void *b){  
        E *pa = (E *)a;  
        E *pb = (E *)b;  
        return pa->cost-pb->cost;  
    }  
      
    int main(){  
        int n,x,y,cst,stat,i,pos;  
      
        while(scanf("%d",&n) && n){  
            init(n);  
            pos = 0;  
            int limit = n*(n-1)/2;  
            for(i=0;i<limit;++i){  
                scanf("%d %d %d %d",&x,&y,&cst,&stat);  
                if(stat==1){//�ѽ���·ֱ�Ӻϲ����˵�  
                    merge(x,y);  
                }else{//δ����·��¼����ʼ��ʹ��ۺ������򲢴�С����һ�β���ͼ��  
                    edg[pos].x = x;  
                    edg[pos].y = y;  
                    edg[pos].cost = cst;  
                    ++pos;  
                }  
            }  
            //������������ȫ�ǿ�³˹�����㷨��˼����  
            qsort(edg,pos,sizeof(E),cmp);  
            int minx = 0;//������¼��С����  
            for(i=0;i<pos;++i){  
                //�������1˵��������֮ǰ����ͨ����Ҫ���ϸñ�ʹ����������ͨ���Ӷ������㲢��ͬһ����  
                if(merge(edg[i].x,edg[i].y)==1){  
                    minx += edg[i].cost;  
                }  
            }  
      
            printf("%d\n",minx);  
        }  
        return 0;  
    }