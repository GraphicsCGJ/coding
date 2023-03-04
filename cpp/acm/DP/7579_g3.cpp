#include <iostream>
#include <algorithm>
using namespace std;
using P1=pair<int,int>;

int N, M;

P1 arr[100];
int dp[101][10001];


int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> M;
  for(int i = 0;i<N;i++)
    cin >> arr[i].first;
  for(int i = 0;i<N;i++)
    cin >> arr[i].second;

  int ans = 2000000000;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= 10000; j++) {
      P1 p = arr[i-1];
      if (j >= p.second)
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-p.second] + p.first);
      else dp[i][j] = dp[i-1][j];

      if (dp[i][j] >= M) ans = min(ans, j);
    }
  }
  // for (int i = 0; i <= N; i++) {
  //   for (int j = 0; j < 20; j++) {
  //     cout << dp[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  cout << ans << '\n';

  return 0;
}