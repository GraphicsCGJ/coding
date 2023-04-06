#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int N;


void recur(int r, int c, int n) {
  if ((r / n) % 3 == 1 && (c/n)%3 == 1)
    cout << ' ';
  else {
    if(n / 3 == 0)
      cout <<'*';
    else
      recur(r,c,n/3);
  }
}


int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);


  cin >> N;
  return 0;
}