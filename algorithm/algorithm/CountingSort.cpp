#include "pch.h"
#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX 2000001
#define VMAX 10000



void CountingSort () {
	unsigned short *inputArray, *outputArray;

	int buckets[VMAX + 1];

	int n;
	scanf_s("%d", &n);

	inputArray = new unsigned short[n];
	outputArray = new unsigned short[n + 1];

	for (int i = 0; i <= VMAX; i++) {
		buckets[i] = 0;
	}

	//0 in the outputArray is acting like threshold value.
	//if 0 was in the input array, the buckets[0] == 1,
	//but if there wasn't any, it will be bucket[0] == 0.
	//If the value in the buckets is 0, then there hasn't been any index in the input, even still up to that index.
	//So there won't be any timing that outputArray[0] will be changed, in the calculating back time.

	for (int i = 0; i < n; i++) {
		scanf_s("%hu", &inputArray[i]);
		buckets[inputArray[i]]++;
	}

	//Accumulating the count, making bucket as cumulative array
	for (int i = 1; i <= VMAX; i++) {
		buckets[i] = buckets[i] + buckets[i - 1];
	}

	for (int i = 0; i < n; i++) {
		outputArray[buckets[inputArray[i]]] = inputArray[i];
		buckets[inputArray[i]]--;
	}

	for (int i = 1; i < n + 1; i++) {
		if (i > 1) printf(" ");

		printf("%d",outputArray[i]);

	}

	cout << endl;

	return;
}
