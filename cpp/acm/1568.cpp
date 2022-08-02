#include <iostream>

using namespace std;

int N;

int main(void) {
    cin >> N;
    int k = 1;
    int cnt = 0;

    while (N > 0) {
        if (N < k)
            k = 1;

        N -= k;
        k ++;
        cnt ++;
    }

    cout << cnt << endl;

    return 0;
}