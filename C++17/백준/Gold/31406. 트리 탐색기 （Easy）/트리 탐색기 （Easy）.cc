#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void DFS(int node, const vector<vector<int>>& directory, const vector<bool>& toggle, vector<int>& visible_list) {
    visible_list.push_back(node);

    if (toggle[node]) {
        for (int child : directory[node]) {
            DFS(child, directory, toggle, visible_list);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n{ 0 }, q{ 0 };
    cin >> n >> q;

    vector<vector<int>> directory(n + 1, vector<int>());
    vector<bool> toggle(n + 1, false);

    for (int i = 1; i <= n; i++) {
        int num = 0;
        cin >> num;
        if (num == 0) continue;

        directory[i].resize(num);
        for (int j = 0; j < num; j++) {
            cin >> directory[i][j];
        }
    }

    int cursor = directory[1][0];
    string str = "";
    vector<int> visible_list; 

    for (int k = 0; k < q; k++) {
        cin >> str;

        if (str[0] == 't') {
            toggle[cursor] = !toggle[cursor];
        }
        else { //move
            int num = 0;
            cin >> num;

            visible_list.clear();
            for (int child : directory[1]) {
                DFS(child, directory, toggle, visible_list);
            }
            int current_idx = 0;
            for (int i = 0; i < visible_list.size(); i++) {
                if (visible_list[i] == cursor) {
                    current_idx = i;
                    break;
                }
            }

            int next_idx = current_idx + num;

            next_idx = max(0, min(next_idx, (int)visible_list.size() - 1));

            cursor = visible_list[next_idx];
            cout << cursor << "\n";
        }
    }
    
    return 0;
}