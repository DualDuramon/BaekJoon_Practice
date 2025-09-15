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

	vector<vector<int>> backpack(k + 1, vector<int>(n + 1, 0));
	vector<item> items(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> items[i].weight >> items[i].value;
	}

	for (int i = 1; i <= n; i++) {
		for (int w = 1; w <= k; w++) {
			if (w - items[i].weight < 0) {
				backpack[w][i] = backpack[w][i - 1];
				continue;
			}
			backpack[w][i] = max(backpack[w - items[i].weight][i - 1] + items[i].value, backpack[w][i - 1]);
		}	
	}
	

	cout << backpack[k][n] << endl;
	//return 0;
}