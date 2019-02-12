#include "pch.h"
#include <stdio.h>
#include <iostream>

#define MAX 100000
#define SENTINEL 2000000000

using namespace std;

struct Card {
	char suit;
	int value;
};



void Merge(Card *arr, int left, int mid, int right) {
	Card L[MAX / 2 + 2], R[MAX / 2 + 2];

	int n1 = mid - left;
	int n2 = right - mid;

	for (int i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = arr[mid + i];
	}

	L[n1].value = R[n2].value = SENTINEL;

	for (int k = left, i = 0, j = 0 ; k < right; k++) {
		if (L[i].value <= R[j].value) {
			arr[k] = L[i++];
		}
		else {
			arr[k] = R[j++];
		}
	}

}

void MergeSortQuick(Card *arr, int left, int right) {
	int mid;
	if (left + 1 < right) {
		mid = (left + right) / 2;
		MergeSortQuick(arr, left, mid);
		MergeSortQuick(arr, mid, right);
		Merge(arr, left, mid, right);
	}
}

int Partition(Card *arr, int startIndex, int thresholdIndex) {
	int thresholdValue, iteratorIndex;
	thresholdValue = arr[thresholdIndex].value;
	iteratorIndex = startIndex;

	for (int i = startIndex; i < thresholdIndex; i++) {
		if (arr[i].value <= thresholdValue) {

			swap(arr[i], arr[iteratorIndex]);
			iteratorIndex++;
		}
	}

	//since i == thresholdIndex, arr[i] <= thresholdValue
	swap(arr[iteratorIndex], arr[thresholdIndex]);

	return iteratorIndex;
}


void Sort(Card *arr, int left, int right) {
	int q;
	if (left < right) {
		q = Partition(arr, left, right);
		Sort(arr, left, q - 1);
		Sort(arr, q + 1, right);
	}
}

void QuickSort() {

	int n, value;
	Card *A, *B;
	char suit[10];
	int stable = 1;

	scanf_s("%d", &n);
	A = new Card[n]; B = new Card[n];

	for (int i = 0; i < n; i++) {
		scanf_s("%s %d", suit, 10, &value);
		A[i].suit = B[i].suit = suit[0];
		A[i].value = B[i].value = value;
	}

	MergeSortQuick(A, 0, n);
	Sort(B, 0, n - 1);

	for (int i = 0; i < n; i++) {
		if (A[i].suit != B[i].suit) {
			stable = 0;
		}
	}

	if (stable == 1) {
		printf("Stable\n");
	}
	else {
		printf("Not stable\n");
	}

	for (int i = 0; i < n; i++) {
		printf("%c %d\n", B[i].suit, B[i].value);
	}
	//for (int i = 0; i < n; i++) {
	//	printf("%c %d\n", A[i].suit, A[i].value);
	//}


	return;
}
