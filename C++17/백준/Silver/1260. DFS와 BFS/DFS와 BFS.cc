#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>

using namespace std;

/*
* 백준 1260번
* 
* 
*/
static std::vector<std::vector<int>> list;
static std::queue<int> qu;
//static std::stack<int> st;	//사용?
static std::vector<bool> visited;	//방문기록 나타내는 배열

void DFS(int node);
void BFS(int node);

int main(void) {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n{0}, m{0};
	int startnode{ 0 };
	std::cin >> n >> m >> startnode;

	list.resize(n+1);
	visited = std::vector<bool>(n+1, false);

	for (int i = 0; i < m; i++) {
		int s, e;
		std::cin >> s >> e;
		list[s].push_back(e);
		list[e].push_back(s);
	}
	for (auto i = list.begin(); i != list.end(); i++) {
		std::sort(i->begin(), i->end());
	}

	DFS(startnode);
	std::cout << std::endl;
	
	for (int i = 0; i <= n; i++) visited[i] = false;
	qu.push(startnode);
	BFS(startnode);

	return 0;
}

void DFS(int node) {
	if (visited[node]) {
		return;
	}

	visited[node] = true;
	std::cout << node << " ";

	for (int i : list[node]) {
		if (!visited[i])
			DFS(i);
	}
}

void BFS(int node) {

	while (!qu.empty()) {
		int f = qu.front();
		std::cout << qu.front() << " ";
		visited[f] = true;
		qu.pop();

		for (int i : list[f])
			if (!visited[i]) {
				visited[i] = true;
				qu.push(i);
			}
	}
}