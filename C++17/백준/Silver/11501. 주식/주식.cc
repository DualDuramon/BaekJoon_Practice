#include<iostream>
#include<vector>
#include<climits>
using namespace std;


void ProbSolving() {
	int n{ 0 };
	cin >> n;

	vector<int> prices(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> prices[i];
	}

	long sum = 0;

	int nowMax = prices[n - 1];

	for (int i = n-1 ; i >= 0; i--) {
		nowMax = max(nowMax, prices[i]);
		sum += nowMax - prices[i];
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
