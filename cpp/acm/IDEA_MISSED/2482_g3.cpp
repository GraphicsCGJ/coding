#include <iostream>
#include <algorithm>

using namespace std;
int N, K;
int dp[1001][1001];
int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> K;
  for (int i = 0; i <= N; i++) {
    dp[i][0] = 1; dp[i][1] = i;
  }

  for (int i = 1; i <= N; i++) {
    for (int k = 2; k<=i; k++) {
      dp[i][k] = (dp[i-1][k] + dp[i-2][k-1]) % 1000000003;
    }
  }

  cout << (dp[N-3][K-1] + dp[N-1][K]) % 1000000003 << '\n';

  return 0;
}