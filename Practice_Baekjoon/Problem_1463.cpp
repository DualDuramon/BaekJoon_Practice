#include"problem.h"
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

//int main() {
void Problem_1463::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	cin >> n;

	vector<int> dp(n + 1, INT_MAX);
	dp[n] = 0;

	for (int i = n; i >= 2; i--) {
		dp[i - 1] = std::min(dp[i] + 1, dp[i - 1]);
		if (i % 3 == 0) dp[i/3] = std::min(dp[i] + 1, dp[i / 3]);
		if (i % 2 == 0) dp[i/2] = std::min(dp[i] + 1, dp[i / 2]);
	}

	cout << dp[1] << endl;
	//return 0;
}
