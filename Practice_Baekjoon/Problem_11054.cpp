#include"problem.h"
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void Problem_11054::Solution() 
{
	/*
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	cin >> n;

	vector<int> nums(n, 0);

	for (auto& num : nums) {
		cin >> num;
	}

	vector<int> dp(n, 1);
	vector<int> dpReverse(n, 1);
	dp[0] = dpReverse[n - 1] = 1;


	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (nums[j] > nums[i]) {
				dp[j] = max(dp[i] + 1, dp[j]);
			}
		}
	}

	for (int i = n - 1; 0 <= i; i--) {
		for (int j = i; 0 <= j; j--) {
			if (nums[j] > nums[i])
				dpReverse[j] = max(dpReverse[i] + 1, dpReverse[j]);
		}
	}

	int maxNum = 1;
	for (int i = 0; i < n; i++) {
		if (maxNum < dp[i] + dpReverse[i])
			maxNum = dp[i] + dpReverse[i];
	}
	std::cout << maxNum - 1 << "\n";
	*/

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n{ 0 };
	std::cin >> n;

	std::vector<int> vec(n, 0);
	std::vector<int> leastNums;
	leastNums.emplace_back(-1);

	for (auto& num : vec) {
		std::cin >> num;
	}

	for (int i = 0; i < n; i++) {
		if (vec[i] > leastNums.back()) {
			leastNums.emplace_back(vec[i]);
		}
		else if(vec[i] < leastNums.back()) {
			int low = 1;
			int high = leastNums.size() - 1;
			int mid = low + (high - low) / 2;

			while (low <= high) {
				if (leastNums[mid] == vec[i]) { break; }
				if (leastNums[mid] < vec[i]) {
					low = mid + 1;
				}
				else {
					high = mid - 1;
				}
				mid = low + (high - low) / 2 ;
			}

			if (leastNums[low] > vec[i]) leastNums[low] = vec[i];
		}
	}

	std::cout << leastNums.size() - 1 << "\n";
}