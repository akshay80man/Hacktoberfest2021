// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the absolute difference
// between the XOR of non-primes and the
// XOR of primes in the given array
int calculateDifference(int arr[], int n)
{

	// Find maximum value in the array
	int max_val = *max_element(arr, arr + n);

	// USE SIEVE TO FIND ALL PRIME NUMBERS LESS
	// THAN OR EQUAL TO max_val
	// Create a boolean array "prime[0..n]". A
	// value in prime[i] will finally be false
	// if i is Not a prime, else true.
	vector<bool> prime(max_val + 1, true);

	// Remaining part of SIEVE
	prime[0] = false;
	prime[1] = false;
	for (int p = 2; p * p <= max_val; p++) {

		// If prime[p] is not changed, then
		// it is a prime
		if (prime[p] == true) {

			// Update all multiples of p
			for (int i = p * 2; i <= max_val; i += p)
				prime[i] = false;
		}
	}

	// Store the XOR of primes in X1 and
	// the XOR of non primes in X2
	int X1 = 1, X2 = 1;
	for (int i = 0; i < n; i++) {

		if (prime[arr[i]]) {

			// The number is prime
			X1 ^= arr[i];
		}
		else if (arr[i] != 1) {

			// The number is non-prime
			X2 ^= arr[i];
		}
	}

	// Return the absolute difference
	return abs(X1 - X2);
}

// Driver code
int main()
{
	int arr[] = { 1, 3, 5, 10, 15, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Find the absolute difference
	cout << calculateDifference(arr, n);

	return 0;
}
