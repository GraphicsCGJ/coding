#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b;

vector<ll> found;
int minVal;

void dfs(ll num, int cnt) {
    // cout << num << '\n';

    if (num > b) return;
    else if (num == b) {
        if (minVal == 0 || minVal > cnt)
            minVal = cnt;
        return;
    }
    else {
        dfs(num * 2, cnt + 1);
        dfs(num * 10 + 1, cnt + 1);
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> a >> b;

    dfs(a, 0);

    cout << (minVal == 0 ? -1 : minVal  + 1) << '\n';

    return 0;
}