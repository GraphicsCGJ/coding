#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

#define MX 20000000

using namespace std;

using P1=pair<int,int>;

int N, M;

int ans[200][200];
int cost[200][200];

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> M;

  fill(&cost[0][0],&cost[N-1][N], MX);
  fill(&ans[0][0],&ans[N-1][N], -1);
  // for (int i=0;i<N;i++) ans[i][i] = i;

  for (int i = 0; i < M;i++) {
    int a, b, c;
    cin >> a>>b>>c; a--;b--;

    cost[a][b] = c;
    cost[b][a] = c;
    ans[a][b] = b+1;
    ans[b][a] = a+1;
  }

  for (int k=0;k<N;k++) {
    for (int i=0;i<N;i++) {
      for (int j=0;j<N;j++) {
        if (cost[i][j] > cost[i][k] + cost[k][j]) {
          cost[i][j] = cost[i][k] + cost[k][j];
          ans[i][j] = ans[i][k];
        }
      }
    }
  }

  for (int i=0;i<N;i++) {
    for (int j=0;j<N;j++) {
      if (i == j) cout << '-' << ' ';
      else
        cout << ans[i][j] << ' ';
    }cout << '\n';
  }

  return 0;
}