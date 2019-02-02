#include "pch.h"

#include <iostream>
#include <stdio.h>

using namespace std;

int Partition(int *arr, int startIndex, int thresholdIndex) {
	int thresholdValue, iteratorIndex;
	thresholdValue = arr[thresholdIndex];
	iteratorIndex = startIndex;

	for (int i = startIndex; i < thresholdIndex; i++) {
		if (arr[i] <= thresholdValue) {
			
			swap(arr[i] , arr[iteratorIndex]);
			iteratorIndex++;
		}
	}

	//since i == thresholdIndex, arr[i] <= thresholdValue
	swap(arr[iteratorIndex], arr[thresholdIndex]);

	return iteratorIndex;
}


void PartitionSort() {

	int n, *arr;

	scanf_s("%d", &n);

	arr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	int q;

	q = Partition(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		if (i) printf(" ");
		if (i == q) printf("[");
		printf("%d", arr[i]);
		if (i == q) printf("]");
	}


	cout << endl;

	return;
}

