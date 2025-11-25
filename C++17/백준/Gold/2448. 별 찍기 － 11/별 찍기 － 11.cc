#include<iostream>
#include<vector>

using namespace std;

typedef struct dot {
	int x;
	int y;

	dot() : x(0), y(0) {};
	dot(int x, int y) : x(x), y(y) {}
}dot;

void SetStar(vector<vector<char>>& map, dot d) {
	auto [x, y] = d;

	map[y][x] 
		= map[y - 1][x - 1] = map[y - 1][x + 1] = '*';

	for (int i = -2; i < 3; ++i) {
		map[y - 2][x + i] = '*';
	}
}

void DFS(vector<vector<char>>& map, const dot& ggok, const dot& left, const dot& right) {	
	if (ggok.y - left.y == 2) {
		SetStar(map, ggok);
		return;
	}

 	DFS(map, 
		ggok, 
		dot((ggok.x + left.x) / 2 + 1, (ggok.y + left.y) / 2 + 1),
		dot((right.x + ggok.x) / 2, (ggok.y + right.y) / 2 + 1));

	DFS(map, dot((ggok.x + left.x) / 2, (ggok.y + left.y) / 2), left, dot(ggok.x, left.y));
	DFS(map, dot((right.x + ggok.x) / 2, (ggok.y + right.y) / 2) , dot(ggok.x + 1, right.y), right);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	cin >> n;

	vector<vector<char>> map(n, vector<char>(n * 2, ' '));
	DFS(map, dot(n - 1, n - 1), dot(0, 0), dot(n * 2 - 1, 0));


	for (int i = n - 1; i >= 0; --i) {
		for (auto& ch : map[i]) {
			cout << ch;
		}
		cout << "\n";
	}
	return 0;
}
