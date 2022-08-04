#include <iostream>

using namespace std;
int N, C;

typedef struct {
    int cost;
    int people;
} knap;

knap arr[21];

int dp[21][2000];

int main(void) {
    cin >> C >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].cost >> arr[i].people;
    }

    int mincost = 50000000;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= 2000; j++) {
            if (i == 0)
                dp[i][j] = 0;
            else {
                if (j >= arr[i].cost) {
                    int local_max = dp[i - 1][j];
                    for (int idx = 1; j >= arr[i].cost * idx; idx++) {
                        int local_max2 = dp[i - 1][j - arr[i].cost * idx] + arr[i].people * idx;
                        if (local_max < local_max2) local_max = local_max2;
                    }
                    dp[i][j] = local_max;
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
                if (dp[i][j] >= C) {
                    if (mincost > j) {
                        mincost = j;
                    }
                }
            }
        }
    }

    // // cout << dp[N][C] << endl;
    // for (int i = 0; i <= N; i ++) {
    //     for (int j = 0; j <= C; j++) {
    //         cout << j<<":"<<dp[i][j] << "  ";
    //     }
    //     cout << endl;
    // }
    cout << mincost << endl;


    return 0;
}