#include <iostream>
#include <algorithm>

using namespace std;

int N, T;

int arr[500];
int dp[500][500];
int sum[500];

void calc(int l, int r) {
  if (dp[l][r]>0) return;

  if (l == r) dp[l][r] = 0;
  else {
    for (int i = l; i <r ; i++) {
      calc(l,i);
      calc(i+1,r);
      int tmp = sum[r] - sum[l] + arr[l];
      tmp += (dp[l][i]+dp[i+1][r]);
      dp[l][r] = dp[l][r] == 0 ? tmp : min(dp[l][r],tmp);
    }
  }
}


void sol(){
  cin >> N;

  for(int i=0;i<N;i++) {
    cin>>arr[i];

    sum[i] = i==0? arr[i] : sum[i-1] + arr[i];
  }

  fill(&dp[0][0],&dp[499][500],0);

  calc(0, N-1);
  cout << dp[0][N-1] << '\n';
}

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> T;

  while(T--){
    sol();
  }

  return 0;
}