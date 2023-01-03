#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, M, A;

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M >> A;

    cout << (N / A + (N % A != 0)) * (M / A + (M % A != 0)) << '\n';

    return 0;
}

