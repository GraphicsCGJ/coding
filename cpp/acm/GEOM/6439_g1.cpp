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
    return vec(x - v.x, y - v.y);
  }
};

bool isCross(vec v1, vec v2, vec v3, vec v4) {
  int c1 = (v2-v1)*(v3-v1);
  int c2 = (v2-v1)*(v4-v1);
  int c3 = (v2-v3)*(v4-v3);
  int c4 = (v1-v3)*(v4-v3);

  if (c1 * c2 == 0 && c3 * c4 == 0) {
    int d1 = (v3 - v1).dot(v4-v1);
    int d2 = (v3 - v2).dot(v4-v2);

    if (d1 < 0 || d2 < 0)
        return true;
    else if (d1 == 0 || d2 == 0)
        return true;
    else {
        if ((v2 - v3).dot(v1 - v3) < 0)
            return true;
        else
            return false;
    }
  }
  else if (c1 * c2 == 0) {
    if (c1 == 0 && (v1-v3).dot(v2-v3) <= 0)
      return true;
    else if (c2 == 0 && (v1-v4).dot(v2-v4) <= 0)
      return true;
    return false;
   }
   else if (c3 * c4 == 0) {
    if (c3 == 0 && (v3-v2).dot(v4-v2) <= 0)
      return true;
    else if (c4 == 0 && (v3-v1).dot(v4-v1) <= 0)
      return true;
    return false;
   }
   else if (c1 * c2 < 0 && c3 * c4 < 0) {
    return true;
   }
   else
    return false;
}

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> T;

  while (T--) {
    int xs, ys, xe, ye, xl, yt, xr, yb;
    cin >> xs >> ys >> xe >> ye >> xl >> yt >> xr >> yb;

    if (xl > xr) swap(xl, xr);
    if (yb > yt) swap(yb, yt);

    int cnt = 0;
    if (xs >= xl && xs <= xr && ys <= yt && ys >= yb) cnt++;
    if (xe >= xl && xe <= xr && ye <= yt && ye >= yb) cnt++;

    if (cnt > 0) {
      cout << "T" << '\n';
      continue;
    }

    vec vs(xs,ys);
    vec ve(xe,ye);

    vec va[4];
    va[0] = vec(xl,yt);
    va[1] = vec(xr,yt);
    va[2] = vec(xr,yb);
    va[3] = vec(xl,yb);

    bool ans = false;
    for (int i = 0; i < 4 && !ans; i++) {
      int i2 = (i + 1) % 4;
      ans = ans | isCross(vs, ve, va[i], va[i2]);
    }

    cout << (ans == true ? "T" : "F") << '\n';
  }
  return 0;
}