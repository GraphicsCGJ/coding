#include <iostream>

using namespace std;

int T;

int main(void) {
    cin >> T;

    while (T--) {
        int M, N, x, y;
        int li = 1, lj = 1;
        int cnt = 1;

        cin >> M >> N >> x >> y;

        do {
            if (x == li && lj == y) {
                cout << cnt << endl;
                break;
            }

            cnt++;

            li++; lj++;

            if (li > M) li = 1;
            if (lj > N) lj = 1;
        } while (li != 1 || lj != 1);

        if (cnt != 1 && li == 1 && lj == 1)
            cout << -1 << endl;
    }


    return 0;
}