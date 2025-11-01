#include<iostream>
#include<vector>

using namespace std;

void Solving() {
	int n{ 0 }, h{ 0 }, w{ 0 };
	cin >> h >> w >> n;

	//형태 YY XX or Y XX /  즉, Y는 층수, XX는 번호
	
	int floor = (n - 1) % h + 1;
	int room = (n - 1) / h + 1;

	printf("%d%02d\n", floor, room);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	cin >> n;

	for (int i = 0; i < n; i++) {
		Solving();
	}
    
    return 0;
}