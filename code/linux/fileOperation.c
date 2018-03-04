#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void copyFile(char *sou, char *des);

int main()
{

    //copyFile("./file.in", "./file.out");
    return 0;
}

void copyFile(char *sou, char *des)
{
    FILE *in, *out;
    in = fopen(sou, "r");
    out = fopen(des, "w");

    int nread;
    char buf[1024];
    while (!feof(in))
    {
        nread = fread(buf, sizeof(char), 1024, in);
        fwrite(buf, sizeof(char), nread, out);
        fflush(out);
    }
    printf("copy done\n");

    fclose(in);
    fclose(out);
}