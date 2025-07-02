#include"problem.h"
#include <iostream>
#include<vector>
#include<stack>

/*	링크 : https://www.acmicpc.net/problem/1012
*	티어 : 실버 II
*/

int garoCha[] = { 1, -1, 0, 0 };
int seroCha[] = { 0, 0 , 1, -1 };

void Problem_1012::Solution() {
	int testCase = 0;
	std::cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		Solving();
	}
}


void Problem_1012::Solving() {
	int m, n, k;
	std::cin >> m >> n >> k;
	std::vector<std::vector<bool>> map(n, std::vector<bool>(m, false));
	std::vector<std::pair<int, int>> baechuList(k);

	for (int i = 0; i < k; i++)
	{
		int a, b;
		std::cin >> a >> b;
		baechuList[i] = std::pair<int, int>(a, b);		//first = 가로 , second = 세로 좌표

		map[b][a] = true;
	}

	std::stack<std::pair<int, int>> st;
	std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));


	int result = 0;

	for (int i = 0; i < baechuList.size(); i++)
	{
		if (visited[baechuList[i].second][baechuList[i].first]) continue;
		st.push(baechuList[i]);

		while (!st.empty())
		{
			std::pair<int, int> nowPoint = st.top();
			st.pop();

			if (visited[nowPoint.second][nowPoint.first]) continue;
			visited[nowPoint.second][nowPoint.first] = true;

			for (int check = 0; check < 4; check++) 
			{
				if (nowPoint.first + garoCha[check] < 0 || nowPoint.first + garoCha[check] > m - 1) continue;
				if (nowPoint.second + seroCha[check] < 0 || nowPoint.second + seroCha[check] > n - 1) continue;

				if (map[nowPoint.second + seroCha[check]][nowPoint.first + garoCha[check]])
					st.push(std::pair<int, int>(nowPoint.first + garoCha[check], nowPoint.second + seroCha[check]));

			}
		}

		result++;
	}

	std::cout << result << std::endl;
}
