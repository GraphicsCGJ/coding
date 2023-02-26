#include <iostream>
#include <cmath>

using namespace std;

typedef pair <double,double> P1;

int N;

P1 arr[1000];

int idx = -1;
double MX = 10000000 * 4;

static inline double dst(P1& a, P1& b) {
  return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}

int main(void) {

  cin.tie(0);
  ios_base::sync_with_stdio(0);


  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  int global_far_idx = 0;
  for (int i = 0; i < N; i++) {
    double far_dist = 0;
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      double cur_dist = dst(arr[i], arr[j]);

      far_dist = max(far_dist, cur_dist);
    }

    if (MX > far_dist) {
      MX = far_dist;
      global_far_idx = i;
    }
  }

  cout.precision(12);
  cout << arr[global_far_idx].first << ' ' << arr[global_far_idx].second << '\n';
  // cout << global_far_dist << '\n';

  return 0;
}
