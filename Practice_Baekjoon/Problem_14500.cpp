#include "problem.h"
#include<iostream>
#include<vector>

using namespace std;
typedef pair<int, int> dot;

static int result{ 0 };

static dot point[6] = {
	{-1, 0},
	{-1, 1},
	{0, 2},
	{1, 1},
	{1, 0},
	{0, -1}
};

bool CheckBound(const std::vector<std::vector<int>>& map, int row, int col) {

	return (0 <= row && row < map.size()) && (0 <= col && col < map[0].size());
}

void Problem_14500::CheckTiles(const std::vector<std::vector<int>>& map, dot p) {
	
	int nowSum = map[p.first][p.second] + map[p.first][p.second + 1];

	for (int i = 0; i < 6; i++) {
		if (CheckBound(map, p.first + point[i].first, p.second + point[i].second)) {
			for (int j = i + 1; j < 6; j++) {
				if (CheckBound(map, p.first + point[j].first, p.second + point[j].second)) {
					int chooseSum 
						= map[p.first + point[i].first][p.second + point[i].second] + 
						map[p.first + point[j].first][p.second + point[j].second];

					result = max(result, nowSum + chooseSum);
				}
			}
		}
	}

}

//int main(){
void Problem_14500::Solution() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 }, m{ 0 };
	cin >> n >> m;

	vector<vector<int>> map(n, vector<int>(m, 0));
	vector<vector<int>> swapedMap(m, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			swapedMap[j][i] = map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			CheckTiles(map, dot(i, j));
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			CheckTiles(swapedMap, dot(i, j));
		}
	}

	cout << result << endl;
	//return 0;
}