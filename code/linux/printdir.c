/*************************************************************************
    > File Name: printdir.c
    > Author: splend
    > Mail: 752406912@qq.com 
    > Created Time: 2017年12月12日 星期二 15时53分24秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

void printdir(char *name, int depth)
{

    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;

    if ((dp = opendir(name)) == NULL)
    {
        fprintf(stderr, "can not open the directory %s", name);
        return;
    }

    chdir(name);
    while ((entry = readdir(dp)) != NULL)
    {
        lstat(entry->d_name, &statbuf);
        if (S_ISDIR(statbuf.st_mode))
        {
            if (strcmp(".", entry->d_name) == 0 ||
                strcmp("..", entry->d_name) == 0)
                continue;

            printf("%*s%s/\n", depth, "", entry->d_name);
            printdir(entry->d_name, depth + 1);
        }
        else
            printf("%*s%s/\n", depth, "", entry->d_name);
    }
    chdir("..");
    closedir(dp);
}

int main(int argc, char *argv[])
{

    char *topdir = ".";

    int size = 30;
    if (argc >= 2)
        topdir = argv[1];

    char buf[30];
    printf("Directory scan of %s:\n", topdir);
    printdir(topdir, 0);
    printf("Done");
    return 0;
}
