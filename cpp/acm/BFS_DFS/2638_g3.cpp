#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int M;

int field[100][100];
bool visited[100][100];
pair<int,int> st[4];

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
int cheeseCnt;

void dfs(int r, int c) {

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 ||  nr >= N || nc < 0 || nc >= M)
            continue;

        if (field[nr][nc] > 0) {
            field[nr][nc]++;
        }
        else if(visited[nr][nc] == false) {
            visited[nr][nc] = true;
            dfs(nr, nc);
        }
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    st[0] = pair<int,int>(0,0);
    st[1] = pair<int,int>(0,M-1);
    st[2] = pair<int,int>(N-1,0);
    st[3] = pair<int,int>(N-1,M-1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> field[i][j];
            if (field[i][j] == 1) cheeseCnt++;
        }
    }
    int time = 0;
    while(cheeseCnt > 0) {
        fill(&visited[0][0], &visited[N-1][M], false);

        for (int ii = 0; ii < 4; ii++) {
            if (visited[st[ii].first][st[ii].second]) continue;

            visited[st[ii].first][st[ii].second] = true;
            dfs(st[ii].first, st[ii].second);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (field[i][j] > 0) {
                    if (field[i][j] > 2) {
                        cheeseCnt--; field[i][j] = 0;
                    }
                    else field[i][j] = 1;
                }
            }
        }
        time++;
    }
    cout << time << '\n';

    return 0;
}
