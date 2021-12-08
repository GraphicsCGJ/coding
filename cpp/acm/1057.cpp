#include <iostream>

using namespace std;

int n;
int a, b;


int main(void) {
    cin >> n >> a >> b;
    if (a > b) {
        int tmp = b;
        b = a;
        a = tmp;
    }

    int cnt = 1;
    while (!(b - a == 1 && a % 2 == 1)) {
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        cnt++;

        if (a == b) {
            cnt = -1;
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}