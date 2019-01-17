#include "pch.h"
#include <iostream>

using namespace std;

void Trace(int* A, int N) {
	for (int i = 0; i < N; i++)
	{
		if (i > 0) cout << " ";
		cout << A[i];
	}

	cout << "\n";
}

void SortingAlgorithm(int* A, int N) {
	int j, i, v;
	for (i = 1; i < N; i++)
	{
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		Trace(A, N);
	}
}

void InsertionSort()
{
	int A[100], N, i;

	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	Trace(A, N);
	SortingAlgorithm(A, N);

	return;

}