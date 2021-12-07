#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

typedef struct tmp_s tmp_t;
typedef struct tmp_s {
    int r[4];
    int c[4];
    int value;
};

vector<tmp_t> memoiz;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int maxVal;

bool check_tmp_v(vector<pair<int, int>>& tet) {
    for (int i = 0; i < memoiz.size(); i++) {
        bool flag = true;
        for (int j = 0; j < 4; j++) {
            if (memoiz[i].r[j] != tet[j].first || memoiz[i].c[j] != tet[j].second) {
                flag = false;
                break;
            }
        }
        if (flag == true)
            return true;
    }
    return false;
}

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
            if (check_tmp_v(tet) == false) {
                int sum = 0;
                tmp_t tmptmp;
                for (int i = 0; i < 4; i++) {
                    sum += v[tet[i].first][tet[i].second];
                    tmptmp.r[i] = tet[i].first;
                    tmptmp.c[i] = tet[i].second;
                }
                tmptmp.value = sum;
                memoiz.push_back(tmptmp);

                if (sum > maxVal)
                    maxVal = sum;
            }

            tet.pop_back();
        }
        else {
            pair<int, int> tet_check(-1, -1);
            s.push(tet_check);


            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < tet.size(); j++) {
                    int li = tet[j].first;
                    int lj = tet[j].first;
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

    for (int i = 0; i < memoiz.size(); i++) {
        for (int j = 0; j < 4; j++) {
            cout << "[" << memoiz[i].r[j] << "," << memoiz[i].c[j] << "]";
        }
        cout << " " << memoiz[i].value << endl;
    }

    cout << maxVal << endl;

    return 0;
}