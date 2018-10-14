#include <ctime>
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



	cout << "For ijk and n size of " << n << " we have clock time of " << (double(t) / CLOCKS_PER_SEC) << endl;

	t = clock();

	/* ijk */
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++) 
		{
			register double sum = 0.0;
			for (k = 0; k < n; k++)
			{
				sum += A[i*n+k] * B[k*n+j];
			}
			C[i*n+j] = sum;
		}
	}

	
	t = clock() - t;



	cout << "For dgemm3 and n size of " << n << " we have clock time of " << (double(t) / CLOCKS_PER_SEC) << endl;



	/* Multiply n x n matrices a and b  */



}
