#include "time.h"
#include "cstdlib"
#include <iostream>

using namespace std;

void RandomizeArrays(double arr1[], double arr2[], int array_size)
{
	int m = 0;

	for (m = 0; m < array_size; ++m)
	{
		arr1[m] = rand() % 100;
		arr2[m] = rand() % 100;
	}
}




int main(int argc, char** argv)
{
	int i = 0;
	int j = 0;
	int k = 0;

	double * C;
	double * B;
	double * A;

	const int n = atoi(argv[1]);

	const int arr_size = n * n;


	C = (double*)malloc(arr_size * sizeof(double));
	B = (double*)malloc(arr_size * sizeof(double));
	A = (double*)malloc(arr_size * sizeof(double));


	RandomizeArrays(A, B, arr_size);



	clock_t t;

	t = clock();

	/* Multiply n x n matrices a and b  */
	
	for (i = 0; i < n; i += 2)
	{
		for (j = 0; j < n; j += 2)
		{
			for (k = 0; k < n; k += 2)
			{
				C[i*n + j] = A[i*n + k] * B[k*n + j] + A[i*n + k + 1] * B[(k + 1)*n + j]
					+ C[i*n + j];
				C[(i + 1)*n + j] = A[(i + 1)*n + k] * B[k*n + j] + A[(i + 1)*n + k + 1] * B[(k + 1)*n + j]
					+ C[(i + 1)*n + j];
				C[i*n + (j + 1)] = A[i*n + k] * B[k*n + (j + 1)] + A[i*n + k + 1] * B[(k + 1)*n + (j + 1)]
					+ C[i*n + (j + 1)];
				C[(i + 1)*n + (j + 1)] = A[(i + 1)*n + k] * B[k*n + (j + 1)]
					+ A[(i + 1)*n + k + 1] * B[(k + 1)*n + (j + 1)] + C[(i + 1)*n + (j + 1)];

			}
		}
	}
	
	t = clock() - t;

	cout << "For dgemm2 and n size of " << n << " we have clock time of " << (double(t) / CLOCKS_PER_SEC) << endl;

	
	/*
	// dgemm(): simple ijk version triple loop algorithm 

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				C[i*n + j] += A[i*n + k] * B[k*n + j];
			}
		}
	}

	t = clock() - t;

	cout << "For dgemm0 and n size of " << n << " we have clock time of " << (double(t) / CLOCKS_PER_SEC) << endl;

	RandomizeArrays(A, B, arr_size);

	t = clock();

	// dgemm1: simple ijk version triple loop algorithm with register reuse 

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			register double r = C[i*n + j];
			for (k = 0; k < n; k++)
			{
				r += A[i*n + k] * B[k*n + j];
			}
			C[i*n + j] = r;
		}
	}

	t = clock() - t;

	cout << "For dgemm1 and n size of " << n << " we have clock time of " << (double(t) / CLOCKS_PER_SEC) << endl << endl;
	*/
}
