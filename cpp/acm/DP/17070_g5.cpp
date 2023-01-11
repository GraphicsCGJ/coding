#include <iostream>
#include <queue>

using namespace std;

int N;

int field[16][16];
int dp[16][16][3];

int getValue(int r, int c, int dir) {
    /* already visited */
    // cout << r << ':' << c << ':' << dir << '\n';
    if (dp[r][c][dir] != -1) {
        return dp[r][c][dir];
    }
    /* if impossible */
    else if ((c == 0 && dir <= 1) || (r == 0 && dir >= 1)) {
        // cout << r << ':' << c << ':' << dir << '\n';
        return 0;
    }

    /* if wall*/
    else if ((dir == 0 || dir == 2) && field[r][c] == 1) {
        return 0;
    }
    else if (dir == 1 && (field[r][c] == 1 || field[r][c-1] == 1 || field[r-1][c] == 1)) {
        return 0;
    }

    else {
        // cout << "hi\n";
        if (dir == 0) {
            dp[r][c-1][0] = getValue(r, c-1, 0);
            dp[r][c-1][1] = getValue(r, c-1, 1);
            dp[r][c][dir] = dp[r][c-1][0] + dp[r][c-1][1];
        }
        else if (dir == 1) {
            dp[r-1][c-1][0] = getValue(r-1, c-1, 0);
            dp[r-1][c-1][1] = getValue(r-1, c-1, 1);
            dp[r-1][c-1][2] = getValue(r-1, c-1, 2);
            dp[r][c][dir] = dp[r-1][c-1][0] + dp[r-1][c-1][1] + dp[r-1][c-1][2];
        }
        else {
            dp[r-1][c][2] = getValue(r-1, c, 2);
            dp[r-1][c][1] = getValue(r-1, c, 1);
            dp[r][c][dir] = dp[r-1][c][2] + dp[r-1][c][1];
        }
        return dp[r][c][dir];
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    fill(&dp[0][0][0], &dp[15][15][16], -1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> field[i][j];
        }
    }

    dp[0][1][0] = 1;
    int val = getValue(N-1, N-1, 0) + getValue(N-1, N-1, 1) + getValue(N-1, N-1, 2);

    cout << val << '\n';
    return 0;
}