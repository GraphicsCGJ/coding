#include <iostream>

using namespace std;

int field[1024][1024];
int N, M;

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;


    for (int r = 0; r < N; r++) {
        int accum = 0;
        for (int c = 0; c < N; c++) {
            int tmp;
            cin >> tmp;
            accum += tmp;
            field[r][c] = r == 0 ? accum : field[r - 1][c] + accum;
        }
    }

    // for (int r = 0; r < N; r++) {

    //     for (int c = 0; c < N; c++) {
    //         cout << field[r][c] << ' ';
    //     }
    //     cout << '\n';
    // }

    for (int i = 0; i < M; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;

        int sum = field[r2][c2];
        if (r1 > 0) {
            sum -= field[r1 - 1][c2];
            if (c1 > 0)
                sum += field[r1 - 1][c1 - 1];
        }

        if (c1 > 0) {
            sum -= field[r2][c1 - 1];
        }

        cout << sum << '\n';

    }


    return 0;
}