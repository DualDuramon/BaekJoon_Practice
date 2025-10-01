#include"problem.h"
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct consult {
	int time;
	int value;

	consult(int t, int p) {
		this->time = t;
		this->value = p;
	}
	consult() {
		this->time = 0;
		this->value = 0;
	}
};

//int main(){
void Problem_14501::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	cin >> n;

	vector<consult> chart(n + 2);
	for (int i = 1; i <= n; i++) {
		cin >> chart[i].time >> chart[i].value;
	}

	vector<int> maxValue(n + 2, 0);

	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++) {
			if (j + chart[j].time <= n + 1) {
				maxValue[j + chart[j].time] = max(maxValue[j + chart[j].time], maxValue[i] + chart[j].value);
			}
		}
	}

	cout << *max_element(maxValue.begin(), maxValue.end()) << endl;
	//return 0;
}