#include<iostream>
#include<vector>
#include<string>

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

int F(int n, vector<bool>& visited) {
	if (visited[n]) {
		return 0;
	}

	visited[n] = true;
	int result = CalCulateNum(n);

	if (result > 100000) {
		return -1;
	}
	else if (result == n) {
		return 1;
	}
	else return F(result, visited);
}


int G(int l, vector<bool>& visited) {
	fill(visited.begin(), visited.end(), false);
	return F(l, visited);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int l{ 0 }, r{ 0 };
	cin >> l >> r;

	vector<bool> visited(100001);
	int result {0};

	for (int i = l; i <= r; ++i) {
		result += G(i, visited);
	}

	cout << result << "\n";

	return 0;
}