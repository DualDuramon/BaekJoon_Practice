#include"problem.h"
#include<iostream>
#include<vector>

using namespace std;
static struct dot {
	int x = 0;
	int y = 0;

	dot(int x, int y) { this->x = x; this->y = y; }
	dot operator + (const dot& a) {
		return dot(x + a.x, y + a.y);
	}
};

static dot dirList[3]{ {1,1}, {1,0}, {0,1} }; //대각, 가로, 세로 이동
static enum direction { Horizontal, Vertical, Diagonal};


//파이프 처음 -> (1,1) (1,2) 를 차지 , (n, n)까지 이동시켜야함.

bool CheckNextLoc(vector<vector<int>>& map, const dot& nextDot) {
	return 1 <= nextDot.x && nextDot.x < map.size()
		&& 1 <= nextDot.y && nextDot.y < map.size()
		&& map[nextDot.x][nextDot.y] == 0;
}

void DFS(vector<vector<int>>& map, int& caseCount, dot nowDot, direction nowDir) {
	if (nowDot.x == map.size() - 1 && nowDot.y == map.size() - 1) {
		caseCount++;
		return;
	}

	//방향 정해서 풀기

	switch (nowDir) {
	case Horizontal:
		if (CheckNextLoc(map, nowDot + dirList[1])) {
			DFS(map, caseCount, nowDot + dirList[1], Horizontal);
		}
		break;
	case Vertical :
		if (CheckNextLoc(map, nowDot + dirList[2])) {
			DFS(map, caseCount, nowDot + dirList[2], Vertical);
		}
		break;
	case Diagonal:
		if (CheckNextLoc(map, nowDot + dirList[1])) {
			DFS(map, caseCount, nowDot + dirList[1], Horizontal);
		}
		if (CheckNextLoc(map, nowDot + dirList[2])) {
			DFS(map, caseCount, nowDot + dirList[2], Vertical);
		}
		break;
	}
	if (CheckNextLoc(map, nowDot + dirList[0]) && CheckNextLoc(map, nowDot + dirList[1]) && CheckNextLoc(map, nowDot + dirList[2])) {
		DFS(map, caseCount, nowDot + dirList[0], Diagonal);
	}
}


//int main(){
void Problem_17070::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	cin >> n;

	vector<vector<int>> map(n + 1, vector<int>(n + 1, 0));
	int caseCount{ 0 };

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[j][i];
		}
	}
	
	DFS(map, caseCount, dot(2, 1), Horizontal);

	cout << caseCount << endl;
	//return 0;
}