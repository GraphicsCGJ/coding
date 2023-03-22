#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
double arr[100000];

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cout << fixed;
  cout.precision(8);

  cin >> N;
  double sum = 0.0;
  for (int i = 0;i<N;i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  sort(arr, arr + N);

  if (N == 1) {
    cout << arr[0] << '\n';
  }
  else if (N == 2) {
    cout << (arr[0] + arr[1]) / 2 << '\n';
  }
  else {
    double ans = sum / N;
    cout << (ans < arr[N-2] ? arr[N-2] : ans) << '\n';
  }

  return 0;
}