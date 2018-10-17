#include <ctime>
#include <iostream>
#include <iomanip>
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





double Correctness(double arr1[], double arr2[], int array_size)
{
	double tempMax = arr1[0] - arr2[0];
	for (int r = 0; r < array_size; r++)
	{
		if (tempMax > arr1[r] - arr2[r])
		{
			tempMax = arr1[r] - arr2[r];
		}
	}

	return tempMax;
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

	cout << "STARTING PROGRAM: cache blocking with block size 8 and registers!" << endl;

	clock_t t;

	t = clock();

	int block = 8; // block size


	/* ijk */

	for (i = 0; i < n; i += block)
	{
		for (j = 0; j < n; j += block)
		{
			for (k = 0; k < n; k += block)
			{
				for (int i1 = i; i1 < i + block+2; i1++)
				{
					for (int j1 = j; j1 < j + block+2; j1++)
					{
						register int t = i1 * n + j1; register int tt = t + n;
						register double c00 = C[t]; register double c01 = C[t + 1];  register double c10 = C[tt]; register double c11 = C[tt + 1];

						for (int k1 = k; k1 < k + block+2; k1++)
						{
							register int ta = i1 * n + k1; register int tta = ta + n; register int tb = k1 * n + j1; register int ttb = tb + n;
							register double a00 = A[ta]; register double a01 = A[ta + 1]; register double a10 = A[tta]; register double a11 = A[tta + 1];
							register double b00 = B[tb]; register double b01 = B[tb + 1]; register double b10 = B[ttb]; register double b11 = B[ttb + 1];
							c00 += a00 * b00 + a01 * b10;
							c01 += a00 * b01 + a01 * b11;
							c10 += a10 * b00 + a11 * b10;
							c11 += a10 * b01 + a11 * b11;
						}
						C[t] = c00;
						C[t + 1] = c01;
						C[tt] = c10;
						C[tt + 1] = c11;
					}
				}
			}
		}
	}

	t = clock() - t;

	cout << "For ijk cache block and n size of " << n << " we have clock time of " << (double(t) / CLOCKS_PER_SEC) << endl;

	return 0;
}
