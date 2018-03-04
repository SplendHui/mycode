#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <time.h>
#include <stdlib.h>

//int array[] = {15, 11, 9, 16, 3, 14, 8, 7, 4, 6, 12, 10, 5, 2, 13, 1};
void merge_low(int mykeys[], int receive[], int n);
void merge_high(int mykeys[], int receive[], int n);
void odd_even_sort(int a[], int n);
int cmp(const void *a, const void *b);
int getPartner(int phase, int myid, int comm_sz);
void doSort(int myid, int np);
void printMatrix(int array[], int n);
void init();

int *array;
int *mykeys, *receive, partner, N;

int main(int argc, char **argv)
{
	int i, j;
	int myid, np, namelen;
	char proc_name[MPI_MAX_PROCESSOR_NAME];
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Get_processor_name(proc_name, &namelen);
	//  fprintf(stderr,"Hello, I am proc. %d of %d on %s\n",
	//         myid, np, proc_name);
	// 1. if myid == 0 then initialize the matrix ;
	if (myid == 0)
	{
		N = atoi(argv[1]);
		init();
	}

	MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

	int currentNumber = N / np;

	receive = (int *)malloc(sizeof(int) * currentNumber);
	mykeys = (int *)malloc(sizeof(int) * currentNumber);

	// 2. bcast the matrix to ohers process;

	MPI_Scatter(array, N / np, MPI_INT, mykeys, N / np, MPI_INT, 0, MPI_COMM_WORLD);

	// 3. area sort

	qsort(mykeys, N / np, sizeof(int), cmp);

	// 4. for (i = 0; i < np; i++) do sendrecv() and merge;

	doSort(myid, np);

	// 5. if myid == 0 , receive all and print;

	MPI_Gather(mykeys, currentNumber, MPI_INT, array, currentNumber, MPI_INT, 0, MPI_COMM_WORLD);
	if (myid == 0)
		printMatrix(array, N);

	MPI_Finalize();
}

void merge_low(int mykeys[], int receive[], int n)
{

	int mi, ri, ti;
	int *temp = malloc(sizeof(int) * n);
	if (temp == NULL)
	{
		exit(-1);
	}
	mi = ri = ti = 0;
	while (ti < n)
	{
		if (mykeys[mi] <= receive[ri])
		{
			temp[ti] = mykeys[mi];
			ti++;
			mi++;
		}
		else
		{
			temp[ti] = receive[ri];
			ti++;
			ri++;
		}
	}

	for (mi = 0; mi < n; mi++)
		mykeys[mi] = temp[mi];
	free(temp);
}
void merge_high(int mykeys[], int receive[], int n)
{

	int mi, ti, ri;
	int *temp = malloc(sizeof(int) * n * 2);
	if (temp == NULL)
	{
		exit(-1);
	}

	mi = ri = ti = 0;
	/*
	while (ti < 2 * n)
	{
		if (mi < n)
			temp[ti++] = mykeys[mi++];
		if (ri < n)
			temp[ti++] = receive[ri++];
	}
	qsort(temp, 2 * n, sizeof(int), cmp);
	*/
	while (mi < n && ri < n)
	{
		if (mykeys[mi] >= receive[ri])
		{
			temp[ti] = receive[ri];
			ri++;
			ti++;
		}
		else
		{
			temp[ti] = mykeys[mi];
			ti++;
			mi++;
		}
	}

	while (mi < n)
	{
		temp[ti] = mykeys[mi];
		ti++;
		mi++;
	}
	while (ri < n)
	{
		temp[ti] = receive[ri];
		ti++;
		ri++;
	}
	for (mi = 0; mi < n; mi++)
		mykeys[mi] = temp[n + mi];
	free(temp);
}
void printMatrix(int array[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");
}
void doSort(int myid, int np)
{
	int i;
	for (i = 0; i < np; i++)
	{
		partner = getPartner(i, myid, np);
		if (partner != MPI_PROC_NULL)
		{
			MPI_Sendrecv(mykeys, N / np, MPI_INT, partner, 0, receive, N / np, MPI_INT, partner, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			if (myid < partner)
			{
				merge_low(mykeys, receive, N / np);
			}
			else
			{
				merge_high(mykeys, receive, N / np);
			}
		}
	}
}
void init()
{
	int i;
	srand(time(NULL));
	array = (int *)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++)
	{
		*(array + i) = random() % 100000000;
	}
}

int getPartner(int phase, int myid, int comm_sz)
{
	int partner;
	if (phase % 2 == 0)
	{
		if (myid % 2 != 0)
		{
			partner = myid - 1;
		}
		else
		{
			partner = myid + 1;
		}
	}
	else
	{
		if (myid % 2 != 0)
		{
			partner = myid + 1;
		}
		else
		{
			partner = myid - 1;
		}
	}
	if (partner == -1 || partner == comm_sz)
	{
		partner = MPI_PROC_NULL;
	}
	return partner;
}
int cmp(const void *a, const void *b)
{
	return *((int *)a) > *((int *)b);
}