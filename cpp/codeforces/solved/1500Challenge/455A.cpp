#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, M, A;
ll cnt[100001];
ll dp[100001][2];
ll input[100001];
ll tmp;

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> input[i];
        cnt[input[i]]++;
    }

    sort (input, input + N);

    for (int i = 0; i < N; i+=cnt[input[i]]) {
        int val = input[i];
        if (i == 0) {
            dp[val][0] = 0;
            dp[val][1] = val * cnt[val];
        }
        else {
            int preval = input[i - 1];
            if (cnt[val - 1] > 0) {
                dp[val][1] = dp[preval][0] + cnt[val] * val;
            }
            else {
                dp[val][1] = max(dp[preval][1], dp[preval][0]) + cnt[val] * val;
            }
            dp[val][0] = max(dp[preval][0], dp[preval][1]);
        }
    }

    cout << max(dp[input[N - 1]][0], dp[input[N-1]][1]) << '\n';

    return 0;
}

