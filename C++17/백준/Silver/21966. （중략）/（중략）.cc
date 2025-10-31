#include<iostream>
#include<string>

using namespace std;
//대문자, 소문자, 쉼표, 마침표
//아스키 코드는 각각 65~90, 97~122, 44, 46이다.


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	string str;

	cin >> n >> str;

	if (n <= 25) {
		cout << str << "\n";
		return 0;
	}

	bool isDoubleDot = false;
	bool onePhraseTrigger = false;

	for (int i = 10; i < n - 11; i++) {
		if (onePhraseTrigger) {
			isDoubleDot = true;
			break;
		}

		onePhraseTrigger = str[i] == '.';
	}

	if (isDoubleDot) {
		for (int i = 0; i < 9; ++i) {
			cout << str[i];
		}

		cout << "......";
		for (int i = n - 10; i < n; i++) {
			cout << str[i];
		}
	}
	else {
		for (int i = 0; i < 11; ++i) {
			cout << str[i];
		}

		cout << "...";
		for (int i = n - 11; i < n; i++) {
			cout << str[i];
		}
	}

	cout << "\n";
	
	return 0;
}