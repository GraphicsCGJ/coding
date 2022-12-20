/*
1629
Multiplication
*/

#include<iostream>

using namespace std;

typedef long long ll;


int main(void) {
    ll a, b, c;
    ll a2;
    int l = 0, r = 0;
    int isodd = 0;

    cin >> a >> b >> c;
    a2 = 1;

    if (b == 1) {
        cout << a % c << endl;
        return 0;
    }

    while (b != 1) {
        if (b % 2 == 1) {
            a2 = (a2 * a) % c;
            b -= 1;
        }
        else {
            a = (a * a) % c;
            b /= 2;
        }
    }

    cout << (a * a2) % c << endl;

    return 0;
}