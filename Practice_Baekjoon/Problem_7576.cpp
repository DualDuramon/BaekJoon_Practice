#include"problem.h"
#include<iostream>
#include <vector>
#include <queue>

using namespace std;
struct Dot {
	int row;
	int col;

	Dot(int r, int c) {
		row = r;
		col = c;
	}
};

static int dr[] = { -1, 1, 0, 0 };
static int dc[] = { 0 , 0, -1, 1 };

bool Problem_7576::CheckCoord(const std::vector<std::vector<int>>& map, size_t row, size_t col) {
	return
		0 <= row && row < map.size() &&
		0 <= col && col < map[0].size() &&
		map[row][col] == 0;
}

void Problem_7576::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int m{ 0 }, n{ 0 };	//m : 가로 n : 세로
	cin >> m >> n;

	vector<vector<int>> box(n, vector<int>(m, 0));
	queue<Dot> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) 
		{
			cin >> box[i][j];
			if (box[i][j] == 1)
				q.push(Dot(i, j));
		}
	}
	
	while (!q.empty()) 
	{
		Dot nowDot = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextR = nowDot.row + dr[i];
			int nextC = nowDot.col + dc[i];

			if (CheckCoord(box, nextR, nextC)) {
				box[nextR][nextC] = box[nowDot.row][nowDot.col] + 1;
				q.push(Dot(nextR, nextC));
			}
		}
	}

	int phase = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) {
				phase = 0;
				cout << "-1\n"<<endl;
				return;
			}
			phase = std::max(phase, box[i][j]);
		}
	}

	cout << phase -1 << endl;
}