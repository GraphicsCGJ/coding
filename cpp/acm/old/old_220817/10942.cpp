#include <iostream>

using namespace std;

int N;
int T;
int arr[2001];
int isPalin[2001][2001];

int check(int s, int e) {
    if (isPalin[s][e] > 0)
        return isPalin[s][e];
    if (s > e)
        return true;

    isPalin[s][e] = (arr[s] == arr[e] ? check(s+1, e-1) : 2);
    return isPalin[s][e];
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        for (int j = 1; j <= N; j++)
            isPalin[i][j] = 0;
    }

    cin >> T;
    while (T--) {
        int s, e;
        cin >> s >> e;
        int tmp = check(s, e);

        cout << tmp % 2 << "\n";
    }

    return 0;
}