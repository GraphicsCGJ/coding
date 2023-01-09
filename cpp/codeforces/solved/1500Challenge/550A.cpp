#include <bits/stdc++.h>

using namespace std;



int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    char ppc = 0x00;
    char pc = 0x00;
    char c = 0x00;
    char buf[5];

    int firstab = -1;
    int firstba = -1;
    int curab = -1;
    int curba = -1;
    int cur = 0;
    bool rst = false;
    while (c != '\n') {
        cin.get(c);

        if (pc == 'B' && c == 'A') {
            if (firstba == -1)
                firstba = cur;
            curba = cur;
            if (firstab != -1 && curba - firstab > 1) {
                rst = true;
            }
        }

        if (pc == 'A' && c == 'B') {
            if (firstab == -1)
                firstab = cur;
            curab = cur;
            if (firstba != -1 && curab - firstba > 1) {
                rst = true;
            }
        }

        ppc = pc;
        pc = c;
        cur ++;
    }

    cout << (rst ? "YES" : "NO") << '\n';

    return 0;
}

