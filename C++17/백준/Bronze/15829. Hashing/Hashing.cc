#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	string str;
	cin >> n >> str;

	int r{ 31 }, m{ 1234567891 };
	long long result{ 0 };

	for (int i = 0; i < str.size(); i++) {
		long long ch = str[i] - 'a' + 1;
		result = (result + ch * (long long)pow(r, i)) % m;
	}

	cout << result << "\n";
	return 0;
}
