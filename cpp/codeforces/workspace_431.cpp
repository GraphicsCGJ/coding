#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

int N, K, D;
int dp[101][2];

int sol(int n, int idx) {
    if (dp[n][idx] != -1)
        return dp[n][idx];

    if (idx == 0) {
        int last = min(n, D-1);

        dp[n][0] = 0;
        for (int i = 1; i <= last; i++) {
            dp[n][0] += sol(n-i, 0);
        }

        return dp[n][0];
    }
    else {
        // dp[n][1] = (dp[n-1][0] + dp[n-2][0] + dp[n-(d-1)][0]);
        dp[n][1] = 0;
        for (int i = D; i <= n; i++) {
            dp[n][1] += sol(n-i, 0);
            dp[n][1] += sol(n-i, 1);
        }
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    fill(&dp[0][0], &dp[100][2], -1);
    dp[0][0] = 0;
    dp[1][0] = 1;
    dp[D][1] = 1;
    for (int i = 0; i < D; i++) {
        dp[i][1] = 0;
    }
    cin >> N >> K >> D;

    cout << sol(N, 1) << '\n';
    return 0;
}

