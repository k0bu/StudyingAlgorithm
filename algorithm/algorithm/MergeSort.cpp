#include "pch.h"

#include <iostream>

using namespace std;

#define MAX 500000
#define SENTINEL 2000000000

int L[MAX / 2 + 2], R[MAX / 2 + 2];
int cnt = 0;

void Merge(int A[], int n, int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;

	for (int i = 0; i < n1; i++) L[i] = A[left + i];
	for (int i = 0; i < n2; i++) R[i] = A[mid + i];

	L[n1] = R[n2] = SENTINEL;
	int i = 0, j = 0;

	for (int k = left; k < right; k++) {
		cnt++;
		if (L[i] <= R[j]) {
			A[k] = L[i++];
		}
		else {
			A[k] = R[j++];
		}
	}
}

void Sort(int A[], int n, int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		Sort(A, n, left, mid);
		Sort(A, n, mid, right);
		Merge(A, n, left, mid, right);
	}
}


void MergeSort() {
	int *A, n, i;
	cnt = 0;

	scanf_s("%d", &n);
	A = new int[n];
	for(i = 0; i < n; i++) scanf_s("%d", &A[i]);

	Sort(A, n, 0, n);

	for (i = 0; i < n; i++) {
		if (i) printf(" ");
		printf("%d", A[i]);
	}

	printf("\n");

	cout << cnt << endl;


	return;
}









