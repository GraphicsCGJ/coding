#include <iostream>

using namespace std;

int map[10][10];
int papers[6];

int mincnt;

void calc(int factor, int cnt, int i_in, int j_in) {
    cout << factor << " " << cnt << " " << i_in << " " << j_in << endl;

    /* papers check */
    bool check = true;
    if (factor <= 0) return;

    for (int i = 0; i < 10 && check == true; i++) {
        for (int j = 0; j < 10 && check == true; j++) {
            if (map[i][j] != 0)
                check = false;
        }
    }
    if (check == true) {
        if (mincnt > cnt) {
            mincnt = cnt;
            return;
        }
    }

    if (papers[factor] == 0) {
        factor--;
        i_in = 0; j_in = 0;
        if (factor <= 0) return;
    }

    /* map check */
    for (int i = i_in; i <= 10 - factor; i++) {
        for (int j = j_in; j <= 10 - factor; j++) {
            check = true;
            for (int ii = i; ii < i + factor && check; ii++) {
                for (int jj = j; jj < j + factor && check; jj++) {
                    if (map[ii][jj] == 0)
                        check = false;
                }
            }

            if (check == true) {
                /* in */
                papers[factor] --;
                for (int ii = i; ii < i + factor && check; ii++) {
                    for (int jj = j; jj < j + factor && check; jj++) {
                        map[ii][jj] = 0;
                    }
                }
                calc(factor, cnt + 1, i, j + 1);
                papers[factor] ++;
                for (int ii = i; ii < i + factor && check; ii++) {
                    for (int jj = j; jj < j + factor && check; jj++) {
                        map[ii][jj] = 1;
                    }
                }

                /* not in */
                calc(factor, cnt, i, j + 1);
            }
        }
    }
    calc(factor - 1, cnt, 0, 0);
}

int main(void) {
    mincnt = 100;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= 5; i++) {
        papers[i] = 5;
    }

    calc(5, 0, 0, 0);

    if (mincnt == 100)
        cout << -1 << endl;
    else
        cout << mincnt << endl;

    return 0;
}