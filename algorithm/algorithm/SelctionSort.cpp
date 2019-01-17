#include "pch.h"
#include <iostream>

using namespace std;

int SortAlgorithm(int* A, int N) {

	int swapCount = 0;

	for (int i = 0; i < N; i++) {
		int minIndex = i;

		for (int j = i + 1; j < N; j++) {
			if (A[j] < A[minIndex]) {
				minIndex = j;
			}
		}

		if (i != minIndex) {
			swap(A[i], A[minIndex]);
			swapCount++;
		}
		
	}


	return swapCount;
}


void SelectionSort() {

	int A[100], N, swapCount;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	swapCount = SortAlgorithm(A, N);

	for (int i = 0; i < N; i++) {
		if (i) cout << " ";
		cout << A[i];
	}

	cout << endl;
	cout << swapCount << endl;

	return;
}



