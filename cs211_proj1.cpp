#include <iostream>
#include "time.h"
#include "cstdlib"

using namespace std;

int main()
{
	int i = 0;
	int j = 0;
	int k = 0;

	const int n = 128;

	const int arr_size = n * n;

	double C[arr_size];
	double B[arr_size];
	double A[arr_size];
	
	for (i = 0; i < arr_size; ++i)
	{
		B[i] = rand() % 100;
		A[i] = rand() % 100;
	}


	clock_t t;
	t = clock();

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
	cout << "TIME IS " << t << " something...." << endl;

	cout << "hello world" << endl;

}
