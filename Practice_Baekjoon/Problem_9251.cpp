#include"problem.h"
#include<iostream>
#include<vector>

using namespace std;

void Problem_9251::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string str1, str2;
	cin >> str1 >> str2;

	vector<vector<int>> dp(1001, vector<int>(1001, 0));

	for (int i = 1; i <= str2.length(); i++) {
		for (int j = 1; j <= str1.length(); j++) {
			if (str2[i - 1] == str1[j - 1]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + 1);
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}

		}
	}

	cout << dp[str2.length()][str1.length()] << endl;
}