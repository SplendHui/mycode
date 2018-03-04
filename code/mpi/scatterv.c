#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <time.h>
#include <stdlib.h>
int *sendbuf;
int *recv;
int *sendcnts;
int *displ;
int *generatePoint;
int generateNumber;
int matrixNumber;
// print matrix
void printMatrix(int matrixNumber);
// initialize the matrix and generatePoint;
void init(int matrixNumber, int *matrix, int generateNumber, int *generatePoint);
// initialize Scatterv
void initScatterv(int matrixNumber, int np);
// allocate memory for matrix , generatePoint , receive buffer;
void getMemory(int matrixNumber, int **matrix, int generateNumber, int **generatePoint, int receiveNumber, int **receive);
// do task
void doTask(int myid, int pn, int matrixNumber, int *matrix, int generateNumber, int *generatePoint);
// mark the matrix
void mark(int x, int y, int matrixNumber, int *matrix, int generateNumber, int *generatePoint, int k);
// free memory
void freeScatter(void);
// get distance;
int cmpdist(int fx, int fy, int tx, int ty);
int main(int argc, char **argv)
{
	int myid, np, namelen;
	char proc_name[MPI_MAX_PROCESSOR_NAME];
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Get_processor_name(proc_name, &namelen);
	//  fprintf(stderr,"Hello, I am proc. %d of %d on %s\n",
	//         myid, np, proc_name);

	int i, j;
	int n = 0;

	generateNumber = 5;
	//matrixNumber = 10;
	int metaData[2];
	MPI_Barrier(MPI_COMM_WORLD);
	double beginTime = MPI_Wtime();
	if (myid == 0)
	{

		matrixNumber = atoi(argv[1]);
		//matrixNumber = 10;
		srand(time(NULL));
		generateNumber = rand() % (matrixNumber * matrixNumber);
		//generateNumber = 10;
		initScatterv(matrixNumber, np);
		int receiveNumber = (matrixNumber * matrixNumber) / np;
		metaData[0] = matrixNumber;
		metaData[1] = generateNumber;

		getMemory(matrixNumber, &sendbuf, generateNumber, &generatePoint, receiveNumber, &recv);

		init(matrixNumber, sendbuf, generateNumber, generatePoint);

		MPI_Bcast(metaData, 2, MPI_INT, 0, MPI_COMM_WORLD);

		MPI_Bcast(generatePoint, generateNumber, MPI_INT, 0, MPI_COMM_WORLD);

		MPI_Scatterv(sendbuf, sendcnts, displ, MPI_INT, recv, receiveNumber, MPI_INT, 0, MPI_COMM_WORLD);
		//do
		doTask(myid, np, matrixNumber, recv, generateNumber, generatePoint);

		MPI_Gatherv(recv, receiveNumber, MPI_INT, sendbuf, sendcnts, displ, MPI_INT, 0, MPI_COMM_WORLD);

		//printMatrix(matrixNumber);

		free(sendbuf);
		free(generatePoint);
		freeScatter();
	}
	else
	{
		MPI_Bcast(metaData, 2, MPI_INT, 0, MPI_COMM_WORLD);
		matrixNumber = metaData[0];
		generateNumber = metaData[1];
		initScatterv(matrixNumber, np);
		int receiveNumber = (matrixNumber * matrixNumber) / np;
		if (myid == (np - 1))
			receiveNumber += (matrixNumber * matrixNumber) % np;
		// allocate memory for matrix , generatePoint , recv
		getMemory(0, &sendbuf, generateNumber, &generatePoint, receiveNumber, &recv);

		MPI_Bcast(generatePoint, generateNumber, MPI_INT, 0, MPI_COMM_WORLD);

		MPI_Scatterv(sendbuf, sendcnts, displ, MPI_INT, recv, receiveNumber, MPI_INT, 0, MPI_COMM_WORLD);
		//do
		doTask(myid, np, matrixNumber, recv, generateNumber, generatePoint);

		MPI_Gatherv(recv, receiveNumber, MPI_INT, sendbuf, sendcnts, displ, MPI_INT, 0, MPI_COMM_WORLD);

		free(generatePoint);
		freeScatter();
	}
	double endTime = MPI_Wtime();
	if (myid == 0)
	{
		printf("%d * %d voronoi graph total spent time = %lf second\n", matrixNumber, matrixNumber, endTime - beginTime);
	}
	MPI_Finalize();
}
int cmpdist(int fx, int fy, int tx, int ty)
{
	return abs(tx - fx) + abs(ty - fy);
}
void getMemory(int matrixNumber, int **matrix, int generateNumber, int **generatePoint, int receiveNumber, int **receive)
{

	if (matrixNumber != 0)
	{
		//printf("matrix allocate successful\n");
		*matrix = (int *)malloc(sizeof(int) * (matrixNumber * matrixNumber));
	}
	else
	{
		*matrix = NULL;
	}
	if (receiveNumber != 0)
	{
		//printf("receive allocate successful\n");
		*receive = (int *)malloc(sizeof(int) * receiveNumber);
	}
	else
	{
		*receive = NULL;
	}
	if (generateNumber != 0)
	{
		*generatePoint = (int *)malloc(sizeof(int) * generateNumber);
	}
	else
	{
		*generatePoint = NULL;
	}
}

