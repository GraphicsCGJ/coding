#include <iostream>

using namespace std;

typedef long long ll;

class Vec {
public:
    ll x;
    ll y;

    Vec() = default;
    Vec(ll x, ll y) {
        this->x = x;
        this->y = y;
    };
    Vec(const Vec& other) = default;
    Vec& operator=(const Vec& rhs) = default;

    ll operator*(Vec&& v) {
        return x * v.y - y * v.x;
    }
    ll operator*(Vec& v) {
        return x * v.y - y * v.x;
    }

    ll dot(Vec&& v) {
        return (x * v.x + y * v.y);
    }

    ll dot(Vec& v) {
        return (x * v.x + y * v.y);
    }

    Vec operator-(Vec& v) {
        return Vec(x - v.x, y - v.y);
    }
};

int main(void) {
    Vec v1, v2, v3, v4;
    cin >> v1.x >> v1.y >> v2.x >> v2.y;
    cin >> v3.x >> v3.y >> v4.x >> v4.y;

    ll cross1 = (v2 - v1) * (v3 - v1);
    ll cross2 = (v2 - v1) * (v4 - v1);
    ll cross3 = (v4 - v3) * (v1 - v3);
    ll cross4 = (v4 - v3) * (v2 - v3);

    if (cross1 == 0 && cross2 == 0) {
        ll d1 = (v3 - v1).dot(v4-v1);
        ll d2 = (v3 - v2).dot(v4-v2);
        // cout << d1 << ' ' << d2 << '\n';

        if (d1 < 0 || d2 < 0) {
            cout << 1 << '\n';
        }
        else if (d1 == 0 || d2 == 0) {
            cout << 1 << '\n';
        }
        else {
            if ((v2 - v3).dot(v1 - v3) < 0)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
    }
    else if (cross1 == 0) {
        if ((v2 - v1).dot(v3 - v1) < 0 || (v1 - v2).dot(v3 - v2) < 0)
            cout << 0 << '\n';
        else {
            cout << 1 << '\n';
            //
        }
    }
    else if (cross2 == 0) {
        if ((v2 - v1).dot(v4 - v1) < 0 || (v1 - v2).dot(v4 - v2) < 0)
            cout << 0 << '\n';
        else {
            cout << 1 << '\n';

        }
    }
    else if (cross3 == 0) {
        if ((v4 - v3).dot(v1 - v3) < 0 || (v3 - v4).dot(v1 - v4)  < 0)
            cout << 0 << '\n';
        else {
            cout << 1 << '\n';
            //
        }
    }
    else if (cross4 == 0) {
        if ((v4 - v3).dot(v2 - v3) < 0 || (v3 - v4).dot(v2 - v4) < 0)
            cout << 0 << '\n';
        else {
            cout << 1 << '\n';
            //
        }
    }
    else if ((double)cross1 * (double)cross2 < 0 && (double)cross3 * (double)cross4 < 0) {
        cout << 1 << '\n';

    }
    else {
        cout << '0' << '\n';
    }

    return 0;
}