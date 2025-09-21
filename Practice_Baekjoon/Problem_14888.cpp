#include"problem.h"
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void backtracking(const vector<int>& nums, vector<int>& operations, int& nowMax, int& nowMin, int nowResult, int nowIdx) {
	if (nowIdx == nums.size()) {
		nowMax = std::max(nowMax, nowResult);
		nowMin = std::min(nowMin, nowResult);
		return;
	}
	

	for (int i = 0; i < 4; i++) {
		if (operations[i] == 0) continue;
		operations[i]--;

		switch (i) {
		case 0 :
			backtracking(nums, operations, nowMax, nowMin, nowResult + nums[nowIdx], nowIdx + 1);
			break;
		case 1:
			backtracking(nums, operations, nowMax, nowMin, nowResult - nums[nowIdx], nowIdx + 1);
			break;
		case 2:
			backtracking(nums, operations, nowMax, nowMin, nowResult * nums[nowIdx], nowIdx + 1);
			break;
		case 3:
			backtracking(nums, operations, nowMax, nowMin, nowResult / nums[nowIdx], nowIdx + 1);
			break;
		}
		operations[i]++;
	}

}

//int main(){
void Problem_14888::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	cin >> n;
	
	vector<int> num(n, 0);
	vector<int> operation(4, 0);

	int max{ INT_MIN };
	int min{ INT_MAX };

	for (int i = 0; i < n; i++) cin >> num[i];
	for (int i = 0; i < 4; i++) cin >> operation[i];

	backtracking(num, operation, max, min, num[0], 1);
	cout << max << "\n" << min << endl;
	//return 0;
}