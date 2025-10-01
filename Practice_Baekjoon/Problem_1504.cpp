#include"problem.h"
#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

typedef std::pair<int, int> edge; // weight. end

void djikstra(const vector<vector<edge>>& graph, vector<int>& dist, int startNode) {
	
	priority_queue<edge, vector<edge>, greater<edge>> pq;

	pq.push(edge(0, startNode));
	dist[startNode] = 0;

	while (!pq.empty()) {
		auto [val, end] = pq.top();
		pq.pop();

		if (val > dist[end]) continue;
		for (int i = 0; i < graph[end].size(); i++) {
			int newDist = val + graph[end][i].first;

			if (newDist < dist[graph[end][i].second]) {
				dist[graph[end][i].second] = newDist;
				pq.push({ newDist, graph[end][i].second });
			}
		}
	}
}

//int main() {
void Problem_1504::Solution() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int n, e;
	cin >> n >> e;
	if (e == 0) {
		cout << -1 << "\n";
		return;
		//return 0;
	}

	vector<vector<edge>> graph(n + 1, vector<edge>());

	for (int i = 0; i < e; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		graph[s].emplace_back(edge(v, e));
		graph[e].emplace_back(edge(v, s));
	}

	int node1, node2;
	cin >> node1 >> node2;

	priority_queue<edge, vector<edge>, edge> pq;

	vector<int> dist(graph.size(), INT_MAX);
	djikstra(graph, dist, node1);
	int startToNode1 = dist[1];
	int node1ToNode2 = dist[node2];
	int node1ToEnd = dist[n];

	std::fill(dist.begin(), dist.end(), INT_MAX);
	djikstra(graph, dist, node2);
	int startToNode2 = dist[1];
	int node2ToNode1 = dist[node1];
	int node2ToEnd = dist[n];

	long long ans1 = (long long)startToNode1 + (long long)node1ToNode2 + (long long)node2ToEnd;
	long long ans2 = (long long)startToNode2 + (long long)node2ToNode1 + (long long)node1ToEnd;

	if (ans1 < 0) ans1 = INT_MAX;
	if (ans2 < 0) ans2 = INT_MAX;

	long long ans = min(ans1, ans2);

	if (ans >= INT_MAX || ans < 0)		
		cout << -1 << "\n";
	else
		cout << ans << "\n";

	//return 0;
}