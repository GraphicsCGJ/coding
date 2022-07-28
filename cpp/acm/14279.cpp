#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    int a, b, c, minval = 4000001;
    cin >> a >> b >> c;
    for (int i = 1; i <= 3333333; i++) {
        for (int j = 1; j <= 3333333; j++) {
            if (i * j > 3333333) break;

            int ta = i - a < 0 ? a - i : i - a;
            int tb = j - b < 0 ? b - j : j - b;
            int tc = i * j - c < 0 ? c - i * j : i * j - c;
            int minval_local = ta + tb + tc;

            if (minval_local < minval)
                minval = minval_local;
        }
    }

    cout << minval << endl;

    return 0;
}