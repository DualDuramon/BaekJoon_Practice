#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);

    int length, width, height;
    int n;

    cin >> length >> width >> height;
    cin >> n;

    vector<int> cubes(20, 0);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        cubes[a] = b;
    }

    long long total_count = 0;
    long long filled = 0;

    for (int i = 19; i >= 0; --i) {
        filled <<= 3; // filled *= 8;
        long long limit = (long long)(length >> i) * (width >> i) * (height >> i);
        long long needed = limit - filled;

        long long use = min((long long)cubes[i], needed);

        total_count += use;
        filled += use;
    }

    if (filled == (long long)length * width * height) {
        cout << total_count << "\n";
    } else {
        cout << "-1\n";
    }
}

int main() {
    Solution();
    return 0;
}