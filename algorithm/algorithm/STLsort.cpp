#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>


using namespace std;


void STLsort () {

	int n;
	vector<int> vec;
	//int *arr;

	cin >> n;
	//arr = new int[n];

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
		//arr[i] = x;
	}

	sort(vec.begin(), vec.end());
	//sort(arr, arr + n );

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
	//for (int i = 0; i < vec.size (); i++) {
	//	cout << arr[i] << " ";
	//}
	//cout << endl;

	return;
}