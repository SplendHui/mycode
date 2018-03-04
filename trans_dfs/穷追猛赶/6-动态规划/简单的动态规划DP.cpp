/*Description: 

??????有一个容量为V的箱子和N件物品，每件物品的体积Vi。现在要从N件物品中取出若干件放入箱子中，使得箱子的剩余体积最小。

Input: 

第一行为两个数V，N，代表箱子容量和物品数量。 第二行为N个数，表示N件物品的体积。 0<=V<=20000。 0<=N<=100。 0<=Vi<=10^9。

Output: 

输出一个数，即箱子剩余的最小体积。

Sample Input: 

24 6
8 3 12 7 9 7

Sample Output: 

0
*/
#include<cstdio>
int goods[101];//存放物品的体积
bool space[20001];
int main(void)
{
    int v, n, i, j;//v箱子容量,n物品数量

    scanf("%d%d", &v, &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &goods[i]);
    space[0] = 1;//space[i]=1表示至少可以装i体积
    for (i = 0; i < n; ++i)
    {
        for (j = v; j >= goods[i]; --j)//j为剩余的背包容量,j >= goods[j]表示剩余的容量j大于物品的体积good[i],即还可以装
        {
            if (space[v])//如果箱子已经可以装满，则剩余的空间为0；无需继续判断
            {
                printf("0\n");
                return 0;
            }
            if (space[j - goods[i]])//只有当space[i]的值为1时，才执行
                space[j] = 1;//背包可装space[j]容量的物品
        }
    }
    for (i = v; i >= 0; --i)//因为题目要求最小剩余体积，即装的最多，所以倒着开始判断
        if (space[i])   break;
    printf("%d", v - i);
    return 0;
}