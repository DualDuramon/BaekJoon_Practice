#include<iostream>
#include<vector>

using namespace std;
typedef vector<vector<int>> matrix;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 }, m{ 0 }, k{ 0 };

	cin >> n >> m;

	matrix matA(n, vector<int>(m)); //matA (n x m)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matA[i][j];
		}
	}

	cin >> m >> k;
	matrix matB(m, vector<int>(k)); //matB (m x k)
	for (int i = 0; i < m; i++) { 
		for (int j = 0; j < k; j++) {
			cin >> matB[i][j];
		}
	}

	matrix result(n, vector<int>(k)); //mat (n x k)

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int p = 0; p < m; p++) {
				result[i][j] += (matA[i][p] * matB[p][j]);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; j++) {
			cout << result[i][j]<<" ";
		}
		cout << "\n";
	}

	return 0;
}