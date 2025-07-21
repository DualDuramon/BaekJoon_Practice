#include "problem.h"
#include<iostream>
#include<cstdlib>
#include<vector>

/*
* 링크 : https://www.acmicpc.net/problem/11726
* 티어 : 실버 III
*/

using namespace std;

void Problem_11726::Solution() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	cin >> n;

	vector<long> dp(n + 1, 0);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	std::cout << dp[n] << std::endl;
}