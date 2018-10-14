#include "cstdlib"
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


	t = clock();

	for (i = 0; i < n; i += 2)
		for (j = 0; j < n; j += 2) {
			for (k = 0; k < n; k += 2) {
				/* 2 by 2 mini matrix multiplication using registers*/
				register int ta = i * n + k; register int tta = ta + n; register int tb = k * n + j; register int ttb = tb + n;
				register double a00 = A[ta]; register double a01 = A[ta + 1]; register double a10 = A[tta]; register double a11 = A[tta + 1];
				register double b00 = B[tb]; register double b01 = B[tb + 1]; register double b10 = B[ttb]; register double b11 = B[ttb + 1];
				C[i*n+j] += a00 * b00 + a01 * b10;
				C[(i*n+j) + 1] += a00 * b01 + a01 * b11;
				C[(i*n+j)+n] += a10 * b00 + a11 * b10;
				C[((1*n+j)+n) + 1] += a10 * b01 + a11 * b11;
			}
			C[i*n+j] = C[i*n + j];
			C[(i*n+j) + 1] = C[(i*n + j) + 1];
			C[(i*n+k)+n] = C[(i*n + j) + n];
			C[((i*n+j)+n) + 1] = C[((i*n + j) + n) + 1];
		}
	t = clock() - t;

	cout << "For dgemm3 and n size of " << n << " we have clock time of " << (double(t) / CLOCKS_PER_SEC) << endl;

	/* Multiply n x n matrices a and b  */
	
}
