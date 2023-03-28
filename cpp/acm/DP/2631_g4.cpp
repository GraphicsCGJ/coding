#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[200];
int dp[201];


int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;
  for(int i=0;i<N;i++) cin>>arr[i];

  for (int i = 0; i<N; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if(arr[j] < arr[i]){
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  int MX = 0;
  for (int i = 0; i< N; i++) {
    MX = max(MX, dp[i]);
  }
  cout << N - MX << '\n';

  return 0;
}