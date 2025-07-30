#include"problem.h"
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int rowDir[]{ 0,1,1,1 };
int colDir[]{ 1,-1,0,1 };

bool Problem_4883::CheckBoundary(const std::vector<std::vector<int>>& graph, int row, int col) {
	return 0 <= row && row < graph.size() && 0 <= col && col < 3;
}

int Problem_4883::CalculateCost(int n) 
{
	vector<vector<int>> graph(n, vector<int>(3, 0));
	vector<vector<int>> memo(n, vector<int>(3, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			std::cin >> graph[i][j];
		}
	}

	memo[0][0] = INT_MAX;
	memo[0][1] = graph[0][1];
	memo[0][2] = graph[0][2] + memo[0][1];

	for (int i = 1; i < n; i++) {
		memo[i][0] = std::min(memo[i - 1][0], memo[i - 1][1]) + graph[i][0];
		memo[i][1] 
			= std::min(
				std::min(memo[i - 1][0], memo[i - 1][1]), 
				std::min(memo[i - 1][2], memo[i][0])) + graph[i][1];
		memo[i][2] = std::min(std::min(memo[i - 1][1], memo[i - 1][2]), memo[i][1]) + graph[i][2];
	}

	return memo[n-1][1];
}

void Problem_4883::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	int testCase{ 0 };

	while (true) {
		std::cin >> n;
		if (n == 0) break;

		cout << ++testCase << ". " << CalculateCost(n) << endl;
	}

	//return 0;
}