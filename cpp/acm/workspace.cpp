#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;


// int find_root(int x) {
//     if (x == parent[x]) return x;

//     // path compression.
//     // all node in same tree have the same parent
//     return parent[x] = find_root(parent[x]);
// }



// /* Union Function */
// void union_root(int x, int y) {
//     x = find_root(x);
//     y = find_root(y);

//     if (x!=y) {
//         parent[x] = y;
//     }
// }

class C1 {
public:
  int x1, x2, y1, y2;
  int parent;

  bool cmp(C1& tgt) {
    if (tgt.x1 >= x1 && tgt.x1 <= x2 && ((tgt.y1 >= y1 && tgt.y1 <= y2) || (tgt.y2 >= y1 && tgt.y2 <= y2)))
      return true;
    else if (tgt.x2 >= x1 && tgt.x2 <= x2 && ((tgt.y1 >= y1 && tgt.y1 <= y2) || (tgt.y2 >= y1 && tgt.y2 <= y2)))
      return true;
    else
      return false;
  }

};

C1 arr[1000];

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;

  for (int i = 0; i <N; i++) {
    cin >> arr[i].x1 >> arr[i].y1 >> arr[i].x2 >> arr[i].y2;
    arr[i].parent = i;
  }



  return 0;
}