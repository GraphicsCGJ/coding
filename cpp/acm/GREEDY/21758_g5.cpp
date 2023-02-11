#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

int N, K;
int arr1[300000];
ll sumarr[300000];

inline ll rangesum(const int& l, const int& r) {
    if (r < l) return 0;
    return (sumarr[r] - sumarr[l] + arr1[l]);
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr1[i];
        sumarr[i] = i == 0 ? 0 : sumarr[i-1] + arr1[i];
    }

    ll MX = -1;

    for (int i = 1; i < N-1; i++) {
        ll l = rangesum(1, i-1);
        ll r = rangesum(i+1, N-2);

        ll localMX = l + r + r + arr1[N-1] * 2;
        ll localMX2 = l + l + r + arr1[0] * 2;
        ll localMX3 = rangesum(1, i) + rangesum(i, N-2);
        localMX = localMX < localMX2 ? localMX2 : localMX;
        localMX = localMX < localMX3 ? localMX3 : localMX;

        MX = MX < localMX ? localMX : MX;
    }

    cout << MX << '\n';

    return 0;
}