#include<iostream>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 }, m{ 0 }, b{ 0 };
	cin >> n >> m >> b;

	vector<vector<int>> map(n, vector<int>(m, 0)); // x, y
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int minTimer{ n * m * 2 * 257 };
	int height{ 0 };

	for (int h = 256; h >= 0; h--) {
		int neededBlocks = 0;
		int destroy = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] < h) {
					neededBlocks += (h - map[i][j]);
				}
				if (map[i][j] > h) {
					destroy += (map[i][j] - h);
				}
			}
		}
		if (neededBlocks <= (b + destroy) && minTimer > (neededBlocks + 2 * destroy)) {
			minTimer = neededBlocks + 2 * destroy;
			height = h;
		}
	}

	
	cout << minTimer << " " << height << "\n";
	return 0;
}