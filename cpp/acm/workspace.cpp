#include <iostream>
#include <algorithm>

using namespace std;
using P1=pair<int,int>;

int N, K;
int arr[100000];
int dif[100000];

bool cmp(P1& a, P1& b) {
  return a.first<b.first;
}

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> K;
  int ans=0;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    // cout << arr[i] << '\n';
    if (i!=0) {
      dif[i-1] = arr[i]-arr[i-1];
      ans += dif[i-1];
    }
  }

  sort(dif,dif + N-1,greater<int>());

  for (int i = 0; i < K-1; i++)
    ans-=(dif[i]-1);

  cout << ans +1<< '\n';


  return 0;
}