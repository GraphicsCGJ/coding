#include<iostream>
#include<queue>

using namespace std;

typedef pair<int, int> P1;

int N, K;
int dp[100001];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    queue<P1> q;

    fill(dp, dp + 100001, 999999);

    cin >> N >> K;

    q.push(P1(N, 0));

    while (!q.empty()) {
        P1 p = q.front();
        q.pop();

        if (p.first < 0 || p.first > 100000 || dp[p.first] <= p.second)
            continue;

        dp[p.first] = p.second;

        q.push(P1(2 * p.first, p.second));
        q.push(P1(p.first + 1, p.second + 1));
        q.push(P1(p.first - 1, p.second + 1));
    }

    cout << dp[K] << '\n';

    return 0;
}