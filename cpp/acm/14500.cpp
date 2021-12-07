#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int maxVal;

bool check_tet( // aa is not in tet
    vector<pair<int, int>>& tet,
    vector<vector<int>>& visited,
    pair<int, int> aa
) {
    return (find(tet.begin(), tet.end(), aa) == tet.end() ? true : false) &&
            (visited[aa.first][aa.second] == 0 ? true : false);
}

void backtracking(
    vector<vector<int>>& v,
    vector<vector<int>>& visited,
    int n,
    int m,
    int si,
    int sj
) {
    stack<pair<int, int>> s;
    vector<pair<int, int>> tet;
    s.push(pair<int, int>(si, sj));

    while (!s.empty()) {
        int li = s.top().first;
        int lj = s.top().second;

        s.pop();

        if (li == -1 && lj == -1) {
            tet.pop_back();
            continue;
        }

        tet.push_back(pair<int, int>(li, lj));

        if (tet.size() == 4) {
            /* calc */
            int sum = 0;
            for (int i = 0; i < 4; i++) {
                sum += v[tet[i].first][tet[i].second];
                // cout << tet[i].first << ":" << tet[i].second << " ";
            }
            if (sum > maxVal)
                maxVal = sum;

            tet.pop_back();
        }
        else {
            pair<int, int> tet_check(-1, -1);
            s.push(tet_check);
            for (int i = 0; i < 4; i++) {
                int li2 = li + dx[i];
                int lj2 = lj + dy[i];
                pair<int, int> lp;
                lp.first = li2;
                lp.second = lj2;

                if (li2 < 0 || li2 >= n || lj2 < 0 || lj2 >= m || !check_tet(tet, visited, lp))
                    continue;

                s.push(lp);
            }
        }
    }
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

    maxVal = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vector<vector<int>> visited(n, vector<int>(m, 0));

            for (int ii = 0; ii <= i; ii++) {
                int jj = (ii == i) ? j : m;
                fill(&visited[ii][0], &visited[ii][jj], 1);
            }

            /* back tracking */
            backtracking(v, visited, n, m, i, j);
        }
    }

    cout << maxVal << endl;

    return 0;
}