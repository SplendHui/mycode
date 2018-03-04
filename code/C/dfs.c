#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dir[8][2] = {{2, -1}, {2, 1}, {1, -2}, {1, 2}, {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}};
int flag = 0;
int map[8][8];
int count = 0;

int max = 1000;
void printMatrix();
void dfs(int x, int y, int cnt)
{
    // successful
    if (cnt == 64)
    {
        flag = 1;
        printMatrix();
        count++;
        return;
    }
    int i, nx, ny;
    for (i = 0; i < 8 && count < max; i++)
    {
        nx = x + dir[i][0];
        ny = y + dir[i][1];
        if (nx < 8 && nx >= 0 && ny < 8 && ny >= 0 && map[nx][ny] == 0)
        {
            map[nx][ny] = cnt + 1;
            dfs(nx, ny, cnt + 1);
            // if find then no return
            map[nx][ny] = 0;
        }
    }
}
void printMatrix()
{
    int i, j;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            printf("%2d ", map[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------\n");
}
int main(int argc, char *argv[])
{
    int bx, by;

    printf("input horse begin x and y \n");
    scanf("%d%d", &bx, &by);
    map[bx][by] = 1;
    printMatrix();
    dfs(bx, by, 1);
    if (!flag)
        printf("can't reach\n");

    return 1;
}
