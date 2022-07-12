#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int maxVal;

int *dp;

int main(void) {
    cin >> T;

    vector<int> vecN;
    maxVal = -1;
    while (T--) {
        int n;
        cin >> n;
        vecN.push_back(n);
        if (maxVal < n) maxVal = n;
    }

    dp = (int*) malloc(sizeof(int) * (maxVal + 1));

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= maxVal; i++) {
        dp[i] = (((dp[i-1] + dp[i-2]) % 1000000009) + dp[i-3]) % 1000000009;
    }

    for (int vi : vecN) {
        cout << dp[vi] << endl;
    }

    return 0;
}