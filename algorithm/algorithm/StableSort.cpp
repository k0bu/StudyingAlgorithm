#include "pch.h"
#include <iostream>

using namespace std;

struct Card {
	char suit, value;
};


void Bubble(struct Card* A, int N) {
	for (int i = N - 1; i > -1; i--) {
		bool noSwapDone = true;
		for (int j = 0; j < i; j++) {
			if (A[j].value > A[j + 1].value) {
				swap(A[j], A[j + 1]);
				noSwapDone = false;
			}
		}
		if (noSwapDone) break;
	}

}

void Selection(struct Card* A, int N) {
	for (int i = 0; i < N; i++) {
		int minIndex = i;
		for (int j = i; j < N; j++) {
			if (A[j].value < A[minIndex].value) minIndex = j;
		}
		if (i != minIndex) swap(A[i], A[minIndex]);
	}

}

void ConsolePrinter(struct Card* A, int N) {
	for (int i = 0; i < N; i++)
	{
		if (i) cout << " ";
		cout << A[i].suit << A[i].value;
	}
	cout << endl;
}

bool isSortStable(struct Card* StableCards, struct Card* CheckingCards, int N) {
	for (int i = 0; i < N; i++) {
		if (StableCards[i].suit != CheckingCards[i].suit) return false;
	}
	return true;
}

void StableSort() {
	Card C1[100], C2[100];
	int N;
	char ch;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> C1[i].suit >> C1[i].value;
	}

	for (int i = 0; i < N; i++) C2[i] = C1[i];

	Bubble(C1, N);
	Selection(C2, N);

	ConsolePrinter(C1, N);
	cout << "Stable" << endl;

	ConsolePrinter(C2, N);
	if (isSortStable(C1, C2, N)) {
		cout << "Stable" << endl;
	}
	else {
		cout << "Not stable" << endl;
	}

	return;

}

