#include "pch.h"
#include <stdio.h>
#include <iostream>

#define MAX 100000

using namespace std;

struct Card {
	char suit;
	int value;
};

Card L[MAX / 2 + 2], R[MAX / 2 + 2];

void Merge(Card *arr, int n, int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;

	for (int i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = arr[mid + i];
	}


	for (int k = left, i = 0, j = 0 ; k < right; k++) {
		if (L[i].value <= R[j].value) {
			arr[k] = L[i++];
		}
		else {
			arr[k] = R[j++];
		}
	}

}

void MergeSortQuick(Card *arr, int n, int left, int right) {
	int mid;
	if (left + 1 < right) {
		mid = (left + right) / 2;
		MergeSortQuick(arr, n, left, mid);
		MergeSortQuick(arr, n, mid, right);
		Merge(arr, n, left, mid, right);
	}
}






void QuickSort() {






	return;
}
