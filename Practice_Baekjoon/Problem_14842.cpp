#include"problem.h"
#include<iostream>
#include<vector>

using namespace std;

void Problem_14842::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout.tie(nullptr);

	int w{ 0 }, h{ 0 }, n{ 0 }; //가로, 세로, n등분
	std::cin >> w >> h >> n;

	std::vector<double> sero(n, 0.0);
	double dw = (double)w / n;
	double tanX = (double)h / w;

	for (int i = 0; i < n / 2; i++) {
		sero[i] = h - 2 * (dw * (i + 1)) * tanX;
	}

	double result = 0.0;

	for (int i = 0; i < n / 2; i++) {
		result += sero[i];
	}

	printf("%.6lf\n", result*2.0);
}