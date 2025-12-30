#include<iostream>
#include<queue>

using namespace std;

/*
레지스터: 0~9999
D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다. 그 결과 값(2n mod 10000)을 레지스터에 저장한다.
S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999 가 대신 레지스터에 저장된다.
L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.
*/

typedef pair<int, string> node;

int OperD(int num) {
	return (num * 2) % 10000;
}
int OperS(int num) {
    
	return num-1 <0? 9999 : num - 1;
}
int OperR(int num) {
	return (num % 10) * 1000 + num / 10;
}

int OperL(int num) {
	return num / 1000 + (num % 1000) * 10;
}

void Solving() {
	int n{ 0 }, dest{ 0 };
	cin >> n >> dest;

	vector<bool> visited(10000, false);
	queue<node> myQueue;
	node nowNode{ n,"" };

	myQueue.push(nowNode);

	while (nowNode.first != dest) {
		nowNode = myQueue.front();
		myQueue.pop();

		int d = OperD(nowNode.first);
		int s = OperS(nowNode.first);
		int l = OperL(nowNode.first);
		int r = OperR(nowNode.first);

		if (!visited[d]) {
			visited[d] = true;
			myQueue.push(node(d, nowNode.second + "D"));
		}
		if (!visited[s]) {
			visited[s] = true;
			myQueue.push(node(s, nowNode.second + "S"));
		}
		if (!visited[l])
		{
			visited[l] = true;
			myQueue.push(node(l, nowNode.second + "L"));
		}
		if (!visited[r]) {
			visited[r] = true;
			myQueue.push(node(r, nowNode.second + "R"));
		}
	}

	cout << nowNode.second << endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int t{ 0 };
	cin >> t;
	for (int i = 0; i < t; i++) {
		Solving();
	}
    return 0;
}