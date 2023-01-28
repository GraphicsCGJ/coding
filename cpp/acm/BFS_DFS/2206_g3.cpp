#include <iostream>
#include <queue>

using namespace std;

class C1 {
public:
    int r;
    int c;
    int use;
    C1(int r, int c, int use) {
        this->r = r;
        this->c = c;
        this->use = use;
    }
};

int N, M;
int field[1000][1000];
int dst[1000][1000][2];

int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            field[i][j] = (s[j] - '0');
        }
    }

    queue<C1> q;
    q.push(C1(0,0,0));
    dst[0][0][0] = 1;
    dst[0][0][1] = 1;
    bool flg = false;
    while(!q.empty()) {
        C1 cur = q.front();
        q.pop();
        // cout << cur.r << ':' << cur.c << '\n';
        if (cur.r == N-1 && cur.c == M-1) {
            cout << dst[cur.r][cur.c][cur.use] << '\n';
            flg = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nxt_r = cur.r + dr[i];
            int nxt_c = cur.c + dc[i];
            if (nxt_r >= N || nxt_r < 0 || nxt_c >= M || nxt_c < 0)
                continue;
            if (field[nxt_r][nxt_c] == 1 && cur.use == 0 &&
                    (dst[nxt_r][nxt_c][1] == 0 || dst[nxt_r][nxt_c][1] > dst[cur.r][cur.c][cur.use] + 1)) {
                dst[nxt_r][nxt_c][1] = dst[cur.r][cur.c][cur.use] + 1;
                q.push(C1(nxt_r, nxt_c, 1));
            }
            if (field[nxt_r][nxt_c] == 0 &&
                    (dst[nxt_r][nxt_c][cur.use] == 0 || dst[nxt_r][nxt_c][cur.use] > dst[cur.r][cur.c][cur.use] + 1)) {
                dst[nxt_r][nxt_c][cur.use] = dst[cur.r][cur.c][cur.use] + 1;
                q.push(C1(nxt_r, nxt_c, cur.use));
            }
        }
    }

    if (!flg) {
        cout << -1 << '\n';
    }
    return 0;
}