void init(int matrixNumber, int *matrix, int generateNumber, int *generatePoint)
{
	int i;
	memset(matrix, 0, sizeof(int) * matrixNumber * matrixNumber);
	for (i = 0; i < generateNumber;)
	{
		int x, y;
		x = rand() % matrixNumber;
		y = rand() % matrixNumber;
		if (x < matrixNumber && y < matrixNumber && matrix[x * matrixNumber + y] == 0)
		{
			matrix[x * matrixNumber + y] = i;
			generatePoint[i] = x * matrixNumber + y;
			i++;
		}
	}
}
void initScatterv(int matrixNumber, int np)
{

	int i;
	sendcnts = (int *)malloc(sizeof(int) * np);
	displ = (int *)malloc(sizeof(int) * np);
	for (i = 0; i < np; i++)
	{
		sendcnts[i] = ((matrixNumber * matrixNumber) / np);
		if (i == (np - 1))
		{
			sendcnts[i] += (matrixNumber * matrixNumber) % np;
		}
	}
	for (i = 0; i < np; i++)
	{
		displ[i] = i * (matrixNumber * matrixNumber / np);
	}
}

void mark(int x, int y, int matrixNumber, int *matrix, int generateNumber, int *generatePoint, int k)
{
	int i;
	int min, t;
	min = cmpdist(x, y, generatePoint[0] / matrixNumber, generatePoint[0] % matrixNumber);
	int index = 0;
	int border = 0;
	for (i = 1; i < generateNumber; i++)
	{

		t = cmpdist(x, y, generatePoint[i] / matrixNumber, generatePoint[i] % matrixNumber);
		if (t < min)
		{
			min = t;
			index = i;
			border = 0;
		}
		else if (t == min)
		{
			border = 1;
		}
	}
	matrix[k] = index;
	if (border == 1)
	{
		matrix[k] = -1;
	}
}
void doTask(int myid, int pn, int matrixNumber, int *matrix, int generateNumber, int *generatePoint)
{
	//pn is process number
	//myid is process rank
	int tn, extra;
	tn = (matrixNumber * matrixNumber) / pn;
	extra = (matrixNumber * matrixNumber) % pn;
	// if current process is the last process , add extra task
	int be, end;

	be = myid * tn;
	end = (myid + 1) * tn;
	int i, j;
	if (myid == (pn - 1))
	{
		tn += extra;
	}
	int k = 0;
	for (i = be; i < end; i++)
	{
		// gui mark the point
		mark(i / matrixNumber, i % matrixNumber, matrixNumber, matrix, generateNumber, generatePoint, k);
		k++;
	}
}
void freeScatter()
{
	free(sendcnts);
	free(recv);
	free(displ);
}
void printMatrix(int matrixNumber)
{

	int i, j;
	int cnt = 0;
	for (i = 0; i < matrixNumber; i++)
	{
		for (j = 0; j < matrixNumber; j++)
		{
			if (sendbuf[cnt] != -1)
				printf("%d ", sendbuf[cnt] + 1);
			else
				printf("%d ", sendbuf[cnt]);
			cnt++;
		}
		printf("\n");
	}
}