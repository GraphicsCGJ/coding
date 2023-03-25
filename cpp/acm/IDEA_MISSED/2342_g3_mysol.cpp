// 풀긴 풀었는데, DP로 더 멋있게 푸는 방법이 있다.
// 나는 사실상 BF로 푼거고, n번째를 왼발로 밟을때 최소값과 오른발로 밟을 때 최소값을 갱신하면서 가면 된다.ㄷ

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
typedef pair<int,int> P1;

int N, K;

map<P1,int> dp[100001];

P1 make_p1(int a, int b) {
  if (a > b) swap (a,b);
  return P1(a,b);
}

int calc(int src, int dst) {
  if (src == dst) return 1;
  else if (src == 0) return 2;
  else {
    int tmp = src - dst;
    if (tmp < 0) tmp = -tmp;
    if (tmp == 2) return 4;
    else return 3;
  }
}

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int idx = 0;
  dp[idx++].emplace(P1(0,0), 0);

  while (true) {
    int tmp;
    cin >> tmp;

    if (tmp == 0) break;

    auto& pre = dp[idx-1];

    for (auto& mi : pre) {
      int val = calc(mi.first.first, tmp) + mi.second;

      P1 tmpP1 = make_p1(tmp, mi.first.second);
      if (dp[idx].find(tmpP1) != dp[idx].end()) {
        if (dp[idx].find(tmpP1)->second > val) {
          dp[idx].find(tmpP1)->second = val;
        }
      }
      else dp[idx].emplace(tmpP1, val);

      val = calc(mi.first.second, tmp) + mi.second;
      tmpP1 = make_p1(mi.first.first, tmp);

      if (dp[idx].find(tmpP1) != dp[idx].end()) {
        if (dp[idx].find(tmpP1)->second > val) {
          dp[idx].find(tmpP1)->second = val;
        }
      }
      else dp[idx].emplace(tmpP1, val);
    }
    idx++;
  }
  int minVal = 999999999;
  idx -= 1;
  for (auto& mi : dp[idx]) {
    if (minVal > mi.second)
      minVal = mi.second;
    // cout << "(" << mi.first.first <<"," <<mi.first.second<<") " <<mi.second << '\n';
  }
  cout << minVal << '\n';

  return 0;
}