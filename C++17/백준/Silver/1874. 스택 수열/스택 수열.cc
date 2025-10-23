#include<iostream>
#include<stack>
#include<vector>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	
	int n{ 0 };
	std::cin >> n;

	std::stack<int> st;
	std::vector<char>result;
	std::vector<int> nums(n);

	for (int i = 0; i < n; i++) {
		std::cin >> nums[i];
	}

	int counter = 0;

	for (int i = 1; i <= n; i++) {
		st.push(i);
		result.push_back('+');
		
		while (!st.empty()&&st.top() == nums[counter]) {
			st.pop();
			result.push_back('-');
			if (counter + 1 < n) counter++;
			else break;
		}
	}

	if (!st.empty()) {
		std::cout << "NO\n";
	}
	else {
		for (auto i : result) std::cout << i<<"\n";
		//std::cout <<"\n";
	}


	return 0;
}