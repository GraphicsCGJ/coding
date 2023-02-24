#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int N;

class C1 {
public:
  int x1, x2, y1, y2;
  int parent;
  C1() = default;
};

C1 arr[1000];
bool visited[1000];

int find_root(int x) {
  visited[x] = true;
  if (arr[x].parent == x)
    return x;
  return find_root(arr[x].parent);
}

int cp_root(int src, int dst) {
  if (arr[src].parent == src) {
    arr[src].parent = dst;
    return dst;
  }
  return (arr[src].parent = cp_root(arr[src].parent, dst));
}

bool isSameGroup(C1& a, C1& b) {
  if (((a.x1 > b.x2) || (a.x2 < b.x1) || (a.y1 > b.y2) || (a.y2 < b.y1)) ||
      ((a.x1 > b.x1 && a.y1 > b.y1 && a.x2 < b.x2 && a.y2 < b.y2) ||
      (b.x1 > a.x1 && b.y1 > a.y1 && b.x2 < a.x2 && b.y2 < a.y2)))
    return false;
  return true;
}

int main(void) {
  bool flg = false;

  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;

  for (int i = 0; i <N; i++) {
    cin >> arr[i].x1 >> arr[i].y1 >> arr[i].x2 >> arr[i].y2;
    arr[i].parent = i;

    if (arr[i].x1 == 0 && arr[i].y1 <= 0 && arr[i].y2 >= 0)
      flg = true;
    else if (arr[i].x2 == 0 && arr[i].y1 <= 0 && arr[i].y2 >= 0)
      flg = true;
    else if (arr[i].y1 == 0 && arr[i].x1 <= 0 && arr[i].x2 >= 0)
      flg = true;
    else if (arr[i].y2 == 0 && arr[i].x1 <= 0 && arr[i].x2 >= 0)
      flg = true;
  }

  for (int i = 1; i <N; i++) {
    for (int j = i-1; j >= 0; j--) {
      if (isSameGroup(arr[i], arr[j])) {
        cp_root(j, i);
      }
    }
  }
  set<int> st;

  for (int i = 0; i < N; i++) {
    if (visited[i] == false) {
      int res = find_root(i);
      st.emplace(res);
    }
  }

  cout << st.size() - (flg ? 1 : 0) << '\n';

  return 0;
}