#include <iostream>

using namespace std;

int fibo[10000000];
int T, N, M;
int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;



    while(T--) {
        cin >> N >> M;

        int sz = 0;
        fibo[sz++] = 0;
        fibo[sz++] = 1;
        fibo[sz++] = 1;

        while (true) {
            if (fibo[sz - 1] == 0 && fibo[sz - 2] == 1) {
                cout << N << ' ' << sz - 1 << '\n';
                break;
            }

            fibo[sz] = (fibo[sz - 1] + fibo[sz - 2]) % M;
            sz++;
        }
    }
    return 0;
}
