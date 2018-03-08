#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int dir[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
int flag = 0;
int map[8][8];
int count = 0;

int max = 1000;
void printMatrix();

int check(int x, int y)
{
    if (x < 8 && x >= 0 && y < 8 && y >= 0 && map[x][y] == 0)
        return 1;
    return 0;
}

void sort(int step[8][2], int x, int y)
{
    int nx, ny;
    int nnx, nny;
    int i, j;

    for (i = 0; i < 8; i++)
    {
        step[i][0] = i;
        step[i][1] = 0;
    }
    for (i = 0; i < 8; i++)
    {
        nx = x + dir[i][0];
        ny = y + dir[i][1];

        if (check(nx, ny))
        {
            step[i][1]++;
            map[nx][ny] = 0x7ffffff;
            for (j = 0; j < 8; j++)
            {
                nnx = nx + dir[j][0];
                nny = ny + dir[j][1];
                if (check(nnx, nny))
                {
                    step[i][1]++;
                }
            }
            map[nx][ny] = 0;
        }
        else
        {
            step[i][1] = -1;
        }
    }

    for (i = 0; i < 8 - 1; i++)
        for (j = i + 1; j < 8; j++)
        {
            if (step[i][1] > step[j][1])
            {
                nx = step[i][0];
                ny = step[i][1];
                step[i][0] = step[j][0];
                step[i][1] = step[j][1];
                step[j][0] = nx;
                step[j][1] = ny;
            }
        }
}
void dfs(int x, int y, int cnt)
{
    // successful
    if (cnt == 64)
    {
        flag = 1;
        count++;
        printMatrix();
        return;
    }
    int step[8][2];
    int i, nx, ny;
    sort(step, x, y);
    for (i = 0; i < 8 && count < max; i++)
    {
        if (step[i][1] == -1)
            continue;
        nx = x + dir[step[i][0]][0];
        ny = y + dir[step[i][0]][1];
        map[nx][ny] = cnt + 1;
        dfs(nx, ny, cnt + 1);
        map[nx][ny] = 0;
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
    struct timeval be, end;
    gettimeofday(&be, NULL);
    dfs(bx, by, 1);
    gettimeofday(&end, NULL);
    if (!flag)
        printf("can't reach\n");
    printf("time = %ld microsecond \n", (end.tv_sec * 1000000 + end.tv_usec) - (be.tv_sec * 1000000 + be.tv_usec));
    return 0;
}
