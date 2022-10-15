// C++ program to calculate minimum sum of product
// of two arrays.
#include <bits/stdc++.h>
using namespace std;

// Returns minimum sum of product of two arrays
// with permutations allowed
long long int minValue(int A[], int B[], int n)
{
	// Sort A and B so that minimum and maximum
	// value can easily be fetched.
	sort(A, A + n);
	sort(B, B + n);

	// Multiplying minimum value of A and maximum
	// value of B
	long long int result = 0;
	for (int i = 0; i < n; i++)
		result += (A[i] * B[n - i - 1]);

	return result;
}

// Driven Code
int main()
{
	int A[] = { 3, 1, 1 };
	int B[] = { 6, 5, 4 };
	int n = sizeof(A) / sizeof(A[0]);
	cout << minValue(A, B, n) << endl;
	return 0;
}
