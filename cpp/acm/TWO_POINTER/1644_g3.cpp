#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

int N;

inline bool isSosu(int val) {
  if (val < 2) return false;
  else if (val == 2) return true;
  else if (val % 2 == 0) return false;

  for (int i = 3; i< (int)sqrt(val) + 1; i+=2)
    if (val % i == 0) return false;

  return true;
}

int main(void) {
cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;

  int cnt = 0;

  deque<int> dq;
  int sum = 2;
  dq.push_back(2);

  while (sum > N) {
    sum -= dq.front();
    dq.pop_front();
  }

  if (sum == N) {
    cnt++;
  }

  for (int i = 3; i <=N; i+=2) {
    if (!isSosu(i)) continue;
    dq.push_back(i);
    sum += i;

    while (sum > N) {
      sum -= dq.front();
      dq.pop_front();
    }

    if (sum == N) {
      cnt++;
    }
  }

  cout << cnt  << '\n';
  return 0;
}