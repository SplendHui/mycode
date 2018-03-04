/*
input
2
3 5 7 15
6 4 10296 936 1287 792 1 
output
105
10296 
最小公倍数 (LCM) 的一组积极的整数是最小的一组中的所有数字被整除的正整数.就例如 5、 7 和 15 LCM 是 105.
*/


#include <cstdio>  
int gcd(int a,int b){return b?gcd(b,a%b):a;}  
int lcm(int a,int b){return a/gcd(a,b)*b;}  
int main(){  
    int t,n,a,b;  
    scanf("%d",&t);  
    while(t--){  
        scanf("%d",&n);  
        scanf("%d",&a);  
        for(int i=1;i<n;i++){  
            scanf("%d",&b);  
            a=lcm(a,b);  
        }  
        printf("%d\n",a);  
    }  
}  