#include <iostream>

using namespace std;

int N;
int L;
int main(void) {
    cin >> N >> L;

    bool flag = false;
    for (int i = L; i <= 100 && !flag ; i++) {
        int tmp = N - (i * (i - 1) / 2);
        // cout << tmp << endl;
        if (tmp % i == 0 && tmp >= 0) {
            tmp /= i;
            for (int j = 0; j < i; j++) {
                cout << tmp + j << " ";
            }
            cout << endl;
            flag = true;
        }
    }

    if (!flag) {
        cout << -1 << endl;
    }


    return 0;
}