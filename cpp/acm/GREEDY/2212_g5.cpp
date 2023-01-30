#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M;

int arr[10000];
int dst[10000];
int dst_sz;

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);


    cin >> N ;
    cin >> M;

    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr + N);
    for (int i = 0; i < N-1; i++) {
        if (arr[i+1] == arr[i]) continue;
        dst[dst_sz++] = arr[i+1] - arr[i];
    }

    sort(dst, dst + dst_sz);
    int sum = 0;
    for (int i = 0; i < dst_sz - (M-1); i++) {
        sum += dst[i];
    }

    cout << sum << '\n';

    return 0;
}
