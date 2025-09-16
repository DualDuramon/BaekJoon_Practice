#include"problem.h"
#include<iostream>
#include<vector>

using namespace std;

void Problem_15652::Backtracking(vector<int>& nowSet, int nowNum, int maxNum, int maxLength) {
	if (nowSet.size() == maxLength) {
		for (auto n : nowSet) {
			cout << n << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = nowNum; i <= maxNum; i++) {
		nowSet.push_back(i);
		Backtracking(nowSet, i, maxNum, maxLength);
		nowSet.pop_back();
	}
}

//int main()
void Problem_15652::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 }, m{ 0 };
	cin >> n >> m;

	vector<int> mySet;

	Backtracking(mySet, 1, n, m);
	//return 0;
}