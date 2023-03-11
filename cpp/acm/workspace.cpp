#include <iostream>
#include <map>

using namespace std;

int N;
int T;

int parent[200001];
int member_cnt[200001];
map<string,int> mp;

int find_root(int a) {
  if (a == parent[a]) return a;
  return parent[a] = find_root(parent[a]);
}

void union_root(int a, int b) {
  int x = find_root(a);
  int y = find_root(b);
  if (x != y) {
    parent[x] = y;
    member_cnt[y] = member_cnt[x] + member_cnt[y];
  }
  cout <<member_cnt[y]<<'\n';
}

void sol() {
  cin >> N;

  int cnt = 0;
  mp.clear();
  fill(member_cnt, member_cnt + 2*N, 1);

  for (int i = 0; i < 2*N; i++) parent[i] = i;
  for (int i = 0; i < N; i++) {
    string a, b;
    cin >> a >> b;

    if (mp.find(a) == mp.end())
      mp.emplace(a,cnt++);
    if (mp.find(b) == mp.end())
      mp.emplace(b,cnt++);
    union_root(mp.at(a),mp.at(b));
  }
}

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> T;
  while (T--)
    sol();


  return 0;
}
