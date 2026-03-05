#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

typedef struct dot {
	int r;
	int c;
	int val;

	dot() :r(0), c(0), val(0) {
	}

	dot(int row, int col, int val) : r(row), c(col), val(val) {}

	bool operator()(dot a, dot b) {
		return a.val > b.val;
	}

} dot;

// '0' = 48 ~ 57/ a = 97 ~ 122 / A = 65 ~ 90

static int rDir[4] = { 1,-1,0,0 };
static int cDir[4] = { 0,0,-1,1 };


bool RangeCheck(vector<vector<char>>& map, int r, int c) {

	return 0 <= r && r < map.size()
		&& 0 <= c && c < map[0].size();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<char>> map(m, vector<char>(n, ' '));
	vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
	dot exit;
	dot tera;


	for (int r = 0; r < m; r++) {
		for (int c = 0; c < n; c++) {
			cin >> map[r][c];

			if (map[r][c] == 'E') exit = dot(r, c, 0);
			if (map[r][c] == 'T') tera = dot(r, c, 0);
		}
	}

	//dist[tera.r][tera.c] = 0;
	priority_queue<dot, vector<dot>, dot> myQueue;
	myQueue.push(tera);

	//bool isTouchedLockOnce = false;

	while (!myQueue.empty()) {
		dot nowDot = myQueue.top();
		myQueue.pop();


		for (int i = 0; i < 4; i++) {
			int nextRow = nowDot.r + rDir[i];
			int nextCol = nowDot.c + cDir[i];
			int time = 0;
			
			while (RangeCheck(map, nextRow, nextCol) && map[nextRow][nextCol] != 'H') {
				if (map[nextRow][nextCol] == 'R') {
					if (dist[nextRow - rDir[i]][nextCol - cDir[i]] > nowDot.val + time) {
						dist[nextRow - rDir[i]][nextCol - cDir[i]] = nowDot.val + time;
						myQueue.push(dot(nextRow - rDir[i], nextCol - cDir[i], nowDot.val + time));
						//isTouchedLockOnce = true;
					}
					break;
				}
				else if (map[nextRow][nextCol] == 'E') {
					if (dist[nextRow][nextCol] > nowDot.val + time) {
						dist[nextRow][nextCol] = nowDot.val + time;
					}
					break;
				}

				time += (map[nextRow][nextCol] - '0');
				nextRow += rDir[i];
				nextCol += cDir[i];
			}
		}
	}

	if (dist[exit.r][exit.c] == INT_MAX) cout << "-1\n";
	else cout << dist[exit.r][exit.c] << "\n";

	return 0;
}