#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

int N;
ll B;

ll orig[5][5];
ll h2[5][5];
ll h3[5][5];

ll tmp1[5][5];
ll tmp2[5][5];

inline static void cp_arr(ll (*a)[5], ll (*b)[5]) {
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            a[r][c] = b[r][c];
}

void init(ll (*a)[5]) {
    fill (&a[0][0], &a[4][5], 0);
    for (int r = 0; r < N; r++) {
        a[r][r] = 1;
    }
}

void mul(ll (*a)[5], ll (*b)[5]) {
    ll res[5][5];
    fill (&res[0][0], &res[4][5], 0);
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++) {
            for (int k = 0; k < N; k++) {
                res[r][c] += a[r][k] * b[k][c];
            }
            res[r][c] %= 1000;
        }

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            a[r][c] = res[r][c];
}

void mul2(ll (*a)[5], ll num) {
    ll t1[5][5];
    ll t2[5][5];

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            t2[r][c] = 0;

    init(t1);

    while (num--) {
        for (int r = 0; r < N; r++)
            for (int c = 0; c < N; c++) {
                t2[r][c] = 0;
                for (int k = 0; k < N; k++) {
                    t2[r][c] += t1[r][k] * a[k][c];
                }
                t2[r][c] %= 1000;
            }

        cp_arr(t1, t2);
    }
    cp_arr(a, t1);
}

void sol(ll (*a)[5], ll b) {
    if (b > 5) {
        ll a2[5][5];
        ll b2 = (ll) sqrt(b);

        cp_arr(a2, a);
        sol(a, b2);
        sol(a, b2);
        sol(a2, b-(b2*b2));
        mul(a, a2);
    }
    else {
        mul2(a, b);
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> B;
    init(orig);
    init(h2);
    init(h3);

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> orig[r][c];
        }
    }

    sol(orig, B);

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cout << orig[r][c] << ' ';
        }
        cout << '\n';
    }
    return 0;
}