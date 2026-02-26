#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void ProbSolving() {
	int n{ 0 };
	cin >> n;

	vector<vector<int>> prices(2, vector<int>(n, 0)); // 원가, 주식값

	for (int i = 0; i < n; i++) {
		cin >> prices[0][i];
		prices[1][i] = prices[0][i];
	}

	long sum = 0;

	int nowMax = prices[0][n - 1];
	for (int i = n-1 ; i >= 0; i--) {
		nowMax = max(nowMax, prices[0][i]);
		prices[1][i] = nowMax;
		sum += prices[1][i] - prices[0][i];
	}


	cout << sum << "\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t{ 0 };
	cin >> t;

	for (int i = 0; i < t; i++) {
		ProbSolving();
	}


	return 0;
}
