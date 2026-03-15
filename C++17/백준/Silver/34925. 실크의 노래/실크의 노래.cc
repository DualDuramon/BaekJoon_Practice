#include<iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	long long maxH, s;
	cin >> maxH >> s;

	long long currH = maxH; //맞으면 -2 , 회복하면 3
	long long healAmount = 3;

	if (maxH <= 2) {
		cout << 1 << "\n";
		return 0;
	}

	if (maxH <= 4) {
		healAmount = 2;
	}

	long long damagedCount = (healAmount * s + maxH + 1) / 2;

	cout << damagedCount << "\n";

	return 0;
}