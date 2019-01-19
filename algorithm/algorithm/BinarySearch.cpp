#include "pch.h"
#include <iostream>
#include "stdio.h"

int BinarySearchArray(int *A, int arraySize, int key) {
	int left = 0;
	int right = arraySize;
	int mid;

	while (left < right) {
		mid = (left + right) / 2;
		if (key == A[mid]) return 1;
		if (key > A[mid]) left = mid + 1;
		if (key < A[mid]) right = mid;
	}

	return 0;
}



void BinarySearch() {
	int arraySize, *A, searchKeysSize, key, foundSum = 0;

	scanf_s("%d", &arraySize);
	A = new int[arraySize + 1];
	for (int i = 0; i < arraySize; i++) {
		scanf_s("%d", &A[i]);
	}

	scanf_s("%d", &searchKeysSize);
	for (int i = 0; i < searchKeysSize; i++) {
		scanf_s("%d", &key);
		foundSum += BinarySearchArray(A, arraySize, key);
	}

	printf("%d\n", foundSum);

	return;
}