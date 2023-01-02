#include <iostream>
#include <stack>

using namespace std;

int N;
char m[100][100];
bool visited[100][100];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

inline static bool cmp(char a, char b) {
    if (a == 'R' || a == 'G') {
        return (b == 'R' || b == 'G');
    }
    else
        return a == b;
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> m[i][j];
        }
    }

    fill(&visited[0][0], &visited[N - 1][N], false);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == false) {
                /* dfs start */
                char c = m[i][j];

                stack<pair<int,int>> s;
                s.emplace(i, j);
                visited[i][j] = true;

                while (!s.empty()) {
                    auto si = s.top();
                    s.pop();
                    int &ii = si.first;
                    int &jj = si.second;

                    for (int idx = 0; idx < 4; idx++) {
                        int ii2 = ii + dx[idx];
                        int jj2 = jj + dy[idx];

                        if (ii2 < 0 || ii2 >= N || jj2 < 0 || jj2 >= N || visited[ii2][jj2] == true || m[ii2][jj2] != c)
                            continue;

                        visited[ii2][jj2] = true;
                        s.emplace(ii2, jj2);
                    }
                }
                cnt++;
            }
        }
    }
    cout << cnt << " ";

    fill(&visited[0][0], &visited[N - 1][N], false);
    cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == false) {
                /* dfs start */
                char c = m[i][j];

                stack<pair<int,int>> s;
                s.emplace(i, j);
                visited[i][j] = true;

                while (!s.empty()) {
                    auto si = s.top();
                    s.pop();
                    int &ii = si.first;
                    int &jj = si.second;

                    for (int idx = 0; idx < 4; idx++) {
                        int ii2 = ii + dx[idx];
                        int jj2 = jj + dy[idx];

                        if (ii2 < 0 || ii2 >= N || jj2 < 0 || jj2 >= N || visited[ii2][jj2] == true || !cmp(c, m[ii2][jj2]))
                            continue;

                        visited[ii2][jj2] = true;
                        s.emplace(ii2, jj2);
                    }
                }
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}