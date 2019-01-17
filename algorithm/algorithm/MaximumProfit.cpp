// pch.cpp: プリコンパイル済みヘッダーに対応するソース ファイル。コンパイルが正常に実行されるために必要です

#include "pch.h"
#include <iostream>

using namespace std; //::cin,cout
static const int MAX = 200000;

void MaximumProfit()
{
	int R[MAX], n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> R[i];
	}

	int maxv = -2000000000;
	int minv = R[0];

	for (int i = 1; i < n; i++)
	{
		maxv = (maxv > R[i] - minv) ? maxv : R[i] - minv;
		minv = (minv < R[i]) ? minv : R[i];
	}

	cout << maxv << endl; //endl is to output CRLF and flush the buffer

}

// 一般に、このファイルは無視できますが、プリコンパイル済みヘッダーを使用している場合は保持します。
