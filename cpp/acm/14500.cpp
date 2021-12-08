#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;
#define SIZE 500

int n, m;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int v[SIZE][SIZE];
bool visited[SIZE][SIZE];

int maxVal;
vector<pair<int, int>> tet;

void dfs(
    int si,
    int sj
) {

    stack<pair<int, int>> s;
    s.push(pair<int, int>(si, sj));

    while (!s.empty()) {
        int li = s.top().first;
        int lj = s.top().second;

        s.pop();
        if (li == -1 && lj == -1) {

            visited[tet.back().first][tet.back().second] = false;
            tet.pop_back();

            continue;
        }

        tet.push_back(pair<int, int>(li, lj));
        visited[li][lj] = true;

        if (tet.size() == 4) {
            /* calc */
            int sum = 0;
            for (int i = 0; i < 4; i++) {
                sum += v[tet[i].first][tet[i].second];
            }

            if (sum > maxVal)
                maxVal = sum;

            visited[tet.back().first][tet.back().second] = false;
            tet.pop_back();
        }
        else {
            pair<int, int> tet_check(-1, -1);
            s.push(tet_check);

            for (int i = 0; i < 4; i++) {
                pair<int, int> lp;
                lp.first = li + dx[i];
                lp.second = lj + dy[i];;

                if (lp.first < 0 || lp.first >= n || lp.second < 0 || lp.second >= m || visited[lp.first][lp.second] == true)
                    continue;

                s.push(lp);
            }
        }
    }
}

void case1(int i, int j) { // ㅓ ㅏ
    int sum = v[i+1][j] + v[i][j+1] + v[i+1][j+1] + v[i+2][j+1];
    if (sum > maxVal) maxVal = sum;
    sum = v[i+1][j+1] + v[i][j] + v[i+1][j] + v[i+2][j];
    if (sum > maxVal) maxVal = sum;
}

void case2(int i, int j) { // ㅗ ㅜ
    int sum = v[i][j+1] + v[i+1][j] + v[i+1][j+1] + v[i+1][j+2];
    if (sum > maxVal) maxVal = sum;
    sum = v[i+1][j+1] + v[i][j] + v[i][j+1] + v[i][j+2];
    if (sum > maxVal) maxVal = sum;
}

int main(void) {
    tet.reserve(100);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    maxVal = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            memset(visited, false, sizeof(visited));

            /* back tracking */
            dfs(i, j);
            /* exception cases */
            if (i + 2 < n && j + 1 < m) case1(i, j);
            if (i + 1 < n && j + 2 < m) case2(i, j);
        }
    }
    cout << maxVal << endl;

    return 0;
}