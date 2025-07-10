#include "problem.h"
#include<iostream>
#include<vector>

/*
* 문제 : https://www.acmicpc.net/problem/11659
* 티어 : 실버III
*/

void Problem_11659::Solution() {

	int n{ 0 }, m{ 0 };
	std::cin >> n >> m;

	std::vector<int> vec(n + 1);
	vec[0] = 0;

	for (int i = 1; i < n + 1; i++) {
		//std::cin >> vec[i];
		scanf_s("%d", &vec[i]);
		vec[i] += vec[i - 1];
	}

	int start{ 0 }, end{ 0 };

	for (int i = 0; i < m; i++) {
		std::cin >> start >> end;
		printf("%d\n", vec[end] - vec[start -1]);
	}

}