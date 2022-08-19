#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

ll N, P, Q;
map<ll, ll> map_global;

ll find_value(ll key) {
    if (map_global.find(key) != map_global.end()) {
        return map_global.find(key)->second;
    }

    ll tmp = find_value(key / P) + find_value(key / Q);
    map_global.insert(make_pair(key, tmp));

    return tmp;
}

int main(void) {
    cin >> N >> P >> Q;

    map_global.insert(make_pair(0, 1));
    cout << find_value(N) << endl;

    return 0;
}