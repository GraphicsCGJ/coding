#include <iostream>

using namespace std;


int N;

int arr[1000];
int dp[1000];

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int maxVal = 0;
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j <= i; j++) {
            if (arr[j] > arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
            if (maxVal < dp[i])
                maxVal = dp[i];
        }
    }

    cout << maxVal << endl;

    return 0;
}