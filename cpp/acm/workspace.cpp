#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

int T;

class vec {
public:
  int x;
  int y;

  vec() = default;
  vec& operator=(const vec& rhs) = default;
  vec(int x, int y) {this->x = x; this->y = y;}

  template<typename T>
  int operator*(T&& v) {
    return x * v.y - y * v.x;
  }

  template<typename T>
  int dot(T&& v) {
    return (x * v.x + y * v.y);
  }

  template<typename T>
  vec operator-(T&& v) {
    return Vec(x - v.x, y - v.y);
  }
};

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> T;

  while (T--) {
    int xs, ys, xe, ye, xl, yt, xr, yb;
    cin >> xs >> ys >> xe >> ye >> xl >> yt >> xr >> yb;

    int cnt = 0;
    if (xs >= xl && xs <= xr && ys <= yt && ys >= yb) cnt++;
    if (xe >= xl && xe <= xr && ye <= yt && ye >= yb) cnt++;

    if (cnt > 0) {
      cout << "Y" << '\n';
      continue;
    }

    vec vs(xs,ys);
    vec ve(xe,ye);

    vec va[4];
    va[0] = vec(xl,yt);
    va[1] = vec(xr,yt);
    va[2] = vec(xl,yb);
    va[3] = vec(xr,yb);

    for (int i = 0; i < 4; i++) {
      int i2 = (i + 1) % 4;

      int cross1 = (ve - vs) * (va[i] - vs);
      int cross2 = (ve - vs) * (va[i2] - vs);
      int cross3 = (va[i2] - va[i]) * (vs - va[i]);
      int cross4 = (va[i2] - va[i]) * (ve - va[i]);

      if (cross1 * cross2 < 0 && cross3 * cross4 < 0) {
        cout << "Y" << '\n';
        break;
      }
      else if (cross1* cross2 == 0)


    }
  }
  return 0;
}