#include <iostream>

using namespace std;

int dp[101][100001];

class c1 {
    public:
        int price;
        int weight;
};

int N, K;

int main(void) {
    cin >> N >> K;

    /* init */
    c1 *stuffs = new c1[N];

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        cin >> stuffs[i].weight >> stuffs[i].price;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= stuffs[i - 1].weight) {
                int priceSumLocal = stuffs[i - 1].price + dp[i - 1][j - stuffs[i - 1].weight];
                if (priceSumLocal > dp[i][j])
                    dp[i][j] = priceSumLocal;
            }
        }
    }

    cout << dp[N][K] << endl;


    return 0;
}