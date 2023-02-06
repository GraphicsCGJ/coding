#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;
int arr[300000];
int dif[300000];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    for (int i = 0; i < N - 1; i++) dif[i] = arr[i + 1] - arr[i];
    sort(dif, dif + N-1);

    int sum = 0;
    for (int i = 0; i < N-1 - (K-1); i++) {
        sum += dif[i];
    }

    cout << sum << '\n';

    return 0;
}