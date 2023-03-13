#include <iostream>
#include <vector>

using namespace std;
int N;

struct Node_t{
  vector<int> nodes;
};


vector<int> nodes[1000001];
bool visited[1000001];

int ans = 0;

bool dfs(int idx) {
  bool ret = true;
  visited[idx] = true;
  for (auto i : nodes[idx]) {
    if (visited[i]) continue;
    ret &= dfs(i);
  }
  if (ret == false)
    ans ++;
  return !ret;
}

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  Node_t root;

  cin >> N;
  for (int i = 0; i < N-1; i++) {
    int idx, child;
    cin >> idx >> child;
    nodes[idx].push_back(child);
    nodes[child].push_back(idx);
  }

  dfs(1);
  cout << ans << '\n';

  return 0;
}
