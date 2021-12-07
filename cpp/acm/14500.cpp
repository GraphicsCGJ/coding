#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool check_tet( // aa is not in tet
    vector<pair<int, int>>& tet,
    vector<vector<int>>& visited,
    pair<int, int> aa
) {
    return (find(tet.begin(), tet.end(), aa) == tet.end() ? true : false) &&
            (visited[aa.first][aa.second] == 0 ? true : false);
}

int dfs(
    vector<vector<int>>& v,
    vector<vector<int>>& visited,
    int n,
    int m,
    int si,
    int sj
) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> tet;
    q.push(pair<int, int>(si, sj));

    while (!q.empty()) {
        int li = q.front().first;
        int lj = q.front().second;

        q.pop();
        tet.push_back(pair<int, int>(li, lj));

        if (tet.size() == 4) {
            /* calc */
            for (int i = 0; i < 4; i++) {
                cout << i << " ";
            }
            cout << endl;

            tet.pop_back();
            continue;
        }
        else {
            for (int i = 0; i < 4; i++) {
                int li2 = li + dx[i];
                int lj2 = lj + dy[i];
                pair<int, int> lp;
                lp.first = li2;
                lp.second = lj2;

                if (li2 < 0 || li2 >= n || lj2 < 0 || lj2 >= m || !check_tet(tet, visited, lp))
                    continue;

                q.push(lp);
            }
        }
    }

    return 0;
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vector<vector<int>> visited(n, vector<int>(m, 0));

            for (int ii = 0; ii <= i; ii++) {
                int jj = (ii == i) ? j + 1 : m;
                fill(&visited[ii][0], &visited[ii][jj], 1);
            }

            /* bfs */
            int local_max = dfs(v, visited, n, m, i, j);
            if (local_max > max)
                max = local_max;
        }
    }

    cout << max << endl;

    return 0;
}