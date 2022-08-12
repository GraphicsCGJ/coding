#include <iostream>

using namespace std;

typedef long long ll;

ll x1, x2, y1, y2, x3, y3, x4, y4;

ll ep(ll ox, ll oy, ll ax, ll ay, ll bx, ll by) {
    ax = ax - ox;
    ay = ay - oy;
    bx = bx - ox;
    by = by - oy;

    return (ax * by) - (bx * ay);
}


int main(void) {

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    ll a, b;
    a = ep(x1, y1, x2, y2, x3, y3);
    b = ep(x1, y1, x2, y2, x4, y4);

    if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
        cout << 0 << endl;
        return 0;
    }

    a = ep(x3, y3, x4, y4, x1, y1);
    b = ep(x3, y3, x4, y4, x2, y2);

    if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
        cout << 0 << endl;
        return 0;
    }

    cout << 1 << endl;
    return 0;
}