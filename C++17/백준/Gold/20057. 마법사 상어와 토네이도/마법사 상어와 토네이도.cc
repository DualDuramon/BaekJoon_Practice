#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

static int dirR[4] = { 0,1,0,-1 }; //좌, 하, 우, 상
static int dirC[4] = { -1,0,1,0 };

struct point {
	int r;
	int c;

	point(int r, int c) {
		this->r = r;
		this->c = c;
	}
};

bool CheckBound(const vector<vector<int>>& sendMap, int r, int c) {
	return 0 <= r && r < sendMap.size()
		&& 0 <= c && c < sendMap[0].size();
}

void SendMove(vector<vector<int>>& sendMap, int dirR, int dirC, int& disappearedSand, int amount) {
	if (CheckBound(sendMap, dirR, dirC)) {
		sendMap[dirR][dirC] += amount;
	}
	else {
		disappearedSand += amount;
	}

}

void TornadoMove(vector<vector<int>>& sendMap, const point& p, int dir, int& disappearedSand) {
	if (!CheckBound(sendMap, p.r, p.c)) return;

	point frontVec = { dirR[dir % 4], dirC[dir % 4] };
	point rightVec = { dirR[(dir + 1) % 4], dirC[(dir + 1) % 4] };

	int onePercent = sendMap[p.r][p.c] * 0.01;
	int twoPercent = sendMap[p.r][p.c] * 0.02;
	int sevenPercent = sendMap[p.r][p.c] * 0.07;
	int tenPercent = sendMap[p.r][p.c] * 0.1;
	int fivePercent = sendMap[p.r][p.c] * 0.05;
	int last = sendMap[p.r][p.c] - (onePercent + twoPercent + tenPercent + sevenPercent) * 2 - fivePercent;

	SendMove(sendMap, p.r + frontVec.r + rightVec.r, p.c + frontVec.c + rightVec.c, disappearedSand, tenPercent);
	SendMove(sendMap, p.r + frontVec.r - rightVec.r, p.c + frontVec.c - rightVec.c, disappearedSand, tenPercent);

	SendMove(sendMap, p.r - frontVec.r + rightVec.r, p.c - frontVec.c + rightVec.c, disappearedSand, onePercent);
	SendMove(sendMap, p.r - frontVec.r - rightVec.r, p.c - frontVec.c - rightVec.c, disappearedSand, onePercent);

	SendMove(sendMap, p.r + rightVec.r, p.c + rightVec.c, disappearedSand, sevenPercent);
	SendMove(sendMap, p.r - rightVec.r, p.c - rightVec.c, disappearedSand, sevenPercent);

	SendMove(sendMap, p.r + rightVec.r * 2, p.c + rightVec.c * 2, disappearedSand, twoPercent);
	SendMove(sendMap, p.r - rightVec.r * 2, p.c - rightVec.c * 2, disappearedSand, twoPercent);

	SendMove(sendMap, p.r + frontVec.r * 2, p.c + frontVec.c * 2, disappearedSand, fivePercent);

	
	SendMove(sendMap, p.r + frontVec.r, p.c + frontVec.c, disappearedSand, last);

	sendMap[p.r][p.c] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	cin >> n;

	vector<vector<int>> sendMap(n, vector<int>(n, 0));

	for (auto& line : sendMap) {
		for (auto& tile : line) cin >> tile;
	}

	point nowP = { n / 2, n / 2 };
	int dirCount = 0;
	int disappearedSand = 0;

	while (nowP.r > -1 && nowP.c > -1) {
		int moveLength = dirCount / 2 + 1;

		for (int i = 0; i < moveLength; i++) {
			nowP.r += dirR[dirCount % 4];
			nowP.c += dirC[dirCount % 4];
			TornadoMove(sendMap, nowP, dirCount, disappearedSand);

		}
		++dirCount;
	}

	cout << disappearedSand << "\n";
	return 0;
}