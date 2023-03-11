#include <iostream>
#include <queue>
// https://www.acmicpc.net/problem/19940
using namespace std;

int T;
int arr[61][5];
int btn[5] = {60, 10, -10, 1, -1};
bool visited[61];

class state {
public:
  int value;
  int arr[5];
};

void bfs_arr_fill() {
  queue<state> q;
  state s;

  s.value = 0;
  fill(s.arr, s.arr + 5, 0);
  q.push(s);

  visited[0] = true;
  while (!q.empty()) {
    s = q.front();
    q.pop();
    copy(s.arr, s.arr + 5, arr[s.value]);

    for (int i = 5; i >= 0; i--) {
      int nxt = (s.value + btn[i]);
      if (nxt > 60 || nxt < 0) continue;
      if (visited[nxt]) continue;
      visited[nxt] = true;

      state nxt_s;
      nxt_s.value = nxt;
      copy(s.arr, s.arr + 5, nxt_s.arr);
      nxt_s.arr[i]++;
      q.push(nxt_s);
    }
  }
}

void sol() {
  int tgt;
  cin >> tgt;
  int cnt = 0;
  if (tgt > 60) {
    cnt = tgt / 60;
    tgt = tgt % 60;
  }

  int ans[5];
  copy(arr[tgt], arr[tgt] + 5, ans);
  ans[0] += cnt;

  for (int i = 0; i < 5; i++)
    cout << ans[i] << ' ';
  cout << '\n';
}

int main(void) {

  cin.tie(0);
  ios_base::sync_with_stdio(0);

  bfs_arr_fill();
  cin >> T;

  while (T--) {
    sol();
  }


  return 0;
}