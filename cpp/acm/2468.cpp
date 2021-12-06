#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

void dfs(
    vector<vector<int>>& v,
    vector<vector<int>>& visited,

    queue<pair<int,int>>& dfsmap,

    int n,
    int level

) {
    while (!dfsmap.empty()) {
        int row = dfsmap.front().first;
        int col = dfsmap.front().second;

        visited[row][col] = 1;
        dfsmap.pop();

        for (int i = 0; i < 4; i++) {
            int row2 = row + dy[i];
            int col2 = col + dx[i];

            if (row2 >= n || row2 < 0 || col2 >= n || col2 < 0 || visited[row2][col2] || v[row2][col2] <= level)
                continue;

            visited[row2][col2] = 1;
            dfsmap.push(pair<int,int>(row2, col2));
        }
    }
}

void count_map(vector<vector<int>>& v, int n, int level, int& cnt) {
    vector<vector<int>> visited(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && v[i][j] > level) {
                cnt++;
                queue<pair<int,int>> dfsmap;
                dfsmap.push(pair<int,int>(i,j));

                dfs(v, visited, dfsmap, n, level);
            }
        }
    }

}

int main(void) {
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));

    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            if (max < v[i][j])
                max = v[i][j];
        }
    }

    int max2 = 0;
    for (int i = 0; i <= max; i++) {
        int cnt = 0;
        count_map(v, n, i, cnt);
        if (max2 < cnt)
            max2 = cnt;
    }

    cout << max2 << endl;
}