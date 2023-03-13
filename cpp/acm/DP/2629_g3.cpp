#include <iostream>
#include <cmath>

using namespace std;
int N;
int arr[30];
int M;
int arr2[7];
bool dp[31][40001];

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  dp[0][0] = true;
  int mx = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    mx += arr[i];
  }
  cin >> M;
  for (int i = 0; i < M; i++) cin >> arr2[i];

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= mx; j++) {
      dp[i][j] = dp[i-1][j];

      if (j >= arr[i-1]) {
        if (dp[i-1][j-arr[i-1]] == true)
          dp[i][j] = true;
        if (dp[i-1][j] == true)
          dp[i][j-arr[i-1]] = true;
      }
      else if (j - arr[i-1] < 0 && dp[i-1][arr[i-1]-j] == true)
        dp[i][j] = true;
    }
  }
  for (int i = 0; i < M; i++)
    cout << (dp[N][arr2[i]] == true ? "Y " : "N ");
  cout << '\n';
  return 0;
}
