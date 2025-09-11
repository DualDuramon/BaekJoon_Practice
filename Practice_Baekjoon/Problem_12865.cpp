#include"problem.h"
#include<iostream>
#include<vector>

using namespace std;

static struct item {
	int weight = 0;
	int value = 0;
};

//int main(){
void Problem_12865::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 }, k{ 0 };
	cin >> n >> k;

	vector<vector<int>> backpack(k + 1, vector<int>(n, 0));
	vector<item> items(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> items[i].weight >> items[i].value;
	}

	for (int i = 0; i <= k; i++) {
		
	}

	//넣었을때? 안넣었을때
	// 넣으면 -> 해당 무게를 뺀 백팩에서 n-1개의 아이템 가지고 백팩문제
	// 안넣으면 -> 해당 무게를 유지한 백팩에서 n-1개의 아이템 가지고 구하는 백팩문제
	

	//return 0;
}