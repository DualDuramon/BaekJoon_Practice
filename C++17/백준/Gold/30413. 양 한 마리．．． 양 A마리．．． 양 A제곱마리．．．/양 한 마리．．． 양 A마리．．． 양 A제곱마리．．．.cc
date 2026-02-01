#include<iostream>
#define MOD 1000000007

using namespace std;


int DivConq(long num, long depth) {
	if (depth == 0) return 1;
	if (depth == 1) return num;

	long long left{ 0 };
	long long right{ 0 };

	if (depth % 2 == 0) {
		left = right = DivConq(num, depth / 2) % MOD;
	}
	else {
		left = DivConq(num, depth / 2) % MOD;
		right = (num * left) % MOD;
	}

	return (right * left) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	long a, b;
	cin >> a >> b;

	if (a == 1) {
		cout << b % MOD << "\n";
		return 0;
	}

	long long numerator = DivConq(a, b);
	numerator = (numerator - 1 + MOD) % MOD;

	long long denominator_inv = DivConq(a - 1, MOD - 2);
	long long result = (numerator * denominator_inv) % MOD;

	cout << result << "\n";
	return 0;
}