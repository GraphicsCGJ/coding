#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int N, M;

int dp[1001][100001];

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> M;
  vector<P1> v1;
  for(int i = 0;i<N;i++) {
    P1 p;
    cin >> p.first;
    p.second = -1;
    v1.push_back(p);
  }
  for(int i = 0;i<N;i++)
    cin >> v1[i].second;

  mp.emplace(0,0);

  vector<P1> v2;
  for (int i = 0; i < N; i++) {

  }
}