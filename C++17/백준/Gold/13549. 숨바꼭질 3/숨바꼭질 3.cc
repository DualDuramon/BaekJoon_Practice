#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 }, k{ 0 };

	cin >> n >> k;

	queue<int> queue;
	vector<int> distance(100001, 100001);
	queue.push(n);
	distance[n] = 0;
	
	while (!queue.empty()) {
		int nowPos = queue.front();
		queue.pop();

		if (nowPos < 100000 && distance[nowPos + 1] > distance[nowPos] + 1) {
			distance[nowPos + 1] = distance[nowPos] + 1;
			queue.push(nowPos + 1);
		}

		if (0 < nowPos && distance[nowPos - 1] > distance[nowPos] + 1){
			distance[nowPos - 1] = distance[nowPos] + 1;
			queue.push(nowPos - 1);
		}
		if (nowPos * 2 < 100001 && distance[nowPos * 2] > distance[nowPos])
		{
			distance[nowPos * 2] = distance[nowPos];
			queue.push(nowPos * 2);
		}
	}

	cout << distance[k] << "\n";
	return 0;
}