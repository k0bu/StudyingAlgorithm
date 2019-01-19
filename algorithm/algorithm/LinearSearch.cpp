#include "pch.h"
#include <iostream>
#include "stdio.h"

int IsInArray(int *A, int n, int key) {
	int i = 0;
	A[n] = key;
	while (A[i] != key) {
		i++;
	}
	return i != n;
}


void LinearSearch() {
	int arraySize, *A, searchingKeysSize, key, sum = 0;

	scanf_s("%d", &arraySize);
	A = new int[arraySize];
	for (int i = 0; i < arraySize; i++) scanf_s("%d", &A[i]);

	scanf_s("%d", &searchingKeysSize);
	for (int i = 0; i < searchingKeysSize; i++) {
		scanf_s("%d", &key);
		if (IsInArray(A, arraySize, key)) {
			sum++;
		}
	}

	printf("%d\n", sum);

	return;
}