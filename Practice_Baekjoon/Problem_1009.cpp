#include"problem.h"
#include<iostream>
#include<vector>

/*
* 링크 : https://www.acmicpc.net/problem/1009
* 티어 : 브론즈 II
*/


void Problem_1009::Solution() {
	int testCase = 0;
	std::cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		Solving();
	}
}

void Problem_1009::Solving() {
	int a = 0, b = 0;
	std::cin >> a >> b;

	int result = 1;

	for (int i = 0; i < b; i++) {

		result = (result * a) % 10;
		result = result == 0 ? 10 : result;
	}

	std::cout << result << "\n";
}