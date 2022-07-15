#include <iostream>
#include <cmath>

using namespace std;

int n, r, c;

int main(void) {
    cin >> n >> r >> c;
    int result = 0;
    while (n) {
        int n2 = n - 1;
        int factor = (int)pow(2, n2);
        int loc = 0;

        loc = r < factor ? 0 : 2;
        loc += c < factor ? 0 : 1;

        result += (int)pow(4, n2) * loc;

        r %= factor;
        c %= factor;

        n --;
    }

    cout << result << endl;

    return 0;
}