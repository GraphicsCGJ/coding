#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int l;
    int r;
} pair_t;

bool compare_f(pair_t &a, pair_t &b) {
    return a.l < b.l;
}

int main(void) {

    int n;
    vector<pair_t> vec;
    cin >> n;

    vec.reserve(n);
    for (int i = 0; i < n; i++) {
        pair_t p;
        cin >> p.l >> p.r;
        vec.push_back(p);
    }

    sort(vec.begin(), vec.end(), compare_f);

    for (int i = 0; i < n; i++) {
        pair_t &p = vec[i];
        cout << p.l << " " << p.r << endl;
    }

    return 0;
}