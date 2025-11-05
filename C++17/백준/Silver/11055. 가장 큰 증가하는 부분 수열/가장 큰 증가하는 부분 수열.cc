#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
	int n{ 0 };
	cin >> n;

	vector<int> arr(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		dp[i] = arr[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i+1; j <= n; ++j) {
			if (arr[i] < arr[j]) {
				dp[j] = max(dp[i] + arr[j], dp[j]);
			}
		}

	}

	cout << *max_element(dp.begin(), dp.end()) << "\n";
	return 0;
}