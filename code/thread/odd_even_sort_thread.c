#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 2
int *array;
int n = 10;
void *thread_function(void *arg);
void init();
int main(int argc, char **argv)
{

    int res;
    pthread_t a_thread[NUM_THREADS];

    void *thread_result;
    int lots_of_threads;

    init();
    int i;
    for (i = 0; i < n; i++)
    {
        for (lots_of_threads = 0; lots_of_threads < NUM_THREADS; lots_of_threads++)
            res = pthread_create(&(a_thread[lots_of_threads]), NULL, thread_function, (void *)lots_of_threads);

        for (lots_of_threads = NUM_THREADS - 1; lots_of_threads >= 0; lots_of_threads--)
            res = pthread_join(a_thread[lots_of_threads], &thread_result);
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    printf("All done\n");
    exit(EXIT_SUCCESS);

    return 0;
}

void *thread_function(void *arg)
{
    int odd = ((int)arg);
    int i;
    i = odd == 0 ? 0 : 1;
    for (; i < n - 1; i += 2)
    {
        if (array[i + 1] <= array[i])
        {
            int t = array[i];
            array[i] = array[i + 1];
            array[i + 1] = t;
        }
    }
}

void init()
{
    int i;
    srand(time(NULL));
    array = (int *)malloc(sizeof(int) * n);
    if (array == NULL)
        exit(-1);
    for (i = 0; i < n; i++)
        *(array + i) = rand() % 10000;
}