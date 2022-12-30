#include <iostream>

using namespace std;
int N;
int R;

int main(void) {
    cin >> N;
    cin >> R;
    for (int i = 0; i < N - 1; i++) {
        int tmp;
        cin >> tmp;

        int a = R, b = tmp;
        int min = (a < b) ? a : b;

        while (min > 1) {
            if (a % min == 0 && b % min == 0) {
                a /= min;
                b /= min;

                min = (a < b) ? a : b;
                continue;
            }

            min --;
        }

        cout << a << "/" << b << endl;


    }

    return 0;
}