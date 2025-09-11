#include"problem.h"
#include<iostream>

using namespace std;

static int cnt = 0, n;
static long long ans = -1;

void Problem_1038::BackTracking(long long num, int size) {

	if (size == 1) {
		if (cnt == n) {
			ans = num;
		}
		cnt++;
		return;
	}

	int last = num % 10;
	if (last == 0) return;

	for (int i = 0; i < last; i++) {
		long long nextNum = num * 10 + i;
		BackTracking(nextNum, size - 1);
	}
}

void Problem_1038::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;

	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < 10; j++) {
			BackTracking(j, i);
		}
	}

	cout << ans << endl;
}