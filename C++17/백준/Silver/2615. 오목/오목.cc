#include<iostream>
#include<vector>

using namespace std;

static int dirR[4] = { 1, 1,0,-1 }; // 세로 // 하대각// 가로// 상대각
static int dirC[4] = { 0,1,1,1 };

bool CheckBound(int r, int c) {
	return 0 < r && r < 20
		&& 0 < c && c < 20;
}

void DFS(const vector<vector<int>>& map, int r, int c, int dir, int depth, int player, bool& isWin) {
	int nextR = r + dirR[dir];
	int nextC = c + dirC[dir];

	if (depth == 5) {
		isWin = !(CheckBound(nextR, nextC) && map[nextR][nextC] == player);
		return;
	}
	
	if (CheckBound(nextR, nextC) && map[nextR][nextC] == player) {
		DFS(map, nextR, nextC, dir, depth + 1, player, isWin);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	vector<vector<int>> map(20, vector<int>(20, 0));

	for (int i = 1; i < 20; ++i) {
		for (int j = 1; j < 20; ++j)
			cin >> map[i][j];
	}

	bool isWin = false;

	for (int r = 1; r < 20; ++r) {
		for (int c = 1; c < 20; c++) {
			if (map[r][c] == 0) continue;

			for (int i = 0; i < 4; ++i) {
				DFS(map, r, c, i, 1, map[r][c], isWin);
				if (isWin) {
					int reverseR = r - dirR[i];
					int reverseC = c - dirC[i];
					if (CheckBound(reverseR, reverseC) && map[reverseR][reverseC] == map[r][c]) {
						isWin = false;
						continue;
					}

					cout << map[r][c]<< "\n";
					cout << r << " " << c << "\n";
					r = 20;
					c = 20;
					break;
				}
			}
		}
	}

	if (!isWin) cout << "0\n";
	return 0;
}