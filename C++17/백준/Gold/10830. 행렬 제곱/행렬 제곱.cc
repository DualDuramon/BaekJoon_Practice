#include<iostream>
#include<vector>
#define MOD 1000

using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;


void MatrixMultiply(matrix& a, matrix& b) {
	int n = a.size();
	matrix temp(n, vector<ll>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			for (int j = 0; j < n; j++) {
				temp[i][j] = (temp[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}

	a = temp;
}

void MatrixPow(matrix& mat, matrix& res, ll exp) {
	int n = mat.size();

	while (exp > 0) {
		if (exp == 1) {
			MatrixMultiply(res, mat);
			break;
		}
		if (exp % 2 == 1) {
			MatrixMultiply(res, mat);
		}
		MatrixMultiply(mat, mat);
		exp /= 2;
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ll n, t;
	cin >> n >> t;

	matrix mat(n, vector<ll>(n, 0));
	matrix res(n, vector<ll>(n, 0));


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
		res[i][i] = 1;
	}

	MatrixPow(mat, res, t);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << res[i][j]<<" ";
		}
		cout << "\n";
	}

	return 0;
}