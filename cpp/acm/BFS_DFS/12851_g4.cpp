#include <iostream>
#include <queue>

using namespace std;

#define MX 200001

typedef pair<int,int> P1;

int N, K;

int dp[100001];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;

    fill(dp, dp+100001, MX);
    // dp[0] = 0;

    queue<P1> q;

    q.push(P1(N,0));

    int cnt = 0;
    while (!q.empty()) {
        P1 p = q.front();
        int& cur = p.first;
        int& dist = p.second;
        q.pop();

        // cout << cur << ':' << dist << '\n';
        if (cur > 100000 || cur < 0) continue;

        if (dp[cur] > dist) {
            dp[cur] = dist;
            if (cur == K)
                cnt = 1;
        }
        else if (dp[cur] == dist) {
            if (cur == K)
                cnt++;
        }
        else
            continue;

        if (cur * 2 <= 100000 && dp[cur * 2] > dist + 1)
            q.push(P1(cur * 2, dist + 1));
        if (cur + 1 <= 100000 && dp[cur + 1] > dist + 1)
            q.push(P1(cur + 1, dist + 1));
        if (cur - 1 >= 0 && dp[cur - 1] > dist + 1)
            q.push(P1(cur - 1, dist + 1));
    }

    cout << dp[K] << '\n' << cnt << '\n';

    return 0;
}


