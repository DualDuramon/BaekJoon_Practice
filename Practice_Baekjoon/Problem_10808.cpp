#include "problem.h"
#include<iostream>
#include<vector>
#include<string.h>

/*	��ũ : https://www.acmicpc.net/problem/10808
*	Ƽ�� : ����� IV
*/

using namespace std;

void Problem_10808::Solution() {
	std::vector<int> charCount(26, 0);
	std::string str = "";

	std::cin >> str;
	
	for (char c : str) {
		charCount[c - 97]++;
	}

	for (int i : charCount) {
		std::cout << i << " ";
	}
};