#include<iostream>
#include<vector>
#include<limits>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	long s{ 0 };

	cin >> n >> s;
	vector<int> vec(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	int startIdx = 0;
	int endIdx = 0;
	int minLength = numeric_limits<int>().max();
	long sum = 0;


	while (endIdx < n) {
		sum += vec[endIdx++];

		if (sum < s) continue;
		minLength = min(minLength, endIdx - startIdx);

		while (startIdx < endIdx && sum - vec[startIdx] >= s) {
			sum -= vec[startIdx];
			startIdx++;
			minLength = min(minLength, endIdx - startIdx);
		}
	}

	cout << (minLength < 0 || minLength > 1000001 ? 0 : minLength) << "\n";
	return 0;
}