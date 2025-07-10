#include"problem.h"
#include<iostream>
#include<vector>
#include<queue>

/*
* 문제 : https://www.acmicpc.net/problem/2638
* 티어 : 골드III
*/

typedef std::pair<int, int> Dot;
int dirX[4] = { -1, 0, 1, 0 };
int dirY[4] = { 0, -1, 0, 1 };

void Problem_2638::Solution() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int w{ 0 }, h{ 0 };
	std::cin >> h >> w;

	std::vector<std::vector<int>> map(h, std::vector<int>(w, 0));

	std::queue<Dot> meltCheeseQ;
	std::queue<Dot> airQ;
	int time{ 0 };

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
		{
			std::cin >> map[i][j];
		}
	}

	int phase = 0;
	do{
		std::vector<std::vector<int>> countMap(h, std::vector<int>(w, 0));
		std::vector<std::vector<bool>> visited(h, std::vector<bool>(w, false));

		airQ.push(Dot(0, 0));

		while (!airQ.empty()) {
			Dot nowDot = airQ.front();
			airQ.pop();
			if (visited[nowDot.first][nowDot.second]) continue;

			visited[nowDot.first][nowDot.second] = true;

			for (int i = 0; i < 4; i++) {
				int nextY = nowDot.first + dirY[i];
				int nextX = nowDot.second + dirX[i];

				if (!(0 <= nextX && nextX < w) || !(0 <= nextY && nextY < h)) continue;
				
				if (map[nextY][nextX] == 0) airQ.push(Dot(nextY, nextX));
				else {
					if (countMap[nextY][nextX] == 1) meltCheeseQ.push(Dot(nextY, nextX));
					else {
						countMap[nextY][nextX]++;
					}
				}
			}
		}

		if (meltCheeseQ.empty()) break;

		while (!meltCheeseQ.empty()) {
			map[meltCheeseQ.front().first][meltCheeseQ.front().second] = 0;
			meltCheeseQ.pop();
		}
		phase++;
	} while (true);

	std::cout << phase << std::endl;
}