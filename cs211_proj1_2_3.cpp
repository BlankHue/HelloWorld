#include <ctime>
#include <iostream>
#include <cstdlib>



using namespace std;



void RandomizeArrays(double arr1[], double arr2[], int array_size)
{

	int m = 0;

	for (m = 0; m < array_size; ++m)
	{
		srand(1);
		arr1[m] = rand() % 100;
		arr2[m] = rand() % 100;
	}
}


void checkArrays(double arr1[], double arr2[], int array_size)
{
	/* takes in the same arrays and checks if element to element similarity*/
	int r = 0;
	bool ArraysSame = true;
	for (r = 0; r < array_size; r++)
	{
		if (arr1[r] == arr2[r])
		{
			continue;
		}
		else
		{
			ArraysSame = false;
		}
	}

	if (ArraysSame)
	{
		cout << "Correction test passed" << endl;
	}
	else
	{
		cout << "Correction test failed" << endl;
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

	double ijk_solution[arr_size]; 
	ijk_solution = C; //saves the solution for ijk

	RandomizeArrays(A, B, arr_size);

	t = clock();

	/* jik */
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n; i++)
		{
			register double sum = 0.0;
			for (k = 0; k < n; k++)
			{
				sum += A[j*n + i] * B[k*i + k];
			}
			C[j*n + i] = sum;
		}
	}

	t = clock() - t;

	cout << "For jik and n size of " << n << " we have clock time of " << (double(t) / CLOCKS_PER_SEC) << endl;

	cout << "Correctness between these two solutions is: ";
	checkArrays(ijk_solution, C, arr_size);
}
