#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P1;
vector<P1> vec1;

int N, D;
int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> D;

    for (int i = 0; i < N; i++) {
        ll m, s;
        cin >> m >> s;
        bool flag = false;
        for (auto &v : vec1) {
            if (v.first == m) {
                v.second += s;
                flag = true; break;
            }
        }
        if (flag == false) vec1.push_back(P1(m, s));
    }

    sort(vec1.begin(), vec1.end());

    /* make segment tree */

    /* */
    ll globalMax = 0;
    for (int i = 0; i < vec1.size(); i++) {
        int reach = vec1[i].first + D;
        ll localMax = 0;
        for (int j = i; j < vec1.size(); j++) {
            if (vec1[j].first >= reach) break;

            localMax += vec1[j].second;
        }

        if (globalMax < localMax)
            globalMax = localMax;
    }

    cout << globalMax << '\n';

    return 0;
}

