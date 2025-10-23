#include"problem.h"
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<vector>

using namespace std;

//int main(){
void Problem_11725::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	cin >> n;

	vector<vector<int>> nodeList(n + 1, vector<int>());
	vector<int> parent(n + 1, -1);


	for (int i = 0; i < n - 1; ++i) {
		int start{ 0 }, end{ 0 };
		cin >> start >> end;
		nodeList[start].emplace_back(end);
		nodeList[end].emplace_back(start);
	}
	queue<int> q;
	q.push(1);
	parent[1] = 0;

	while (!q.empty()) {
		int nowNode = q.front();
		q.pop();

		for (auto node : (nodeList[nowNode])) {
			if (parent[node] != -1) continue;
			q.push(node);
			parent[node] = nowNode;
		}
	}

	for (int i = 2; i <= n; ++i) {
		cout << parent[i] << "\n";
	}

	//return 0;
}

// 1 - 6 - 3 - 5
// |
// 4 - 2
// |
// 7