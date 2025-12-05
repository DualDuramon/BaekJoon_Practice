#include<iostream>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	long long n{ 0 };
	cin >> n;

	long long mok = n / 3;
	int last = n % 3;

	bool isSKWin = true;

	isSKWin = (mok % 2 != 0);

	for (int i = 0; i < last; i++) {
		isSKWin = !isSKWin;
	}

	cout << (isSKWin ? "SK\n" : "CY\n");

	return 0;
}
