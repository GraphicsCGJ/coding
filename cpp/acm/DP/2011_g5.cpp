// Idea Missed.

#include <iostream>
#include <algorithm>

using namespace std;

string s;
int dp[5001];

int make_num(int idx) {
  int tmp = 0;
  tmp += (s[idx] - '0') * 10;
  tmp += (s[idx+1] - '0');
  return tmp;
}

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    if (i == 0) {
      if (s[i] == '0') {
        cout << 0<<'\n';
        return 0;
      }
      dp[i] = 1;
    }
    else if (i == 1) {
      if (s[i] == '0') {
        if (s[i-1] >='3' || s[i-1] == '0') {
          cout << 0<<'\n';
          return 0;
        }
        dp[i] = 1;
        continue;
      }
      dp[i] = 1;
      if (make_num(i-1) > 0 && make_num(i-1) <= 26) {
        dp[i] += 1;
      }
    }
    else {
      if (s[i] == '0') {
        if (s[i-1] >='3' || s[i-1] == '0') {
          cout << 0<<'\n';
          return 0;
        }
        dp[i] = dp[i-2];
        continue;
      }

      dp[i] = dp[i-1];
      if (make_num(i-1) >= 10 && make_num(i-1) <= 26) {
        dp[i] += dp[i-2];
        dp[i] %= 1000000;
      }
    }
  }

  cout << dp[s.length() -1] % 1000000 << '\n';

  return 0;
}