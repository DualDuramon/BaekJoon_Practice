#include<iostream>
#include<vector>

using namespace std;

void DFS(vector<vector<bool>>& letterMask, vector<bool>& mask, int letterCount, int maxLetter, int startLoc, int& counter) {
	if (letterCount > maxLetter) 
		return;

	if (letterCount == maxLetter) 
	{
		int matchCounter = 0;
		

		for (int j = 0; j < letterMask.size(); j++) {
			bool canMakeThisWord = true;

			for (int i = 0; i < 26; ++i) {
				if (letterMask[j][i] && !mask[i]) {
					canMakeThisWord = false;
					break;
				}
			}

			if (canMakeThisWord) matchCounter++;
		}

		if (counter < matchCounter) {
			counter = matchCounter;
		}

		return;
	}

	for (int i = startLoc; i < 26; i++) {
		if (mask[i]) { continue; }
		mask[i] = true;
		DFS(letterMask, mask, letterCount + 1, maxLetter, i + 1, counter);
		mask[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t{ 0 }, n{ 0 };
	cin >> t >> n;

	vector<vector<bool>> letterMask(t, vector<bool>(26, false));
	vector<bool> mask(26, false);
	mask['a' - 'a'] = true;
	mask['n' - 'a'] = true;
	mask['t' - 'a'] = true;
	mask['i' - 'a'] = true;
	mask['c' - 'a'] = true;

	for (int i = 0; i < t; i++) {
		string str;
		cin >> str;

		for (auto ch : str) {
			letterMask[i][ch - 'a'] = true;
		}
	}
	int result = 0;

	DFS(letterMask, mask, 5, n, 1, result);

	cout << result << "\n";
	return 0;
}