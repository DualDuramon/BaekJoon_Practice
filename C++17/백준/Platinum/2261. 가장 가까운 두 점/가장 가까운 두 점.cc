#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>

using namespace std;
typedef pair<int, int> dot; //x, y

struct yLess {
	bool operator() (dot& a, dot& b) {
		return a.second < b.second;
	}
};

int CalculateDist(dot& a, dot& b) {
	return (a.first - b.first)* (a.first - b.first) + (a.second - b.second)* (a.second - b.second);
}

int DivConq(vector<dot>& list, int startIdx, int endIdx)
{
	int minDist;
	if (endIdx - startIdx <= 2) {
		minDist = CalculateDist(list[startIdx], list[startIdx + 1]);
		for (int i = startIdx; i <= endIdx; ++i) {
			for (int j = i + 1; j <= endIdx; ++j) {
				minDist = min(minDist, CalculateDist(list[i], list[j]));
			}
		}
		return minDist;
	}

	int midIdx = (startIdx + endIdx) / 2;
	int left = DivConq(list, startIdx, midIdx);
	int right = DivConq(list, midIdx + 1, endIdx);
	minDist = min(left, right);

	vector<dot> tempList;

	for (int i = startIdx; i <= endIdx; ++i) {
		int xDist = list[i].first - list[midIdx].first;
		if (xDist * xDist < minDist) {
			tempList.emplace_back(list[i]);
		}
	}

	std::sort(tempList.begin(), tempList.end(), yLess());

	for (int i = 0; i < tempList.size(); ++i) {
		for (int j = i + 1; j < tempList.size(); ++j) {
			int yDist = tempList[j].second - tempList[i].second;
			if (yDist * yDist < minDist) {
				minDist = min(minDist, CalculateDist(tempList[i], tempList[j]));
			}
			else {
				break;
			}
		}
	}

	return minDist;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	cin >> n;

	vector<dot> dotList(n);
	for (int i = 0; i < n; i++) {
		auto& [x, y] = dotList[i];
		cin >> x >> y;
	}

	std::sort(dotList.begin(), dotList.end(), less<dot>());
	int result = DivConq(dotList, 0, n - 1);

	cout << result << "\n";

	return 0;
}