/*Description: 

??????��һ������ΪV�����Ӻ�N����Ʒ��ÿ����Ʒ�����Vi������Ҫ��N����Ʒ��ȡ�����ɼ����������У�ʹ�����ӵ�ʣ�������С��

Input: 

��һ��Ϊ������V��N������������������Ʒ������ �ڶ���ΪN��������ʾN����Ʒ������� 0<=V<=20000�� 0<=N<=100�� 0<=Vi<=10^9��

Output: 

���һ������������ʣ�����С�����

Sample Input: 

24 6
8 3 12 7 9 7

Sample Output: 

0
*/
#include<cstdio>
int goods[101];//�����Ʒ�����
bool space[20001];
int main(void)
{
    int v, n, i, j;//v��������,n��Ʒ����

    scanf("%d%d", &v, &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &goods[i]);
    space[0] = 1;//space[i]=1��ʾ���ٿ���װi���
    for (i = 0; i < n; ++i)
    {
        for (j = v; j >= goods[i]; --j)//jΪʣ��ı�������,j >= goods[j]��ʾʣ�������j������Ʒ�����good[i],��������װ
        {
            if (space[v])//��������Ѿ�����װ������ʣ��Ŀռ�Ϊ0����������ж�
            {
                printf("0\n");
                return 0;
            }
            if (space[j - goods[i]])//ֻ�е�space[i]��ֵΪ1ʱ����ִ��
                space[j] = 1;//������װspace[j]��������Ʒ
        }
    }
    for (i = v; i >= 0; --i)//��Ϊ��ĿҪ����Сʣ���������װ����࣬���Ե��ſ�ʼ�ж�
        if (space[i])   break;
    printf("%d", v - i);
    return 0;
}