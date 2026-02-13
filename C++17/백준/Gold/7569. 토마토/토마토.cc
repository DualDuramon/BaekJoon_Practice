#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

static int dirH[6] = { 0,0,0,0,-1,1 };
static int dirR[6] = { 1,0,-1,0,0,0 };
static int dirC[6] = { 0,1,0,-1,0,0 };

struct dot {
	int h;
	int r;
	int c;

	dot() : h{ 0 }, r{ 0 }, c{ 0 } {}
	dot(int height, int row, int col) : h{ height }, r{ row }, c{ col } {}
};

bool RangeCheck(const vector<vector<vector<int>>>& map, int h, int r, int c) {
	return 0 <= h && h < map.size()
		&& 0 <= r && r < map[0].size()
		&& 0 <= c && c < map[0][0].size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int m, n, h;
	cin >> m >> n >> h;

	vector<vector<vector<int>>> box(h, vector<vector<int>>(n, vector<int>(m, -1)));
	queue<dot> bfsQueue;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) {
					bfsQueue.push(dot(i, j, k));
				}
			}
		}
	}

	while (!bfsQueue.empty()) {
		dot now = bfsQueue.front();
		bfsQueue.pop();

		for (int i = 0; i < 6; i++) {
			int nextH = now.h + dirH[i];
			int nextR = now.r + dirR[i];
			int nextC = now.c + dirC[i];

			if (!RangeCheck(box, nextH, nextR, nextC)) continue;
			if (box[nextH][nextR][nextC] == 0) {
				box[nextH][nextR][nextC] = box[now.h][now.r][now.c] + 1;
				bfsQueue.push(dot(nextH, nextR, nextC));
			}

		}
	}

	int max = INT_MIN;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (box[i][j][k] == 0) {
					cout << "-1\n";
					return 0;
				}
				max = std::max(box[i][j][k], max);
			}
		}
	}

	cout << (max == 0 ? 0 : max - 1) << "\n";
	return 0;
}