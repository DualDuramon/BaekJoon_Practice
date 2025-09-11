#include"problem.h"
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void Problem_1149::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n{ 0 };
	cin >> n;

	vector<vector<int>> costMap(n, vector<int>(3, 0));
	vector<vector<int>> totalCostMap(n, vector<int>(3, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> costMap[i][j];
		}
	}

	totalCostMap[0][0] = costMap[0][0];
	totalCostMap[0][1] = costMap[0][1];
	totalCostMap[0][2] = costMap[0][2];


	for (int i = 1; i < n; i++) {
		totalCostMap[i][0] = costMap[i][0] + std::min(totalCostMap[i-1][1], totalCostMap[i-1][2]);
		totalCostMap[i][1] = costMap[i][1] + std::min(totalCostMap[i-1][0], totalCostMap[i-1][2]);
		totalCostMap[i][2] = costMap[i][2] + std::min(totalCostMap[i-1][1], totalCostMap[i-1][0]);
	}

	cout << min(totalCostMap[n - 1][0], min(totalCostMap[n - 1][1], totalCostMap[n - 1][2])) << endl;
}