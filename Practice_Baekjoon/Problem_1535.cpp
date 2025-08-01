#include"problem.h"
#include<iostream>
#include<vector>

using namespace std;

//배낭문제 브루트포스 알고리즘ver.

void Problem_1535::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	cin >> n;

	vector<int> health(n + 1, 0);
	vector<int> happy(n + 1, 0);

	for (int i = 1; i <= n; i++) cin >> health[i];
	for (int i = 1; i <= n; i++) cin >> happy[i];

	vector<vector<int>> memo(n + 1, std::vector<int>(101, 0));

	//i = 얻을 hppay, j = 남은 체력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < 100; j++) {
			if (health[i] > j) memo[i][j] = memo[i - 1][j]; //이번에 받을 happy에 대한 소비체력이 기존 체력보다 높으면 -> 못하는거 -> 이전까지 저장해놓은 nowHappy값 저장
			else //이번 happy를 담을 때
			{
				memo[i][j] = std::max(memo[i - 1][j], memo[i - 1][j - health[i]] + happy[i]);
			}
		}
	}

	cout << memo[n][99] << "\n";
}