#include <iostream>

using namespace std;

int x1, x2, y1, y2, ox, oy;

int main(void) {

    cin >> ox >> oy;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    x1 -= ox;
    y1 -= oy;
    x2 -= ox;
    y2 -= oy;

    int ep = x1 * y2 - x2 * y1;
    if (ep < 0)
        cout << -1 << endl;
    else if (ep == 0)
        cout << 0 << endl;
    else
        cout << 1 << endl;

    return 0;
}