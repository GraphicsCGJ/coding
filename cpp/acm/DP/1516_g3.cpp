#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using P1=pair<int,int>;
int N;

bool complete[500];
int complete_t[500];
int time[500];
priority_queue<P1> pq;
vector<int> vec[500];
vector<int> vec2[500];

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> time[i];
    while(true) {
      int tmp; cin >> tmp;
      if (tmp == -1) break;
      tmp--;
      vec[i].push_back(tmp);
      vec2[tmp].push_back(i);
    }

    if (vec[i].size() == 0) {
      pq.emplace(-time[i], i);
    }
  }

  while (!pq.empty()) {
    P1 p = pq.top(); p.first = -p.first;
    pq.pop();
    complete[p.second] = true;

    // time
    int _complete_t = 0;
    for (auto& v : vec[p.second])
      max(_complete_t, complete_t[v]);
    complete_t[p.second] = _complete_t + p.first;

    // find nxt
    for (auto& v : vec2[p.second]) {
      bool check = true;

      for (auto& v2 : vec[v]) {
        check &= complete[v2];
      }

      if (check) pq.emplace(-(time[v] + complete_t[p.second]), v);
    }
  }

  for (int i = 0; i < N; i++) {
    cout << complete_t[i] << '\n';
  }

  return 0;
}
