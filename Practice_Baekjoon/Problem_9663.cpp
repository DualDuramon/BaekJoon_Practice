#include"problem.h"
#include<iostream>
#include<vector>

using namespace std;
typedef std::pair<int, int> coord; // y, x

bool CheckNextLoc(const vector<coord>& queensLoc, coord loc) {
	for (size_t i = 0; i < queensLoc.size(); i++) {
		if (queensLoc[i].first == loc.first || queensLoc[i].second == loc.second) return false; //+ 모양 검사
		if (queensLoc[i].second - queensLoc[i].first == loc.second - loc.first) return false;  // / 모양 검사
		if (queensLoc[i].first + queensLoc[i].second == loc.first + loc.second) return false;  // \ 모양 검사
	}

	return true;
}

void Problem_9663::backtracking(int mapSize, vector<coord>& queensLoc, int nowDepth, int maxDepth, int& cases) {
	if (nowDepth == maxDepth) {
		cases++;
		return;
	}

	for (int j = 0; j < mapSize; j++) {
		if (CheckNextLoc(queensLoc, coord(nowDepth, j))) {
			queensLoc.emplace_back(coord(nowDepth, j));
			backtracking(mapSize, queensLoc, nowDepth + 1, maxDepth, cases);
			queensLoc.pop_back();
		}
	}
}


//int main() {
void Problem_9663::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	cin >> n;

	int cases{ 0 };
	vector<coord> queenLocs;

	backtracking(n, queenLocs, 0, n, cases);
	cout << cases << endl;

	//return 0;
}