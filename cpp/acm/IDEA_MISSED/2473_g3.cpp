#include <iostream>
#include <algorithm>

using namespace std;
using ll=long long;


int N;
int filled[3];

ll arr[5000];

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;
  for(int i=0;i<N;i++){
    cin>>arr[i];
  }
  sort(arr,arr+N);

  ll ans = 3333333333;
  for (int i = 0; i < N-2; i++){
    int l = i+1, r= N-1;
    while (l<r) {
      ll _sum = arr[i] + arr[l] + arr[r];
      if (abs(_sum) < ans) {
        ans = abs(_sum);
        filled[0] = i;
        filled[1] = l;
        filled[2] = r;
      }
      if (_sum < 0) l++;
      else r--;
    }
  }

  for (int i =0;i<3;i++) cout << arr[filled[i]] << ' ';
  cout<<'\n';
  return 0;
}