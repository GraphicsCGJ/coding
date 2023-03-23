#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int N;
vector<deque<int>> dv;

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {

    int tmp;
    cin >> tmp;

    if (dv.size()==0) {
      deque<int> dq;
      dq.emplace_back(tmp);
    }
    else {
      // 1. find
      bool found = false;
      for (auto& dq : dv) {
        if (tmp < dq.front()) {
          found = true;

        }
      }
    }
  }
  return 0;
}