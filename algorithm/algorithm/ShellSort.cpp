#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;

vector<int> intervalVector;
long long swapCount;

void Insertion(int* A, int N, int interval) {

	for (int i = interval; i < N; i++) {
		int targetValue = A[i];
		int j = i - interval;

		while (A[j] > targetValue) {
			swap(A[j + interval], A[j]);
			j -= interval;
			swapCount++;
			if (j < 0) break;
		}
	}
	return;
}

void Shell(int* A, int N) {

	for (int i = 1; i <= N; i = i * 3 + 1) intervalVector.push_back(i);

	for (int i = intervalVector.size() - 1; i >= 0; i--) Insertion(A, N, intervalVector[i]);

	return;
}



void ShellSort() {


	int* A = new int[1000000];
	int N;
	swapCount = 0;

	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	
	Shell(A, N);

	cout << intervalVector.size() << endl;
	for (int i = intervalVector.size() - 1; i >= 0; i--) {
		cout << intervalVector[i];
		if (i) cout << " ";
	}

	cout << "\n";
	cout << swapCount << endl;

	for (int i = 0; i < N; i++) cout << A[i] << "\n";

	delete[] A;

	return;
}