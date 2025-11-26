#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

void Solve(const string& str, vector<bool>& bitMap) {

	if (str.compare("add") == 0) {
		int n;
		cin >> n;

		bitMap[n - 1] = true;

	}

	else if (str.compare("remove") == 0) {
		int n;
		cin >> n;

		bitMap[n - 1] = false;
	}

	else if (str.compare("check") == 0) {
		int n;
		cin >> n;

		cout << (bitMap[n - 1] ? "1\n" : "0\n");	
	}
	
	else if (str.compare("toggle") == 0) {
		int n = 0;
		cin >> n;

		bitMap[n - 1] = !bitMap[n - 1];
	}
	
	else if (str.compare("all") == 0) {
		fill(bitMap.begin(), bitMap.end(), true);
	}
	
	else if (str.compare("empty") == 0) {
		fill(bitMap.begin(), bitMap.end(), false);
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	cin >> n;

	vector<bool> bitMap(20, false);

	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;

		Solve(str, bitMap);
	}
	return 0;
}