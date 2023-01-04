#include <bits/stdc++.h>

using namespace std;

int T, N;
char lamp[100000];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;

    while (T--) {
        cin >> N;
        int r = -1, l = -1;
        for (int i = 0; i < N; i++) {
            cin >> lamp[i];
            if (r == -1 && lamp[i] == 'R') r = i;
            if (lamp[i] == 'L') l = i;
        }

        if (l == -1 || r == -1 || N == 1)
            cout << -1 << '\n';
        else {
            if (r > l) {
                if (r == 0)
                    cout << -1 << '\n';
                else
                    cout << r << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
    }



    return 0;
}

