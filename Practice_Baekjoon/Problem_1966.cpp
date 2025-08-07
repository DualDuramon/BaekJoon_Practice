#include "problem.h"
#include<iostream>
#include <vector>
#include<queue>

using namespace std;


struct priorityWrapper {
	int priority;
};

void Problem_1966::Solving() {

	int n{ 0 }, chooseId{ 0 };
	cin >> n >> chooseId;

	vector<priorityWrapper*> queue(n);
	int maxPriority = -1;
	
	for (int i = 0; i < n; ++i) {
		priorityWrapper* temp = new priorityWrapper;
		cin >> temp->priority;
		if (maxPriority < temp->priority) maxPriority = temp->priority;
		queue[i] = temp;
	}
	priorityWrapper* select = queue[chooseId];

	
	int front = 0;
	int back = n - 1;
	int count = 0;

	while (front != back) {
		if (queue[front]->priority == maxPriority) {
			
			if (queue[front] == select) {
				break;
			}

			count++;
			queue[front]->priority = maxPriority = -1;

			front = (front + 1) % queue.size();
			for (auto p : queue) {
				if (maxPriority < p->priority) maxPriority = p->priority;
			}
		}
		else {
			if (queue[front]->priority != -1) {
				back = front;
			}
			front = (front + 1) % queue.size();
		}
	}

	cout << count + 1 << "\n";
}

void Problem_1966::Solution() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);
	
	int testCase{ 0 };
	std::cin >> testCase;

	for (int i{ 0 }; i < testCase; i++) {
		Solving();
	}
}