#include <ctime>
#include <iostream>
#include <cstdlib>

using namespace std;

void RandomizeArrays(double arr1[], double arr2[], double arr3[], int array_size)
{
	int m = 0;

	for (m = 0; m < array_size; ++m)
	{
		srand(1);
		arr1[m] = rand() % 100;
		arr2[m] = rand() % 100;
	}

	//clean array C
	for (m = 0; m < array_size; ++m)
	{
		arr3[m] = 0;
	}
}


void storeMax(double arr[], double store_array[], int store_here, int array_size)
{
	double tempMax = 0;
	for (int r = 0; r < array_size; r++)
	{
		if (arr[r] > tempMax)
		{
			tempMax = arr[r];
		}
	}
	store_array[store_here] = tempMax;
}


int main(int argc, char** argv)

{

	int i = 0;
	int j = 0;
	int k = 0;


	double * C;
	double * B;
	double * A;
	double * check_array;

	const int n = atoi(argv[1]);
	const int arr_size = n * n;

	C = (double*)malloc(arr_size * sizeof(double));
	B = (double*)malloc(arr_size * sizeof(double));
	A = (double*)malloc(arr_size * sizeof(double));
	check_array = (double*)malloc(50 * sizeof(double)); //just used to check arrays

	RandomizeArrays(A, B, C, arr_size);

	cout << "STARTING PROGRAM" << endl;

	clock_t t;

	t = clock();

	/* ijk */
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			register double sum = 0.0;
			for (k = 0; k < n; k++)
			{
				sum += A[i*n+k] * B[k*n+j];
			}
			C[i*n+j] = sum;
		}
	}

	t = clock() - t;

	cout << "For ijk and n size of " << n << " we have clock time of " << (double(t) / CLOCKS_PER_SEC) << endl;

	storeMax(C, check_array, 0, arr_size); //stores max of solution matrix in an array at index 0

	RandomizeArrays(A, B, C, arr_size);

	t = clock();

	/* jik */
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n; i++)
		{
			register double sum = 0.0;
			for (k = 0; k < n; k++)
			{
				sum += A[i*n + k] * B[k*n + j];
			}
			C[i*n + j] = sum;
		}
	}

	t = clock() - t;

	cout << "For jik and n size of " << n << " we have clock time of " << (double(t) / CLOCKS_PER_SEC) << endl;

	storeMax(C, check_array, 1, arr_size); //stores max of solution matrix in an array at index 0

	if (check_array[0] == check_array[1])
	{
		cout << "Correctness: TRUE" << endl;
	}
	else 
	{
		cout << "Correctness: FALSE " << endl << "first value: " << check_array[0] << endl << "second value: " << check_array[1] << endl;
	}

	RandomizeArrays(A, B, C, arr_size);

	t = clock();

	/* kij */
	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			register double r = A[i*n + k];
			for (j = 0; j < n; j++)
			{
				C[i*n + j] += r * B[k*n + j];
			}
		}
	}

	t = clock() - t;

	cout << "For kij and n size of " << n << " we have clock time of " << (double(t) / CLOCKS_PER_SEC) << endl;

	storeMax(C, check_array, 2, arr_size);

	if (check_array[1] == check_array[2])
	{
		cout << "Correctness: TRUE" << endl;
	}
	else
	{
		cout << "Correctness: FALSE " << endl << "first value: " << check_array[1] << endl << "second value: " << check_array[2] <<  endl;
	}


	RandomizeArrays(A, B, C, arr_size);
	
	t = clock();

	/* ikj */
	for (i = 0; i < n; i++)
	{
		for (k = 0; k < n; k++)
		{
			register double r = A[i*n + k];
			for (j = 0; j < n; j++)
			{
				C[i*n + j] += r * B[k*n + j];
			}
		}
	}

	t = clock() - t;
	
	cout << "For ikj and n size of " << n << " we have clock time of " << (double(t) / CLOCKS_PER_SEC) << endl;

	storeMax(C, check_array, 3, arr_size);

	if (check_array[2] == check_array[3])
	{
		cout << "Correctness: TRUE" << endl;
	}
	else
	{
		cout << "Correctness: FALSE " << endl << "first value: " << check_array[1] << endl << "second value: " << check_array[2] << endl;
	}


	RandomizeArrays(A, B, C, arr_size);

	t = clock();

	/* jki */
	for (j = 0; j < n; j++)
	{
		for (k = 0; k < n; k++)
		{
			register double r = B[k*n + j];
			for (i = 0; i < n; i++)
			{
				C[i*n + j] += A[i*n + k] * r;
			}
		}
	}

	t = clock() - t;

	cout << "For jki and n size of " << n << " we have clock time of " << (double(t) / CLOCKS_PER_SEC) << endl;

	storeMax(C, check_array, 4, arr_size);

	if (check_array[3] == check_array[4])
	{
		cout << "Correctness: TRUE" << endl;
	}
	else
	{
		cout << "Correctness: FALSE " << endl << "first value: " << check_array[1] << endl << "second value: " << check_array[2] << endl;
	}

	RandomizeArrays(A, B, C, arr_size);

	t = clock();

	/* kji */
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			register double r = B[k*n + j];
			for (i = 0; i < n; i++)
			{
				C[i*n + j] += A[i*n + k] * r;
			}
		}
	}

	t = clock() - t;

	cout << "For kji and n size of " << n << " we have clock time of " << (double(t) / CLOCKS_PER_SEC) << endl;

	storeMax(C, check_array, 5, arr_size);

	if (check_array[3] == check_array[4])
	{
		cout << "Correctness: TRUE" << endl;
	}
	else
	{
		cout << "Correctness: FALSE " << endl << "first value: " << check_array[1] << endl << "second value: " << check_array[2] << endl;
	}

}
