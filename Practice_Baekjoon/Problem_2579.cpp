#include"problem.h"
#include<iostream>
#include<vector>

/*
* 문제 : https://www.acmicpc.net/problem/2579
* 티어 : 실버III
*/

void Problem_2579::Solution()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n{ 0 };
	std::cin >> n;
	std::vector<int> stair(n+1, 0);
	std::vector<int> dp(n + 1, 0);


	for (int i = 1; i <= n; i++) {
		std::cin >> stair[i];
	}

	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = std::max(dp[i - 3] + stair[i - 1] + stair[i], dp[i - 2] + stair[i]);
	}

	std::cout << dp[n] << std::endl;
}