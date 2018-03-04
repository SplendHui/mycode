/*************************************************************************
    > File Name: lock2.c
    > Author: splend
    > Mail: 752406912@qq.com 
    > Created Time: 2017年11月24日 星期五 09时42分30秒
 ************************************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

const char *lock_file = "/tmp/LCK.test2";


int main()
{

    int file_desc;
    int tries = 10;

    while (tries--)
    {

        file_desc = open(lock_file, O_RDWR | O_CREAT | O_EXCL, 0444);
        if (file_desc != -1)
        {

            printf("%d - Lock already present\n", getpid());
            sleep(3);
        }
        else
        {
            printf("%d - I hava exclusive access\n", getpid());
            sleep(1);
            close(file_desc);
            unlink(lock_file);
            sleep(2);
        }
    }
    return 0;
}
