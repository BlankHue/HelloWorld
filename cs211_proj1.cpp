#include <iostream>
#include "time.h"
#include "cstdlib"

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


	const int n = atoi(argv[1]);

	const int arr_size = n * n;


	double C[arr_size];
	double B[arr_size];
	double A[arr_size];



	RandomizeArrays(A, B, arr_size);



	clock_t t;

	t = clock();



	/* dgemm(): simple ijk version triple loop algorithm */

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

	cout << "For dgemm0 and n size of " << n << " we have clock time of " << t << endl;

	RandomizeArrays(A, B, arr_size);

	t = clock();

	/* dgemm1: simple ijk version triple loop algorithm with register reuse */

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

	cout << "For dgemm1 and n size of " << n << " we have clock time of " << t << endl << endl;

}
