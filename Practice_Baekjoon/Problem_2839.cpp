#include"problem.h"
#include<vector>
#include<iostream>

using namespace std;

void Problem_2839::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	cin >> n;

	const int max = 10001;
	vector<int> vec(n + 1, max);

	vec[0] = 0;
	vec[3] = 1;

	for (int i = 5; i <= n; i++) {
		vec[i] = min(vec[i - 3] + 1, vec[i - 5] + 1);
	}

	cout << ((vec[n] >= max) ? vec[n] : -1) << endl;
}