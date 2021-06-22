//******-> haithem ben abdelaziz: haithem.ben.abdelaziz@gmail.com

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum length
// of the required sub-array
int maxLength(int arr[], int n)
{
	int maxLen = 0;

	// For the first consecutive
	// pair of elements
	int i = 0;
	int j = i + 1;

	// While a consecutive pair
	// can be selected
	while (j < n) {

		// If current pair forms a
		// valid sub-array
		if (arr[i] != arr[j]) {

			// 2 is the length of the
			// current sub-array
			maxLen = max(maxLen, 2);

			// To extend the sub-array both ways
			int l = i - 1;
			int r = j + 1;

			// While elements at indices l and r
			// are part of a valid sub-array
			while (l >= 0 && r < n && arr[l] == arr[i]
				&& arr[r] == arr[j]) {
				l--;
				r++;
			}

			// Update the maximum length so far
			maxLen = max(maxLen, 2 * (r - j));
		}

		// Select the next consecutive pair
		i++;
		j = i + 1;
	}

	// Return the maximum length
	return maxLen;
}

// Driver code
int main()
{
	int arr[] = { 1, 1, 1, 0, 0, 1, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << maxLength(arr, n);

	return 0;
}
