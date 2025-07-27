#include "problem.h"
#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> dot;
int rowDir[4] = { 0 , 0 , 1, -1 };
int colDir[4] = { 1 , -1 , 0 , 0 };

bool Problem_1103::CheckBound(const vector<vector<char>>& map, int row, int col) {
	if (0 <= row && row < map.size() && 0 <= col && col < map[0].size()) {
		return map[row][col] != 'H' ? true : false;
	}
	else return false;
}

int Problem_1103::DFS(const vector<vector<char>>& map, vector<vector<int>>&lengthMap, vector<vector<bool>>& visited, int row, int col) {
	if (lengthMap[row][col] != 0) return lengthMap[row][col] + 1;

	visited[row][col] = true;
	for (int i = 0; i < 4; i++) {
		int nextRow = row + (map[row][col] - '0') * rowDir[i];
		int nextCol = col + (map[row][col] - '0') * colDir[i];

		if (CheckBound(map, nextRow, nextCol)) {
			if (visited[nextRow][nextCol]) {
				visited[row][col] = false;
				return lengthMap[row][col] = -1;
			}
			//if (lengthMap[nextRow][nextCol] > lengthMap[row][col] + 1) continue; //여기가 문제였다.
			
			int result = DFS(map, lengthMap, visited, nextRow, nextCol);
			if (result == -1) {
				visited[row][col] = false;
				return lengthMap[row][col] = -1;
			}
			lengthMap[row][col] = max(lengthMap[row][col], result);
		}
	}
	visited[row][col] = false;

	return lengthMap[row][col] + 1;
}

void Problem_1103::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 }, m{ 0 };
	cin >> n >> m;

	vector<vector<char>> map(n, vector<char>(m, '0'));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}

	vector<vector<int>> lengthMap(n, vector<int>(m, 0));
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	int result = DFS(map, lengthMap, visited, 0, 0);

	cout << result << "\n";
}