#include"problem.h"
#include<iostream>
#include<queue>
#include<map>
using namespace std;

/*
 * 연산종류->I, D(insert, delete)
 * D 1 -> 큐에서 최댓값 삭제 연산 / D -1 Q에서 최솟값 삭제 연산
 * 최대 or 최소 삭제 연산의 경우 해당 값이 2개면 하나만 삭제시키기.
 * 큐가 비어있으면 D 연산은 무시됨.
 */

void Problem_7662::Solving() {
	int n{ 0 };
	cin >> n;

	priority_queue<int, vector<int>, less<int>> maxQueue;
	priority_queue<int, vector<int>, greater<int>> minQueue;
	map<int, int> map;


	for (int i = 0; i < n; i++) {
		char oper;
		int num;
		cin >> oper >> num;

		if (oper == 'I') {
			maxQueue.push(num);
			minQueue.push(num);

			if (map.find(num) == map.end()) {
				map.emplace(num, 1);
			}
			else {
				map[num]++;
			}

		}
		else {
			if (num == -1 && !minQueue.empty()) {
				map[minQueue.top()]--;
			}
			else if (num == 1 && !maxQueue.empty()) {
				map[maxQueue.top()]--;
			}

			while (!minQueue.empty() && map[minQueue.top()] <= 0) {
				minQueue.pop();
			}
			while (!maxQueue.empty() && map[maxQueue.top()] <= 0) {
				maxQueue.pop();
			}
		}
	}

	if (maxQueue.empty() || minQueue.empty()) {
		cout << "EMPTY" << endl;
	}
	else {
		int max = maxQueue.top();
		int min = minQueue.top();
		cout << max << " " << min << endl;
	}

}

void Problem_7662::Solution() {
	int t{ 0 };
	cin >> t;

	for (int i = 0; i < t; i++) {
		Solving();
	}

	//return 0;
}