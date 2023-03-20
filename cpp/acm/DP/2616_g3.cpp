#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int,int> P1;

int N, R;
int arr[50000];
P1 dp[4][50001];

inline int getRange(int l, int r) {
  int sum = 0;
  for (int i = l; i <= r; i++) sum += arr[i-1];
  return sum;
}

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  cin >> R;

  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= N; j++) {
      if (j - R >= 0 && dp[i-1][j-R].first <= j-R) {
        auto pre = dp[i-1][j-R];
        P1 current(j, pre.second + getRange(j-R+1, j));

        dp[i][j] = dp[i][j-1];
        if (current.second > dp[i][j-1].second)
          dp[i][j] = current;

      }
    }
  }

  cout << dp[3][N].second << '\n';
  return 0;
}