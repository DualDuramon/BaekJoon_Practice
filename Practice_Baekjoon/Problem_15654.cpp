#include"problem.h"
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

void Problem_15654::backtracking(const vector<int>& list, vector<int>& nowSet, vector<bool>& selected, int nowIdx, int maxLength) {
	if (nowSet.size() == maxLength) {
		for (auto i : nowSet) cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < list.size(); i++) 
	{
		if (selected[i]) continue;

		nowSet.push_back(list[i]);
		selected[i] = true;

		backtracking(list, nowSet, selected, i, maxLength);
		
		nowSet.pop_back();
		selected[i] = false;
	}

}

//int main() {
void Problem_15654::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 }, m{ 0 };
	cin >> n >> m;

	vector<int> list(n,-1);
	vector<bool> selected(n, false);
	vector<int> nowSet;

	for (int i = 0; i < n; i++) cin >> list[i];
	std::sort(list.begin(), list.end(), std::less<int>());

	backtracking(list, nowSet, selected, 0, m);

	//return 0;
}