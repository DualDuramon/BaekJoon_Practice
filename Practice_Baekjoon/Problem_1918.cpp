#include"problem.h"
#include<iostream>
#include<stack>

using namespace std;

int Problem_1918::CalCulateOrder(char c) {
	if (c == '*' || c == '/') return 2;
	if (c == '+' || c == '-') return 1;
	return 0;
}

void Problem_1918::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string expression;
	cin >> expression;

	stack<char> st;

	for (char c : expression) 
	{
		if ('A' <= c && c <= 'Z') {
			cout << c;
			continue;
		}

		if (c == '(' || st.empty()) {
			st.push(c);
			continue;
		}

		if (c == ')') {
			while (st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop();
			continue;
		}

		while (!st.empty() && CalCulateOrder(st.top()) >= CalCulateOrder(c)) {
			cout << st.top();
			st.pop();
		}
		st.push(c);

	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}

	cout << endl;
}