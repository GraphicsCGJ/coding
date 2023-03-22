#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int G,P;
int root[100001];

int find_root(int i) {
  if (root[i] == i) {
    root[i] -= 1;
    return root[i];
  }
  return root[i] = find_root(root[i]);
}

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> G >> P;
  for (int i = 0; i <= G; i++) root[i] = i;

  int i;
  for (i = 0; i < P; i++) {
    int tmp; cin >> tmp;
    int rt = find_root(tmp);
    if (rt == -1) break;
  }

  cout << i << '\n';

  return 0;
}