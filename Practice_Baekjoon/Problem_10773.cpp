#include"problem.h"
#include<iostream>
#include<stack>

/*	링크 : https://www.acmicpc.net/problem/10773
*	티어 : 실버 IV
*/

void Problem_10773::Solution() {
	int k = 0;
	std::stack<int> st;
	std::cin >> k;

	for (int i = 0; i < k; i++) {
		int num = -1;
		std::cin >> num;

		if (num == 0 && !st.empty()) {
			st.pop();
			continue;
		}

		st.push(num);
	}

	long result = 0;

	while (!st.empty()) {
		result += st.top();
		st.pop();
	}

	std::cout << result << std::endl;
}