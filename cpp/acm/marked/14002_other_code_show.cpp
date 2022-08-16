#include <iostream>
#include <vector>

using namespace std;

class c1 {
    public:
        int length;
        vector<int> list;
};

int N;
int M;
int arr[1001];
c1 dp[1001][1001];
// i = 몇번째꺼가지 쓸껀가
// j = 이 값까지 증가를 허용시킬 때, 현재 수열 길이
// i, j = i번째의 사용을 허용하고, j값까지의 증가를 허용시킬 때의 수열 길이.

// void dp();
int main(void) {
    cin >> N;

    /* input */
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] > M)
            M = arr[i];
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (i == 0 || j == 0) {
                dp[i][j].length = 0;
            }
            else {
                // 나를 아예 안쓴 길이
                dp[i][j] = dp[i - 1][j]; // 한 개 덜 쓴놈의 수열 길이.

                // 나를 포함한 길이
                if (j >= arr[i - 1]) {
                    c1 tmp;
                    tmp.length = dp[i - 1][arr[i - 1] - 1].length + 1;
                    tmp.list = dp[i - 1][arr[i - 1] - 1].list;
                    tmp.list.push_back(i - 1);

                    if (tmp.length > dp[i][j].length)
                        dp[i][j] = tmp;
                }
            }
        }
    }

    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j <= M; j++) {
    //         cout << dp[i][j].length << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[N][M].length << endl;
    for (int i = 0; i < dp[N][M].list.size(); i++) {
        cout <<  arr[dp[N][M].list[i]] << " ";
    }
    cout << endl;


    return 0;
}

