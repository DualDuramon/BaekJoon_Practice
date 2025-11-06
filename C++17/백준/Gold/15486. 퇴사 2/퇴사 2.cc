#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct schedule {
	int takeTime;
	int payment;

	schedule() {
		takeTime = 0;
		payment = 0;
	}
	schedule(int t, int p) : takeTime(t), payment(p) {}

};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	cin >> n;
	vector<schedule> pyo(n + 1);
	vector<int> dp(n + 2, 0);

	for (int i{ 1 }; i <= n; ++i) {
		cin >> pyo[i].takeTime >> pyo[i].payment;
	}

	for (int i = 0; i <= n; ++i) {
		if (i + pyo[i].takeTime <= n + 1) {
			dp[i + pyo[i].takeTime] = max(dp[i + pyo[i].takeTime], dp[i] + pyo[i].payment);
		}
		dp[i + 1] = max(dp[i + 1], dp[i]); //해당 회차를 진행하지 않았을때 건너뛰는 용
	}

	cout << *max_element(dp.begin(), dp.end()) << "\n";

	return 0;
}