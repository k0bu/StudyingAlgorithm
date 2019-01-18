#include "pch.h"
#include <iostream>
#include "stdio.h"
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void AreasDiagram() {
	stack<int> leftDash;
	stack< pair<int, int> > dashArea;
	char inputDash;
	int sum = 0;

	for (int i = 0; inputDash = getchar() ; i++) {
		if (inputDash == '\n') break;
		if (inputDash == '\\') {
			leftDash.push(i);
		}
		else if (inputDash == '/' && leftDash.size() > 0) {
			int j = leftDash.top();
			leftDash.pop();
			sum += i - j;
			int a = i - j;

			while (dashArea.size() > 0 && dashArea.top().first > j) {
				a += dashArea.top().second;
				dashArea.pop();
			}

			dashArea.push(make_pair(j, a));
		}
	}

	vector<int> ans;
	while (dashArea.size() > 0) {
		ans.push_back(dashArea.top().second);
		dashArea.pop();

	}
	reverse(ans.begin(), ans.end());
	cout << sum << endl;
	cout << ans.size();

	for (int i = 0; i < ans.size(); i++) {
		cout << " ";
		cout << ans[i];
	}

	cout << endl;

	return;
}