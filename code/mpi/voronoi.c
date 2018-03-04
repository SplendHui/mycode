#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
void dispatch(int processNumber, int matrixNumber, int *matrix, int generateNumber, int *generatePoint);
void receive(int np, int matrixNumber, int *matrix, int generateNumber, int *generatePoint);
void doTask(int myid, int pn, int matrixNumber, int *matrix, int generateNumber, int *generatePoint);
void printMatrix(int matrixNumber, int *matrix, int generateNumber, int *generatePoint);
void mark(int x, int y, int matrixNumber, int *matrix, int generateNumber, int *generatePoint);
void init(int matrixNumber, int *matrix, int gn, int *gs); //initialize the matrix
int cmpdist(int, int, int, int);						   // compare distance;
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

	double beginTime = MPI_Wtime();
	int *matrix, *generatePoint;
	if (myid == 0)
	{

		int matrixNumber;
		int generateNumber;
		srand((unsigned)time(NULL));
		//generateNumber = 5;
		matrixNumber = atoi(argv[1]);
		generateNumber = rand() % (matrixNumber * matrixNumber);
		//generateNumber = 5;
		//generateNumber = atoi(argv[2]);
		matrix = (int *)calloc(matrixNumber * matrixNumber, sizeof(int));
		generatePoint = (int *)malloc(sizeof(int) * generateNumber);
		int i, j;

		init(matrixNumber, matrix, generateNumber, generatePoint);

		dispatch(np, matrixNumber, matrix, generateNumber, generatePoint);

		doTask(myid, np, matrixNumber, matrix, generateNumber, generatePoint);

		receive(np, matrixNumber, matrix, generateNumber, generatePoint);

		printMatrix(matrixNumber, matrix, generateNumber, generatePoint);

		free(matrix);
		free(generatePoint);
	}
	else
	{
		int p[2];
		MPI_Bcast(p, 2, MPI_INT, 0, MPI_COMM_WORLD);
		//printf("matrixNumber = %d generateNumber = %d\n", p[0], p[1]);
		matrix = (int *)malloc(sizeof(int) * p[0] * p[0]);
		generatePoint = (int *)malloc(sizeof(int) * p[1]);

		MPI_Bcast(matrix, p[0] * p[0], MPI_INT, 0, MPI_COMM_WORLD); // bcast matrix
		MPI_Bcast(generatePoint, p[1], MPI_INT, 0, MPI_COMM_WORLD); //generate point

		doTask(myid, np, p[0], matrix, p[1], generatePoint);
		//after do
		MPI_Send(matrix, p[0] * p[0], MPI_INT, 0, 1, MPI_COMM_WORLD);
		free(matrix); //free memory;
		free(generatePoint);
	}
	double endTime = MPI_Wtime();
	MPI_Finalize();
}
// print the matrix
void printMatrix(int matrixNumber, int *matrix, int generateNumber, int *generatePoint)
{

	int i, j;
	int cnt = 0;
	for (i = 0; i < generateNumber; i++)
	{
		printf("x = %-4d, y = %-4d  value = %-4d\n", generatePoint[i] / matrixNumber, generatePoint[i] % matrixNumber, i);
		matrix[generatePoint[i]] += 100;
	}

	for (i = 0; i < matrixNumber; i++)
	{
		for (j = 0; j < matrixNumber; j++)
		{
			printf("%4d", matrix[cnt++]);
		}
		printf("\n");
	}
	printf("------------------------------------------\n");
}
void init(int matrixNumber, int *matrix, int generateNumber, int *generatePoint)
{
	//gn is genereate number
	int i;
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

int cmpdist(int fx, int fy, int tx, int ty)
{
	return abs(tx - fx) + abs(ty - fy);
}

void mark(int x, int y, int matrixNumber, int *matrix, int generateNumber, int *generatePoint)
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
	matrix[x * matrixNumber + y] = index;
	if (border == 1)
	{
		matrix[x * matrixNumber + y] = -1;
	}
}

void dispatch(int processNumber, int matrixNumber, int *matrix, int generateNumber, int *generatePoint)
{
	//pn is processes number
	//mat is matrix
	//gp is generate point
	//gn is generate ponint number
	int metaData[2] = {10, 5};
	metaData[0] = matrixNumber;
	metaData[1] = generateNumber;
	if (matrix != NULL)
	{
		MPI_Bcast(metaData, 2, MPI_INT, 0, MPI_COMM_WORLD);							// metadata
		MPI_Bcast(matrix, matrixNumber * matrixNumber, MPI_INT, 0, MPI_COMM_WORLD); // bcast matrix
		MPI_Bcast(generatePoint, generateNumber, MPI_INT, 0, MPI_COMM_WORLD);		//generate point
	}
	else
	{
		exit(-1);
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
	for (i = be; i < end; i++)
	{
		// gui mark the point
		mark(i / matrixNumber, i % matrixNumber, matrixNumber, matrix, generateNumber, generatePoint);
	}
}
void receive(int np, int matrixNumber, int *matrix, int generateNumber, int *generatePoint)
{

	int be, end, extra;
	int i, j;
	int *t = (int *)malloc(sizeof(int) * matrixNumber * matrixNumber);
	for (i = 1; i < np; i++)
	{
		MPI_Recv(t, matrixNumber * matrixNumber, MPI_INT, i, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

		be = i * ((matrixNumber * matrixNumber) / np);
		end = (i + 1) * ((matrixNumber * matrixNumber) / np);
		extra = (matrixNumber * matrixNumber) % np;
		if (extra != 0)
		{
			end += extra;
		}

		for (j = be; j < end; j++)
		{
			matrix[j] = t[j];
		}
	}
	free(t);
}