#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int dp[50001] = {0, };
int N;

int main(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        double sqrtValue = sqrt((double)i);
        double sqrtValue2 = (double)((int)sqrtValue);
        if (sqrtValue == sqrtValue2)
            dp[i] = 1;
        else {
            int globalMin = 5;
            for (int j = 1; (i - (j * j) >= 1); j++) {
                int localMin = dp[i - (j * j)] + 1;
                if (globalMin > localMin)
                    globalMin = localMin;
            }

            dp[i] = globalMin;
        }
    }

        cout << dp[N] << endl;

    return 0;
}