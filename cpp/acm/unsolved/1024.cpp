#include <iostream>

using namespace std;

int N;
int L;
int main(void) {
    cin >> N >> L;

<<<<<<< HEAD
    for (int i = L; i <= 100; i++) {
        int val = N / L;
        if ()
=======
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
>>>>>>> 9466cdf57a3215fff183f36fe7a8042ab207a806
    }


    return 0;
}