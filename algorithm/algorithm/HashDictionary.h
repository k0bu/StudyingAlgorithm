#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>

#define M 1046527
#define NIL (-1)
#define L 14

class HashDictionary
{
private:
	char **hash;
public:
	HashDictionary() {
		//using STL vector should be better
		//vector< vector<int> > arr;
		//arr.resize(M);
		//arr[i].resize(L);
		hash = new char*[M];

		for (int i = 0; i < M; i++) {
			hash[i] = new char[L];
			hash[i][0] = '\0';
		}
	}

	int CharToInt(char ch) {
		if (ch == 'A') return 1;
		else if (ch == 'G') return 2;
		else if (ch == 'C') return 3;
		else if (ch == 'T') return 4;
		else return 0;
	}

	long long GetKeyFromStr(char *str) {
		long long keySum = 0, p = 1, i;
		for (i = 0; i < strlen(str); i++) {
			keySum += p * (CharToInt(str[i]));
			p *= 5;
		}

		return keySum;
	}

	long long H1(long long key) { return key % M; }
	long long H2(long long key) { return 1 + (key % (M - 1)); }

	int FindFromHash(char *searchingStr) {
		long long key, i, h;
		key = GetKeyFromStr(searchingStr);
		for (i = 0; i < M ; i++) {
			h = ( H1(key) + i * H2(key) ) % M;
			if (strcmp(hash[h], searchingStr) == 0) return 1;
			else if (strlen(hash[h]) == 0) return 0;
		}
		return 0;
	}

	int Insert(char *insertStr) {
		long long key, i, h;
		key = GetKeyFromStr(insertStr);
		for (i = 0; i < M; i++) {
			h = (H1(key) + i * H2(key)) % M;
			if (strcmp(hash[h], insertStr) == 0) return 1;
			else if (strlen(hash[h]) == 0) {
				strcpy_s( hash[h], L, insertStr);
				return 0;
			}
		}
		return 0;
	}



	~HashDictionary() {
		for (int i = 0; i < M; i++) {
			delete[] hash[i];
			hash[i] = 0;
		}
		delete[] hash;
		hash = 0;
	}
};