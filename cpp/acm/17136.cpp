#include <iostream>

using namespace std;

#define MAX_VAL 10

int map[MAX_VAL][MAX_VAL];
int cnt[MAX_VAL];
int result;

void flip(int r, int c, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[r + i][c + j] = 1 - map[r + i][c + j];
        }
    }
}

void bruteforce(int r, int c, int n, int cnt2) {
    cout << "r: " << r << " c: " << c << " n: " << n << endl;
    if (n <= 0) return;

    if (cnt[n] <= 0) {
        bruteforce(0, 0, n - 1, cnt2);
    }

    if (r + n < MAX_VAL && c + n < MAX_VAL) {
        bool flag = true;
        int i, j;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (map[i][j] == 0) {
                    flag = false;
                    break;
                }
            }
        }

        if (!flag) {
            bruteforce(r, c + 1, n, cnt2);
        }
        else {
            flip(r, c, n);
            cnt[n] -= 1;
            /* check if all map is colored */
            bool flag = true;
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (map[i][j] == 1) {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag) // all map checked.
                result = (result < 0 ? cnt2 : (result > cnt2 ? cnt2 : result));
            else {
                bruteforce(i, j, n, cnt2 + 1);
            }

            flip(r, c, n);
            cnt[n] += 1;
            bruteforce(i, j + 1, n, cnt2);
        }
    }
    else {
        if (r + n >= MAX_VAL) {
            bruteforce(0, 0, n - 1, cnt2);
        }
        if (c + n >= MAX_VAL)
            bruteforce(r + 1, 0, n, cnt2);
    }
}

int main(void) {
    result = -1;

    for (int i = 0; i < MAX_VAL; i++) {
        for (int j = 0; j < MAX_VAL; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < MAX_VAL; i++) {
        cnt[i] = 5;
    }

    bruteforce(0, 0, 5, 0);

    cout << result << endl;

    return 0;
}