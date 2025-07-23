#include"problem.h"
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;


void Problem_1153::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n{ 0 };
	cin >> n;



	vector<bool> sosuList(n + 1, true);
	sosuList[1] = sosuList[0] = false;
	size_t limit{ static_cast<size_t>(sqrt(n)) };

	for (size_t i{ 2 }; i <= limit; i++) {
		if (!sosuList[i]) continue;

		for (size_t j{ i * i }; j <= n; j += i) {
			sosuList[j] = false;
		}
	}
	
	vector<int> result;
	if (n % 2 == 0) {
		result.emplace_back(2);
		result.emplace_back(2);

		for (int i = 2; i < (n-4) / 2 + 1; i++) {
			if (sosuList[i] && sosuList[(n - 4) - i]) {
				result.emplace_back(i);
				result.emplace_back((n - 4) - i);
				break;
			}
		}

	}
	else {
		result.emplace_back(2);
		result.emplace_back(3);

		for (int i = 2; i < (n-5) / 2 + 1; i++) {
			if (sosuList[i] && sosuList[(n - 5) - i]) {
				result.emplace_back(i);
				result.emplace_back((n - 5) - i);
				break;
			}
		}
	}

	if (result.size() == 4) {
		for (auto& num : result) {
			cout << num << " ";
		}
		cout << endl;
	}
	else {
		cout << "-1\n";
	}

}

