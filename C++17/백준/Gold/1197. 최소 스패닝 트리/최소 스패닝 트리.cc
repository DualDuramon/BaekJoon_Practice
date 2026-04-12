#include<iostream>
#include<queue>
using namespace std;

/*백준 1197번_답지
* 최소 신장트리를 구하는 문제
	* 유니온파인드 리스트를 이용해 노드사이의 사이클 여부를 체크해야함
	* 우선순위 큐를 이용해 미사용 엣지중 가중치가 제일 낮은 에지부터 탐색함(크루스칼 알고리즘을 구현한 것)
	* 대표노드들이 서로 다르면 연결함(union)
* 크루스칼 알고리즘
	* 그래프에서 만들 수 있는 신장트리중 최소신장트리를 구하기 위한 알고리즘
	* 간선들을 가중치에 따라 정렬하고 사이클이 형성되지 않는 선에서 정렬된 순서대로 간선을 선택함
*/

typedef struct edge {	//엣지 정보 구조체 생성
	int s, e, v;
	bool operator >(const edge& temp) const {	//가중치값을 기준으로 오름차순 정렬(1->2->3->...)
		return v > temp.v;
	}
}edge;

void myUnion(int a, int b);
int myFind(int n);
static std::vector<int> parent;	//노드의 부모노드(대표노드)를 기록하는 배열

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n, m;
	std::cin >> n >> m;
	std::priority_queue<edge, std::vector<edge>, std::greater<edge>> pq;	//엣지를 오름차순으로 정렬하는 큐
	parent.resize(n + 1);

	for (int i = 0; i <= n; i++) {	//부모노드 배열 초기화
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {	//엣지 입력
		int s, e, v;
		std::cin >> s >> e >> v;
		pq.push(edge{ s, e, v });
	}

	int useEdge = 0;
	int result = 0;

	while (useEdge < n - 1) {	//최소신장트리 생성
		edge now = pq.top();
		pq.pop();

		if (myFind(now.s) != myFind(now.e)) {//같은 부모가 아니라면 -> 연결해도 사이클이 안생기면 서로 연결
			myUnion(now.s, now.e);
			result += now.v;
			useEdge++;
		}
	}

	std::cout << result << std::endl;

	return 0;
}

void myUnion(int a, int b) {	//union연산 : 대표노드끼리 연결
	int pre_a = myFind(a);
	int pre_b = myFind(b);

	if (pre_a != pre_b) {
		parent[pre_b] = pre_a;
	}
}
int myFind(int n) {	//find 연산 : 대표노드를 검색함
	if (parent[n] == n) {
		return n;
	}
	else {	//재귀로 구현해 경로압축을 구현
		return parent[n] = myFind(parent[n]);
	}
}