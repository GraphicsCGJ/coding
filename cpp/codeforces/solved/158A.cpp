#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[50];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> arr[i];
    K--;

    int orig = arr[K];
    if (N - 1 > K) {
        for (int i = K + 1; i < N; i++)
            if (arr[i] == orig) K++;
    }

    int cnt = 0;
    for (int i = K; i>=0; i--) {
        if (arr[i] != 0) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}

