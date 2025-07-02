#include "problem.h"
#include<iostream>
#include<vector>
#include<queue>

/*
* 문제 : https://www.acmicpc.net/problem/10814
* 티어 : 실버V
*/


typedef struct {
	int age;
	int id;
	std::string name;

}customerData; //회원정보(나이, 이름)

struct SortingRule {
	bool operator()(customerData c1, customerData c2) {
		if (c1.age == c2.age) {
			return c1.id > c2.id;
		}
		else
			return c1.age > c2.age;
	}
};


void Problem_10814::Solution() {
	int n{ 0 }, idCount{ 0 };
	std::cin >> n;

	std::priority_queue<customerData, std::vector<customerData>, SortingRule> pq;

	for (int i = 0; i < n; i++) {
		customerData temp;
		std::cin >> temp.age >> temp.name;
		temp.id = idCount++;
		pq.push(temp);
	}

	while (!pq.empty()) {
		printf("%d %s\n", pq.top().age, pq.top().name.c_str());
		pq.pop();
	}

}