#include "problem.h"
#include<iostream>
#include<set>
#include<string>

/*	링크 : https://www.acmicpc.net/problem/1181
*	티어 : 실버 V
*/

struct cmp {
	bool operator()(const std::string& str1, const std::string& str2) const {
		int length1 = str1.size();
		int length2 = str2.size();
		
		if (length1 == length2) {
			return str1 < str2;
		}
		else {
			return length1 < length2;
		}
	}
};

void Problem_1181::Solution() {
	int n{ 0 };
	std::cin >> n;

	std::set < std::string, cmp> list;
	
	for (int i = 0; i < n; i++) {
		std::string word;
		std::cin >> word;

		list.insert(word);
	}

	for (auto str : list) {
		std::cout << str << std::endl;
	}
}
