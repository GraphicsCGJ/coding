#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> P1;
#define MX 1000000010

int N, M;
int S, E;
map<int,int> eg[100000];
bool visited[100000];
int dst[100000];
priority_queue<P1> pq;

void map_ins(map<int,int>& mp_in, int idx, int val) {
  auto iter = mp_in.find(idx);
  if (iter == mp_in.end()) {
    mp_in.emplace(idx, val);
  }
  else {
    if (iter->second < val)
      iter->second = val;
  }
}

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;a--;b--;

    map_ins(eg[a], b, c);
    map_ins(eg[b], a, c);
  }

  cin >> S >> E; S--;E--;

  fill(dst, dst+N, MX);
  // dijkstra
  dst[S] = 0;
  pq.emplace(MX, S);

  while (!pq.empty()) {
    P1 cur = pq.top();
    pq.pop();

    if (visited[cur.second]) continue;
    visited[cur.second] = true;
    // cout << cur.second << ' ' << cur.first << '\n';
    int pre = -1;
    for (auto v : eg[cur.second]) {
      if (dst[v.first] == MX) {
        dst[v.first] = min(cur.first, v.second);
      }
      else {
        dst[v.first] = max(min(cur.first, v.second), dst[v.first]);
      }
      pq.emplace(dst[v.first], v.first);
    }

    // cout << "dst\n";
    // for (int i = 0; i < N; i++)
    //   cout << "[" << i << ":" << dst[i] << "] ";
    // cout << '\n';
  }

  cout << dst[E] << '\n';

  return 0;
}