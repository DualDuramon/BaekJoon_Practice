#include"problem.h"
#include<iostream>
#include<vector>

using namespace std;

void Problem_15650::Backtracking(vector<int>& nowSet, int startNum, int maxNum, int maxLength) {
	if (nowSet.size() == maxLength) {
		for (int n : nowSet) {
			cout << n << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = startNum + 1; i <= maxNum; i++) {
		nowSet.emplace_back(i);
		Backtracking(nowSet, i, maxNum, maxLength);
		nowSet.pop_back();
	}
}

//int main(){
void Problem_15650::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 }, m{ 0 };
	cin >> n >> m; //최대 수, 수열 길이
	vector<int> mySet;

	for (int i = 1; i <= n; i++) {
		mySet.emplace_back(i);
		Backtracking(mySet, i, n, m);
		mySet.pop_back();
	}

	//return 0;
}
