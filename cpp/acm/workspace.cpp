#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int> pq;

int main(void) {

  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    pq.push(-tmp);
  }

  int cnt = 0;
  long long ans = 0;
  while (!pq.empty()) {
    int tp = -pq.top();
    tp -= cnt;
    if (tp <= 0) {
      pq.pop();
      continue;
    }
    else {
      cnt += 1;
      tp -= 1;
      if (tp > 0)
        ans += tp;
      pq.pop();
    }
  }

  cout << ans << '\n';

  return 0;
}
