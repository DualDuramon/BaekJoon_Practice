#include<iostream>
#include<vector>
using namespace std;

/*
* 백준 11047번
* 
* 
*/


int main(void) {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n{ 0 };
	int k{ 0 };
	std::cin >> n >> k;
	
	std::vector<int> coins(n,0);
	for (int i = 0; i < n; i++) {
		std::cin >> coins[i];	//값 입력
	}

	int count = 0;
	for (auto j = coins.rbegin(); j != coins.rend(); j++) {
		if (*j > k) continue;
		count += (k / *j);
		k %= *j;
	}

	std::cout << count << "\n";

	return 0;
}