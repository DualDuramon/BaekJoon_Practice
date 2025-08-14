#include"problem.h"
#include<iostream>
#include<vector>

using namespace std;

int rDir[] = { -1, 1, 0, 0 };
int cDir[] = { 0 , 0, -1, 1 };

bool Problem_21736::canMove(const std::vector<std::vector<char>>& map, const std::vector<std::vector<bool>>& visited, int r, int c) {
	return (0 <= r && r < map.size())
		&& (0 <= c && c < map[0].size())
		&& !visited[r][c]
		&& map[r][c] != 'X';
}

int Problem_21736::DFS(const std::vector<std::vector<char>>& map, std::vector<std::vector<bool>>& visited, int r, int c) {

	int result = (map[r][c] == 'P') ? 1 : 0;

	for (int d = 0; d < 4; d++) {
		int nRow = r + rDir[d];
		int nCol = c + cDir[d];

		if (canMove(map, visited, nRow, nCol)) {
			visited[nRow][nCol] = true;
			result += DFS(map, visited, nRow, nCol);
		}
	}

	return result;
}

void Problem_21736::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 }, m{ 0 };
	cin >> n >> m;

	std::vector<std::vector<char>> map(n, vector<char>(m));
	std::vector<std::vector<bool>> visited(n, vector<bool>(m, false));

	int r{ 0 }, c{ 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'I') {
				r = i;
				c = j;
			}
		}
	}
	
	visited[r][c] = true;
 	int result = DFS(map, visited, r, c);

	if (result == 0) {
		cout << "TT" << endl;
	}
	else {
		cout << result << endl;
	}
}