#include<iostream>
#include<algorithm>

using namespace std;
int N;
int cnt1, cnt2;
int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);


    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        cnt2 += (tmp/2);
        cnt1 += (tmp%2);
    }

    // cout << cnt1 << ':' << cnt2 << '\n';
    if (cnt2 < cnt1 || (cnt2 - cnt1) % 3 != 0)
        cout << "NO\n";
    else
        cout << "YES\n";

    return 0;
}
