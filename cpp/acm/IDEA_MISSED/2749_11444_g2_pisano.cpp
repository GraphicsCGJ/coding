#include <iostream>

#include<vector>

using namespace std;

typedef long long ll;

ll N;
ll TARGET;

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    TARGET = 1000000007;
    TARGET = 1000000;

    vector<ll> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);

    cin >> N;

    ll sz = 3;
    while (true) {
        v.push_back((v[sz - 1] + v[sz - 2]) % TARGET);
        sz++;

        if (v[sz - 1] == 0 && v[sz - 2] == 1) {
            break;
        }
    }

    cout << v[(N % (sz - 1))] << '\n';

    return 0;
}
