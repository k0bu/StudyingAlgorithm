#include "pch.h"
#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX 200000
#define SENTINEL 2000000000

typedef long long llong;


llong MergeReverseCount (int *input, int left, int mid, int right) {
	int L[MAX / 2 + 2], R[MAX / 2 + 2];
	llong cnt = 0;
	int n1 = mid - left;
	int n2 = right - mid;

	for (int i = 0; i < n1; i++) {
		L[i] = input[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = input[mid + i];
	}

	L[n1] = R[n2] = SENTINEL;

	for (int k = left, i = 0,j = 0; k < right; k++) {
		if (L[i] <= R[j]) {
			input[k] = L[i++];
		}
		else {
			input[k] = R[j++];
			cnt += n1 - i;
		}

	}


	return cnt;
}

llong MergeSortReverseCount (int *input, int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		llong v1, v2, v3;

		v1 = MergeSortReverseCount (input, left, mid);
		v2 = MergeSortReverseCount (input, mid, right);
		v3 = MergeReverseCount(input, left, mid, right);
		
	return v1 + v2 + v3;
	}
	
	return 0;
}



void NumberOfInversion () {

	int *input, n;

	scanf_s("%d", &n);
	input = new int[n];

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &input[i]);
	}

	llong ans = MergeSortReverseCount(input, 0, n);
	
	cout << ans << endl;

	return;
}