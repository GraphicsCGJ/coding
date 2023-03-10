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

bool func(int l, int r, int type) {
  int lpos = arr[l].first;
  int rpos = arr[r].first;
  int l_species = arr[l].second;
  int r_species = arr[r].second;

  if (l>=r) return false;

  if (type == 1) {
    auto& v = mp.find(l_species)->second;
    int idx = lower_bound(v.begin(), v.end(), lpos) - v.begin();
    if (idx < v.size() - 1) {
      int nxt = idx+1;
      if (v[nxt] <= rpos) return true;
    }
  }
  else {
    auto& v = mp.find(r_species)->second;
    int idx = lower_bound(v.begin(), v.end(), rpos) - v.begin();
    if (idx > 0) {
      int nxt = idx-1;
      if (v[nxt] >= lpos) return true;
    }
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
  while (func(l,r,1)) l++;
  while (func(l,r,-1)) r--;
  int mx = arr[r].first - arr[l].first;

  l = 0; r = N-1;
  while (func(l,r,-1)) r--;
  while (func(l,r,1)) l++;

  if (mx > arr[r].first - arr[l].first) mx = arr[r].first - arr[l].first;

  cout << mx << '\n';

  return 0;
}
