#include <iostream>
#include <algorithm>
using namespace std;
using P1 = pair<int,int>;

int N;
P1 arr[1000];

bool cmp(P1& a, P1& b) {
  return a.second > b.second;
}

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;
  for(int i = 0;i<N;i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  sort(arr, arr + N, cmp);

  int cur = arr[0].second;
  for (int i = 0; i < N; i++) {
    auto& p = arr[i];
    cur = p.second >= cur ? cur - p.first : p.second - p.first;
  }


  cout << (cur < 0 ? -1 : cur) << '\n';



  return 0;
}
