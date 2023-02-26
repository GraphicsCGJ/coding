#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int X, Y;
double D, T;

int main(void) {

  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> X >>Y>>D>>T;
  cout << fixed;
  cout.precision(12);

  double t = 0;
  double distance = pow(X, 2) + pow(Y, 2);
  distance = sqrt(distance);

  if (D/T < 1) {
    cout << distance << '\n';
  }
  else {
    double cnt = 0;
    double tmp = (distance - 2*D) / D;
    if (tmp > 0) {
      cnt = (int)tmp + 1;
    }

    double remain = distance - cnt*D;

    // cout << remain << '\n';
    t = remain;
    if (t > T + (remain-D < 0 ? D-remain : remain-D)) t = T + (remain-D < 0 ? D-remain : remain-D);
    if (t > 2.0*T) t=2.0*T;

    t += (cnt*T);
    cout << t  << '\n';
  }

  return 0;
}
