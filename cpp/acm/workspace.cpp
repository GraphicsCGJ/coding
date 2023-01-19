#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MX 1000003

typedef pair<int, int> P1;
typedef pair<P1, int> P2;
int N, M;
int field[1000][1000];
bool visited[1000][1000];

int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};

vector<P1> vec1;

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            field[i][j] = c - '0';;
        }
    }
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << field[i][j];
    //     }cout << '\n';
    // }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {

            if (field[r][c] == 0) continue;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

                if (field[nr][nc] == 0) cnt++;
            }

            if (cnt >= 2)
                vec1.push_back(P1(r, c));
        }
    }

    int ans = MX;
    for (auto& p : vec1) {
        int& br = p.first;
        int& bc = p.second;

        fill(&visited[0][0], &visited[N-1][N], false);
        queue<P2> q;
        q.push(P2(P1(0,0), 0));

        visited[0][0] = true;
        int lans = MX;

        // cout << br << ':' << bc << '\n';
        field[br][bc] = 0;
        while (!q.empty()) {
            P1& pc = q.front().first;
            int dst = q.front().second;
            q.pop();
            dst++;
            int& cr = pc.first;
            int& cc = pc.second;
            // cout << '\t'<< cr << ':' << cc << '\n';
            if (cr == N-1 && cc == M-1) {
                lans = min(dst, lans);
                break;
            }
            for (int i = 0; i < 4; i++) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];
                if (nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc] || field[nr][nc] == 1) continue;
                visited[nr][nc] = true;
                q.push(P2(P1(nr, nc), dst));
            }
        }
        field[br][bc] = 1;
        if (lans < ans)
            ans = lans;
    }

    fill(&visited[0][0], &visited[N-1][N], false);
    queue<P2> q;
    q.push(P2(P1(0,0), 0));

    visited[0][0] = true;
    int lans = MX;

    while (!q.empty()) {
        P1& pc = q.front().first;
        int dst = q.front().second;
        q.pop();
        dst++;
        int& cr = pc.first;
        int& cc = pc.second;
        if (cr == N-1 && cc == M-1) {
            lans = min(dst, lans);
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc] || field[nr][nc] == 1) continue;
            visited[nr][nc] = true;
            q.push(P2(P1(nr, nc), dst));
        }
    }
    if (lans < ans)
        ans = lans;



    cout << (ans == MX ? -1 : ans) << '\n';

    return 0;
}