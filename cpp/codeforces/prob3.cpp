#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T, N, M;
ll arr[4 * 100000];
int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;

    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        int cnt = 0;
        M--;

        ll localSum = 0;

        if (M > 0) {
            for (int i = M; i >= 0; i--) {
                localSum += arr[i];
                if (localSum > 0) {
                    // cout << i << ' ';
                    localSum = localSum - arr[i] - arr[i];
                    cnt ++;
                }
            }
        }

        localSum = 0;
        for (int i = M + 1; i < N; i++) {
            localSum += arr[i];
            if (localSum < 0) {
                // cout << i << ' ';
                localSum = localSum - arr[i] - arr[i];
                cnt ++;
            }
        }
        // cout << '\n';
        cout << cnt << '\n';
    }
    return 0;
}

