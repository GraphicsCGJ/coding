#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int N;
double pn, ps, pw, pe;
double p_total = 0;

bool field [100][100];

void recur(int depth, int si, int sj, double p) {
    /* end condition */
    if (field[si][sj] == true)
        return;
    if (depth == N) {
        p_total += p;
        return;
    }

    field[si][sj] = true;
    recur(depth + 1, si + 1, sj, p * ps);
    recur(depth + 1, si, sj + 1, p * pe);
    recur(depth + 1, si - 1, sj, p * pn);
    recur(depth + 1, si, sj - 1, p * pw);
    field[si][sj] = false;
}

int main(void) {
    cin >> N;

    cin >> pe >> pw >> ps >> pn;
    pe *= 0.01;
    pw *= 0.01;
    ps *= 0.01;
    pn *= 0.01;

    memset(field, 0x00, 100 * 100);
    recur(0, 50, 50, 1);

    printf("%.15lf\n", p_total);
}