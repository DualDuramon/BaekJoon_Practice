#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int Tournament(int jimin, int hansu, int depth, int maxDepth) {
	if (jimin % 2 == 0 && (hansu - jimin) == 1) {
		return depth;
	}
	else if (depth > maxDepth) {
		return -1;
	}

	return Tournament(jimin / 2, hansu / 2, depth + 1, maxDepth);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 }, jimin{ 0 }, hansu{ 0 };
	cin >> n >> jimin >> hansu;
	if (jimin > hansu) {
		int temp = hansu;
		hansu = jimin;
		jimin = temp;
	}

	cout << Tournament(jimin-1, hansu-1, 1, n / 2) << "\n";
	return 0;
}