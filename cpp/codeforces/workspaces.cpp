#include <iostream>

using namespace std;

int N;

int main(void) {

    cin >> N;
    int cnt = 0;
    while(N--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c >= 2)
            cnt++;
    }

    cout << cnt << '\n';

    return 0;
}