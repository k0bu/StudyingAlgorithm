#include "pch.h"
#include <stdio.h>

#define MAX 100000

typedef long long ll;
int weightsNumber, truckNumber;
ll weights[MAX];

int Check(ll P) {
	int i = 0;
	for (int j = 0; j < truckNumber; j++) {
		ll s = 0;
		while (s + weights[i] <= P) {
			s += weights[i];
			i++;
			if (i == weightsNumber) return weightsNumber;
		}

	}
	return i;
}

int Solve() {
	ll left = 0;
	ll right = MAX * MAX;
	ll mid;
	
	while (right - left > 1) {
		mid = (left + right) / 2;
		int v = Check(mid);
		if (v >= weightsNumber) {
			right = mid;
		}
		else {
			left = mid;
		}
	}

	return right;
}

void Allocation() {

	scanf_s("%d %d", &weightsNumber, &truckNumber);

	for (int i = 0; i < weightsNumber; i++) {
		scanf_s("%d", &weights[i]);
	}

	ll ans = Solve();

	printf("%d\n", ans);

	return;
}