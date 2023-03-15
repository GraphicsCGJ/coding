#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int dp[101][101][101];

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  string a, b, c;
  cin >> a >> b >> c;
  for (int i = 1; i <= a.length(); i++) {
    for (int j = 1; j <= b.length(); j++) {
      for (int k = 1; k <= c.length(); k++) {
        dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);

        if (a[i-1] == b[j-1] && a[i-1] == c[k-1])
          dp[i][j][k] = dp[i][j][k] < dp[i-1][j-1][k-1] + 1 ? dp[i-1][j-1][k-1] + 1 : dp[i][j][k];
      }
    }
  }

  cout << dp[a.length()][b.length()][c.length()] << '\n';

  return 0;
}