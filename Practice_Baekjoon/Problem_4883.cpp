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
	vector<vector<long>> memo(n, vector<long>(3, 1001));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			std::cin >> graph[i][j];
		}
	}

	memo[0][1] = graph[0][1];
	memo[0][2] = graph[0][2] + memo[0][1];
	memo[1][0] = graph[1][0] + memo[0][1];
	memo[1][1] = std::min(graph[1][1] + memo[0][1], graph[1][1] + memo[0][2]);
	memo[1][2] = std::min(graph[1][2] + memo[0][1], graph[1][2] + memo[0][2]);

	for (int row = 1; row < n; row++) {
		for (int col = 0; col < 3; col++) {
			for (int i = 0; i < 4; i++) {
				int nRow = row + rowDir[i];
				int nCol = col + colDir[i];

				if (!CheckBoundary(graph, nRow, nCol)) continue;
				memo[nRow][nCol] 
					= (memo[nRow][nCol] == 1001) ? memo[row][col] + graph[nRow][nCol]: std::min(memo[nRow][nCol], memo[row][col] + graph[nRow][nCol]);
			}
		}
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