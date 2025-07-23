#include"problem.h"
#include<iostream>
#include<cmath>
#include<vector>
#include<climits>

/*
* 문제 : https://www.acmicpc.net/problem/9020
* 티어 : 실버II
*/

using namespace std;

void Problem_9020::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	cin >> n;

	for (int i = 0; i < n; i++) {
		Solving();
		cout << "\n";
	}
}

void Problem_9020::Solving() {
	int num{ 0 };
	cin >> num;

	vector<bool> sosuList(num + 1, true);
	sosuList[1] = sosuList[0] = false;

	size_t sqrtNum = static_cast<size_t> (sqrt(num));

	for (size_t i{ 2 }; i < sqrtNum + 1; i++) {
		if (!sosuList[i]) continue;

		for (size_t j{ 2 }; j <= num / i; j++) {
			sosuList[i * j] = false;
		}
	}

	for (size_t i = num / 2; 2 <= i; i--)
	{
		if (sosuList[num - i] && sosuList[i])
		{
			cout << i << " " << num - i;
			break;
		}
	}
}