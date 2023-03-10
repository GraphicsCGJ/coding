// 5926 https://www.acmicpc.net/problem/5926
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
using P1=pair<int,int>;

int N;
P1 arr[50000];
map<int,vector<int>> mp;

bool cmp(P1& a, P1& b) {
  return a.first < b.first;
}

bool isPossible(int src, int dst, int cvt) {
  int lpos = arr[src].first;
  int rpos = arr[dst].first;
  if (lpos > rpos) swap(lpos, rpos);
  if (cvt == 1) {
    auto& v = mp.find(arr[src].second)->second;
    auto iter = lower_bound(v.begin(), v.end(), lpos);
    auto iter_nxt = iter+1;
    if (iter_nxt != v.end() && *iter_nxt <= rpos) return true;
  }
  else {
    auto& v = mp.find(arr[dst].second)->second;
    auto iter = lower_bound(v.begin(), v.end(), rpos);
    if (iter == v.begin()) return false;
    auto iter_nxt = --iter;
    if (*iter_nxt >= lpos) return true;
  }
  return false;
}

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;

  for(int i=0;i<N;i++){
    cin>>arr[i].first >> arr[i].second;
    if (mp.find(arr[i].second) != mp.end())
      mp.at(arr[i].second).emplace_back(arr[i].first);
    else
      mp.emplace(arr[i].second, vector<int>{arr[i].first});
  }

  for (auto& p : mp) {
    auto& v = p.second;
    sort(v.begin(), v.end());
  }

  sort(arr, arr+N, cmp);

  int l = 0; int r = N-1;
  while (isPossible(l,r,1)) l++;
  while (isPossible(l,r,-1)) r--;
  cout << arr[r].first - arr[l].first << '\n';


  return 0;
}