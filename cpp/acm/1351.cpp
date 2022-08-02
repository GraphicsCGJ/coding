#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;


vector<ll> vec;

int N, P, Q;

int find_vec(ll n) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == n)
            return i;
    }
    return -1;
}

ll calc(ll n) {
    int idx = find_vec(n);
    if (find_vec(n) != -1) {
        return
    }
}

int main(void) {
    cin >> N >> P >> Q;


    return 0;
}