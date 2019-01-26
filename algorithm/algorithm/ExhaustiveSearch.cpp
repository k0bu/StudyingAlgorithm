#include "pch.h"
#include <iostream>

int n, array[50];

bool Solve(int i, int m) {
	if (m == 0) return true;
	if (i >= n || m < 0) return false;
	bool res = Solve(i + 1, m) || Solve(i + 1, m - array[i]);
	return res;
}


//complete and including everything: exhaustive
void ExhaustiveSearch() {

	int q, M, i;

	scanf_s("%d", &n);
	for (i = 0; i < n; i++) {
		scanf_s("%d", &array[i]);
	}

	scanf_s("%d", &q);
	for (i = 0; i < q; i++) {
		scanf_s("%d", &M);

		if (Solve(0, M)) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}

	}


	return;
}


