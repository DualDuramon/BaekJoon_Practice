#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	cin >> n;
	
	vector<int> lineOfNumber(3, 0);
	vector<int> minDp(3, 0);
	vector<int> maxDp(3, 0);

	for (int i = 0; i < 3; i++) {
		cin >> lineOfNumber[i];
		minDp[i] = maxDp[i] = lineOfNumber[i];
	}

	vector<int> tempDp(3, numeric_limits<int>().max());

	for (int i = 1; i < n; i++) {
		fill(tempDp.begin(), tempDp.end(), numeric_limits<int>().max());
		for (int j = 0; j < 3; j++) {
			cin >> lineOfNumber[j];
		}

		tempDp[0] = min(tempDp[0], lineOfNumber[0] + min(minDp[0], minDp[1]));
		tempDp[1] = min(tempDp[1], lineOfNumber[1] + min(minDp[0], min(minDp[1], minDp[2])));
		tempDp[2] = min(tempDp[2], lineOfNumber[2] + min(minDp[1], minDp[2]));

		for (int j = 0; j < 3; j++) minDp[j] = tempDp[j];


		fill(tempDp.begin(), tempDp.end(), numeric_limits<int>().min());
		tempDp[0] = max(tempDp[0], lineOfNumber[0] + max(maxDp[0], maxDp[1]));
		tempDp[1] = max(tempDp[1], lineOfNumber[1] + max(maxDp[0], max(maxDp[1], maxDp[2])));
		tempDp[2] = max(tempDp[2], lineOfNumber[2] + max(maxDp[1], maxDp[2]));

		for (int j = 0; j < 3; j++) maxDp[j] = tempDp[j];
	}

	cout << (*max_element(maxDp.begin(), maxDp.end())) << " " << (*min_element(minDp.begin(), minDp.end())) << "\n";
	return 0;
}