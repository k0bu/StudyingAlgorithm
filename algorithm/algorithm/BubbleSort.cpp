#include "pch.h"
#include <iostream>

using namespace std;

int SortingAlgorithm(int* A, int N) {
	int swapCount = 0;
	bool flag = 1;
	for (int i = 0; flag ; i++)
	{
		flag = 0;

		for ( int j = N - 1; j > i ; j--)
		{
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				flag = 1;
				swapCount++;

			}
		}
	}

	return swapCount;
}

void BubbleSort()
{
	int A[100], N, swapCount;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	swapCount = SortingAlgorithm(A, N);

	for (int i = 0; i < N; i++) {
		if (i) cout << " ";
		cout << A[i];
	}

	cout << endl;
	cout << swapCount << endl;

	return;
}