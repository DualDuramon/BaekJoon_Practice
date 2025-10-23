#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 }, nowNum{ 1 };
	cin >> n;

	vector<int> answer(n, 0);
	int answerIdx = 0;
	for (int i = 0; i < answer.size(); ++i) {
		cin >> answer[i];
	}

	stack<int> st;
	vector<char> result;

	st.push(nowNum++);
	result.push_back('+');

	while (nowNum <= n+1) {
		if (answerIdx >= answer.size()) break;

		if (st.empty() || st.top() != answer[answerIdx]) {
			st.push(nowNum++);
			result.push_back('+');
		}
		else {
			st.pop();
			++answerIdx;
			result.push_back('-');
		}
	}

	if (answerIdx < answer.size()) {
		cout << "NO\n";
	}
	else {
		for (auto i : result)
			cout << i << "\n";
	}


	return 0;
}