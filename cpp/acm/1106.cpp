#include <iostream>

using namespace std;
int N, C;

typedef struct {
    int cost;
    int people;
} knap;

knap arr[21];

int dp[21][1101];

int main(void) {
    cin >> C >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].cost >> arr[i].people;
    }

    int mincost =50000000 ;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= 1101; j++) {
            if (i == 0)
                dp[i][j] = 50000000;
            else {
                dp[i][j] = dp[i - 1][j];
                if (j >= arr[i].people) {
                    for (int ii = 1; ii * arr[i].people <= j; ii++) {
                        int localPrice = dp[i - 1][j - arr[i].people * ii] + arr[i].cost * ii;
                        if (localPrice < dp[i][j])
                            dp[i][j] = localPrice;
                    }
                }

                if (j >= C && mincost > dp[i][j])
                    mincost = dp[i][j];
            }
        }
    }
    cout << mincost << endl;




    return 0;
}