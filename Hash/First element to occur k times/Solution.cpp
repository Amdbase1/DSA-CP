// C++ implementation to find first
// element occurring k times
#include <bits/stdc++.h>
using namespace std;

// Function to find the first element
// occurring k number of times
int firstElement(int arr[], int n, int k)
{
	// This loop is used for selection
	// of elements
	for (int i = 0; i < n; i++) {
		// Count how many time selected element
		// occurs
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (arr[i] == arr[j])
				count++;
		}

		// Check, if it occurs k times or not
		if (count == k)
			return arr[i];
	}

	return -1;
}

// Driver Code
int main()
{
	int arr[] = { 1, 7, 4, 3, 4, 8, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 2;
	cout << firstElement(arr, n, k);
	return 0;
}
