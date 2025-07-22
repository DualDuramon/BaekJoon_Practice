#include"problem.h"
#include <iostream>

/*
* 링크 : https://www.acmicpc.net/problem/11727
* 티어 : 실버 III
*/

using namespace std;

void Problem_11727::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n{ 0 };
	std::cin >> n;

	vector<int> dp(n, 0);
	
	dp[0] = 1;
	dp[1] = 3;

	for (int i = 2; i < n; i++) {
		dp[i] = (dp[i - 2] + 2 + dp[i - 1]) % 10007;
	}

	std::cout << dp[n - 1] << std::endl;

};