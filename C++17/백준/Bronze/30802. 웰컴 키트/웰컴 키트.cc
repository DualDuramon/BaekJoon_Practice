#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, t, p;
	cin >> n;

	vector<int> vec(6, 0);
	for (int i = 0; i < 6; ++i) {
		cin >> vec[i];
	}

	int totalShirt = 0;
	int couple_Pen = 0;
	int single_pen = 0;
	cin >> t >> p;
	
	for (int i = 0; i < 6; ++i) {
		totalShirt += (vec[i] / t) + (vec[i] % t > 0 ? 1 : 0);
	}

	couple_Pen = n / p;
	single_pen = n % p;
	
	cout << totalShirt << "\n";
	cout << couple_Pen << " " << single_pen<<"\n";

	return 0;
}