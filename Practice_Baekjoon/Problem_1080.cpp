#include "problem.h"
#include<iostream>
#include <vector>

using namespace std;

bool Problem_1080::CheckAnswer(const std::vector<std::vector<bool>>& map, const std::vector<std::vector<bool>>& answer) {
	return false;
}


void Problem_1080::Calculate(const std::vector<std::vector<bool>>& map, const std::vector<std::vector<bool>>& answer, int startRow, int startCol) {

}

void Problem_1080::ChangeMap(vector<vector<bool>>& map, int row, int col) {
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			map[row + i][col + j] = !map[row + i][col + j];
		}
	}
}

void Problem_1080::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 }, m{ 0 };
	cin >> n >> m;

	vector<vector<bool>> map(n, vector<bool>(m));
	vector<vector<bool>> ans(n, vector<bool>(m));

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < m; j++) {
			map[i][j] = input[j] == '0' ? false : true;
		}
	}
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < m; j++) {
			ans[i][j] = input[j] == '0' ? false : true;
		}
	}

	int count = 0;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (map[i - 1][j - 1] != ans[i - 1][j - 1]) {
				ChangeMap(map, i, j);
				count++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != ans[i][j]) {
				cout<<"-1\n";
				return;
			}
		}
	}

	cout << count << "\n";
}