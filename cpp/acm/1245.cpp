#include <iostream>

using namespace std;

int field[101][71];
bool visited[101][71];
int N, M;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int cnt = 0;

void dfs(int i, int j, bool &ispeek) {
    /* check */
    // cout << i << " " << j << endl;

    visited[i][j] = true;
    /* check 1. is peek ?*/
    if (ispeek == true) {
        for (int ii = 0; ii < 8; ii++) {
            int li = i + dx[ii];
            int lj = j + dy[ii];

            if (li < N && li >= 0 && lj < M && lj >= 0) {
                if (field[li][lj] > field[i][j])
                    ispeek = false;
            }
        }
    }

    /* check 2. dfs */
    for (int ii = 0; ii < 8; ii++) {
        int li = i + dx[ii];
        int lj = j + dy[ii];

        if (li < N && li >= 0 && lj < M && lj >= 0) {
            if (field[li][lj] == field[i][j] && visited[li][lj] == false) {
                dfs(li, lj, ispeek);
            }
        }
    }
}

int main(void) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> field[i][j];
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j])
                continue;
            if (field[i][j] == 0) {
                visited[i][j] = true;
                continue;
            }

            bool tmp = true;
            dfs(i, j, tmp);
            if (tmp) {
                // cout << i << " "<< j  << endl;
                cnt ++;
            }
        }
    }

    cout << cnt << endl;
}
