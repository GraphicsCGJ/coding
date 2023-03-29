// Idea Missed.

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1000001];


int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;
  int mx = -1;
  for(int i=0;i<N;i++) {
    int tmp;
    cin >> tmp;
    arr[tmp] = arr[tmp-1] + 1;
    mx = max(mx,arr[tmp]);
  }

  cout << N - mx << '\n';

  return 0;
}