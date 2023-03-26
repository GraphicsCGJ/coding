#include <iostream>
#include <algorithm>

using namespace std;

int N, T;
int cards[1000];
int dp[1000][1000];
int choice[1000][1000];

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> T;

  while (T--) {
    cin>> N;
    for(int i=0;i<N;i++) cin>>cards[i];

    // set init.
    for (int i = 0; i < N; i++) {
      dp[i][i] = cards[i];
      choice[i][i] = i;
      if (i > 0) {
        if (cards[i-1] > cards[i]) {
          dp[i-1][i] = cards[i-1];
          choice[i-1][i] = i-1;
        }
        else {
          dp[i-1][i] = cards[i];
          choice[i-1][i] = i;
        }
      }
    }

    for (int gap = 2; gap <= N-1; gap++) {
      for (int l = 0, r=gap; r < N; l++,r++) {
        // choice left.
        choice[l][r] = l;
        if (choice[l+1][r] == l+1) {
          dp[l][r] = cards[l] + dp[l+2][r];
        }
        else {
          dp[l][r] = cards[l] + dp[l+1][r-1];
        }

        // choice right
        int tmp = 0;
        if (choice[l][r-1] == l) {
          tmp = cards[r] + dp[l+1][r-1];
        }
        else {
          tmp = cards[r] + dp[l][r-2];
        }

        if (tmp > dp[l][r]) {
          choice[l][r] = r;
          dp[l][r] = tmp;
        }
      }
    }

    cout << dp[0][N-1] << '\n';
  }



  return 0;
}