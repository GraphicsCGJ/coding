#include <iostream>
#include <algorithm>

using namespace std;

int N;

int dp[500][500];
int f[500], e[500];

int sol(int l, int r) {
  if (l != r && dp[l][r] == 0) {
    for (int i = l; i < r; i++) {
      int cur = f[l] * e[r] * e[i];
      int dpval = sol(l,i) + sol(i+1,r);

      dp[l][r] = dp[l][r] == 0 ? dpval + cur : dp[l][r] > dpval + cur ? dpval + cur : dp[l][r];
    }
  }
  return dp[l][r];
}

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;

  for(int i=0;i<N;i++) {
    cin>>f[i]>>e[i];
  }

  cout<< sol(0,N-1) << '\n';
  return 0;
}