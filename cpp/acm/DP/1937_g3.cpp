#include <iostream>
#include <algorithm>

using namespace std;
using ll=long long;


int N;


ll field[500][500];
ll dp[500][500];
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};
ll MX = 0;

ll dfs(int r, int c) {
  if (dp[r][c] > 0) return dp[r][c];

  dp[r][c] = 1;
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];

    if (nr >= N || nr < 0 || nc >= N || nc < 0 ||
        field[r][c] <= field[nr][nc])
      continue;
    dp[r][c] = max(dp[r][c], dfs(nr,nc) + 1);
  }

  return dp[r][c];
}

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>field[i][j];
    }
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      ll LMX = dfs(i,j);
      MX = max(MX,LMX);
    }
  }

  cout << MX << '\n';

  return 0;
}