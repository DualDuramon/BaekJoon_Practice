#include<iostream>
#include<vector>
#include<string>
#define DEFAULT_NUM -10

using namespace std;

//A = N의 각 자릿수를 모두 더한 값
//B = N의 각 자릿수를 모두 곱한 값
//f(N) = A와 B를 순서대로 이어붙인 수
//N에 연산을 계속 해서 f(x) = x 가 되면 g(N) = 1, 안되면 g(N) = 0, 계속하다가 100,000을 넘으면 g(N) = -1

int CalCulateNum(int n) {
	int a{ 0 };
	int b{ 1 };

	while (n != 0) {
		a = a + n % 10;
		b = b * (n % 10);
		n = n / 10;
	}
	string result_a = to_string(a);
	string result_b = to_string(b);

	return stoi(result_a + result_b);
}

int F(int n, vector<int>& visited) {
	if (visited[n] != DEFAULT_NUM) {
		if (visited[n] == 0) {
			return 0;
		}
		else {
			return visited[n];
		}
	}

	visited[n] = 0;
	int result = CalCulateNum(n);

	if (result > 100000) {
		visited[n] = -1;
		return -1;
	}
	else if (result == n) {
		visited[n] = 1;
		return 1;
	}
	else {
		return visited[n] = F(result, visited);
	}
}


int G(int l, vector<int>& visited) {
	return F(l, visited);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int l{ 0 }, r{ 0 };
	cin >> l >> r;

	vector<int> visited(100001, DEFAULT_NUM);
	int result = 0;

	for (int i = l; i <= r; ++i) {
		result += G(i, visited);
	}

	cout << result << "\n";
	return 0;
}