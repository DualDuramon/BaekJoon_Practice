#include<iostream>
#include<vector>

using namespace std;
typedef struct point {
	int x;
	int y;
}point;

static int dirX[4] = { 1,0,-1,0 };
static int dirY[4] = { 0,-1,0,1 };

void SetDragonCurve(vector<vector<bool>>& map, point startPoint, int nowDir, int generation) {
	vector<int> dirOrder;
	point nowPoint;

	nowPoint.x = startPoint.x + dirX[(nowDir) % 4];
	nowPoint.y = startPoint.y + dirY[(nowDir) % 4];

	map[nowPoint.y][nowPoint.x] = true;
	dirOrder.emplace_back(nowDir);

	for (int i = 1; i <= generation; ++i) {
		for (int j = dirOrder.size() - 1; j >= 0; --j) {

			nowPoint.x += dirX[(dirOrder[j] + 1) % 4];
			nowPoint.y += dirY[(dirOrder[j] + 1) % 4];
			map[nowPoint.y][nowPoint.x] = true;

			dirOrder.emplace_back((dirOrder[j] + 1) % 4);
		}
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n{ 0 };
	cin >> n;

	vector<vector<bool>> map(101, vector<bool>(101, false));
	for (int i = 0; i < n; ++i) {
		point start;
		int d;
		int g;
		cin >> start.x >> start.y >> d >> g;

		map[start.y][start.x] = true;
		SetDragonCurve(map, start, d, g);
	}

	int count = 0;
	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1])
				count++;
		}
	}

	cout << count << "\n";
	return 0;
}