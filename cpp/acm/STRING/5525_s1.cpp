#include <iostream>

using namespace std;

int N, M;

int main(void) {

    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    int result = 0;
    int cnt = -1;
    char exchar = 0x00;

    for (int i = 0; i < M; i++) {
        char c;
        cin >> c;

        if (c == 'I') {
            if (exchar == 0x00 || exchar == 'I') {
                exchar = c;
                cnt = 0;
            }
            else { // exchar = O
                exchar = c;
                cnt ++;

                if (cnt == N) {
                    cnt --;
                    result ++;
                }
            }
        }
        else { // c = O
            if (exchar == 0x00 || exchar == 'O') {
                exchar = 0x00;
                cnt = -1;
            }
            if (exchar == 'I') {
                exchar = c;
            }
        }
    }
    cout << result << endl;
}