#include<iostream>
#include<stack>
#include<string>

using namespace std;

void Solve(const string& str) {
	stack<char> st;
	char top = '.';

	for (auto& ch : str) {
		if (ch == '(' || ch == '[') {
			st.push(ch);
			continue;
		}
		else if (ch == ')') {
			if (st.empty() || st.top() == '[') {
				cout << "no\n";
				return;
			}

			st.pop();
		}
		else if (ch == ']') {
			if (st.empty() || st.top() == '(') {
				cout << "no\n";
				return;
			}
			st.pop();
		}
	}
	
	if (st.empty()) {
		cout << "yes\n";
	}
	else {
		cout << "no\n";
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	while (true) {
		string temp;
		getline(cin, temp);

		if (temp[0] == '.') {
			break;
		}
		Solve(temp);
	}
	
	return 0;
}
