#include"problem.h"
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void Problem_11866::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 }, k{ 0 };
	cin >> n >> k;

	vector<int> result(n, -1);
	int idx = 0;
	queue<int> mq;

	for (int i = 1; i <= n; i++) {
		mq.push(i);
	}

	while (!mq.empty()) {
		for (int i = 0; i < k - 1; i++) {
			int top = mq.front();
			mq.pop();
			mq.push(top);
		}
		result[idx++] = mq.front();
		mq.pop();
	}

	cout << "<";
	for (int i = 0; i < n-1; i++) {
		cout << result[i] << ", ";
	}

	cout << result[idx-1]<< ">" << endl;
}