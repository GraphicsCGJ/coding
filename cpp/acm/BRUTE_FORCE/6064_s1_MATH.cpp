#include <iostream>

using namespace std;

int T;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int lcm(int a, int b) {
    return (a*b) / gcd(a,b);
}

int main(void) {
    cin >> T;

    while (T--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        // cout << gcd(M, N) << " " << lcm(M, N) << endl;
        int increment = 0;

        for (increment = 0; increment <= lcm(M, N); increment += M) {
            int curval = (increment + x);

            // if ((curval) % N == y) { // N일수도 있다...
            //     cout << curval << '\n';
            //     break;
            // }

            if ((curval % N == 0 ? N : curval % N) == y) {
                cout << curval << '\n';
                break;
            }
        }

        if (increment >= lcm(M, N)) {
            cout << -1 << '\n';
        }


    }


    return 0;
}