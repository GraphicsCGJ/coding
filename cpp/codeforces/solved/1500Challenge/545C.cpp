#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

typedef pair<int, int> P1;

int N;
P1 arr[100001];
int dp[100001][3];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[0][2] = 1;

    for (int i = 1; i < N; i++) {
        if (arr[i].first - arr[i - 1].first > arr[i].second + arr[i - 1].second) {
            int *exdp = dp[i-1];

            int mx1 = max(exdp[0], exdp[1]);
            mx1 = max(mx1, exdp[2]);

            dp[i][0] = mx1 + 1;
            dp[i][1] = mx1;
            dp[i][2] = mx1 + 1;
        }
        else {
            int tmp[3];
            int *exdp = dp[i-1];
            fill(tmp,tmp+3, 0);

            if (arr[i].first - arr[i - 1].first > arr[i - 1].second) {
                int mx1 = max(exdp[0], exdp[1]);
                int mx2 = max(mx1, exdp[2]);

                if (arr[i].first - arr[i - 1].first > arr[i].second) {
                    dp[i][0] = max(mx2, mx1 + 1);
                    dp[i][1] = mx2;
                    dp[i][2] = mx2 + 1;
                }
                else {
                    dp[i][0] = mx2;
                    dp[i][1] = mx2;
                    dp[i][2] = mx2 + 1;
                }
            }
            else {
                exdp[2] = exdp[1];
                int mx1 = max(exdp[0], exdp[1]);

                if (arr[i].first - arr[i - 1].first > arr[i].second) {
                    dp[i][0] = mx1 + 1;
                    dp[i][1] = mx1;
                    dp[i][2] = mx1 + 1;
                }
                else {
                    dp[i][0] = mx1;
                    dp[i][1] = mx1;
                    dp[i][2] = mx1 + 1;
                }
            }
        }
    }

    int MX = -1;
    for (int i = 0; i < N; i++) {
        int mx1 = max(dp[i][0], dp[i][1]);
        mx1 = max (mx1, dp[i][2]);
        if (MX < mx1)
            MX = mx1;
    }

    cout << MX << '\n';


    return 0;
}

