#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int,int> P;

int N;
ll arr[500001];
ll arr2[500001];

ll ts;
ll cnt;

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        ts += arr[i];
    }

    if (ts % 3 == 0 &&  N >= 3) {
        ll target = ts / 3;
        ll sum1 = 0;
        ll sum2 = 0;

        for (int j = N - 2; j >= 0; j--) {
            sum1 += arr[j + 1];
            if (sum1 == target) {
                sum2++;
                // cout << j<< ':'<<sum2 << '\n';
            }
            arr2[j] = sum2;
        }

        sum1 = 0;
        for (int i = 0; i < N - 1; i++) {
            sum1 += arr[i];

            if (sum1 == target) {
                cnt += arr2[i + 1];
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}

