#include"problem.h"
#include<iostream>
#include<algorithm>

/*
* 문제 : https://www.acmicpc.net/problem/11053
* 티어 : 실버II
*/

void Problem_11053::Solution() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n{ 0 };
	std::cin >> n;

	std::vector<int> vec(n, 0);
	std::vector<int> dp(n, 1);

	for (auto& num : vec) {
		std::cin >> num;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (vec[i] < vec[j]) {
				dp[j] = std::max(dp[i] + 1, dp[j]);
			}
		}
	}


	std::cout << *std::max_element(dp.begin(), dp.end()) << std::endl;

}