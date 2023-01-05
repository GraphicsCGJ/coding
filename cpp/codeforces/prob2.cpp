#include <bits/stdc++.h>

using namespace std;

int T, N;

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;

    while (T--) {
        cin >> N;
        if (N == 1) {
            cout << "YES" << '\n';
            cout << '1' << '\n';
        }
        else if (N % 2 == 0) {
            cout << "YES" << '\n';
            for (int i = 0; i < N; i++) {
                cout << (i % 2 == 0 ? -1 : 1);
                if (i != N - 1) cout << " ";
            }
            cout << '\n';
        }
        else if (N == 3)
            cout << "NO" << '\n';
        else {
            cout << "YES" << '\n';
            for (int i = 0; i < N; i++) {
                cout << (i % 2 == 1 ? N / 2 : 1 - (N / 2));
                if (i != N - 1) cout << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}

