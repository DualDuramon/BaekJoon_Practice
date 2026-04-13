#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct edge {
	int s;
	int e;
	int val;

	bool operator()(const edge& a, const edge& b) {
		return a.val > b.val;
	}
};

bool CheckAllLinked(const vector<int>& parent) {
	int root = parent[1];
	for (int i = 2; i < parent.size(); i++) {
		if (parent[i] != root) return false;
	}

	return true;
}

int FindParent(vector<int>& parent, int x) {
	if (parent[x] == x) return x;

	return parent[x] = FindParent(parent, parent[x]);
}

void Union(vector<int>& parent, int x, int y) {
	x = FindParent(parent, x);
	y = FindParent(parent, y);

	if (x != y) {
		parent[y] = x;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 }, m{ 0 };
	cin >> n >> m;

	priority_queue<edge, vector<edge>, edge> myQueue;
	vector<int> parent(n + 1, 0);
	for(int i = 1 ; i <= n ; i++){
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		edge newEdge;
		cin >> newEdge.s >> newEdge.e >> newEdge.val;
		myQueue.push(newEdge);
	}

	int totalCost = 0;


	while (!CheckAllLinked(parent) && !myQueue.empty()) {
		edge nowEdge = myQueue.top();
		myQueue.pop();

		if (FindParent(parent, nowEdge.s) != FindParent(parent, nowEdge.e)) {
			Union(parent, nowEdge.s, nowEdge.e);
			totalCost += nowEdge.val;
		}
	}

	cout << totalCost << "\n";
	return 0;
}
