#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int,int> P1;

int N;

vector<P1> vc;

bool cmp(P1& p1, P1& p2) {
    return p1.second == p2.second ? p1.first > p2.first : p1.second > p2.second;
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    vc.emplace_back(0,0);
    for (int i = 0; i < N; i++) {
        P1 p;
        cin >> p.first >> p.second;
        vc.push_back(p);
    }

    sort(vc.begin(), vc.end(), cmp);

    int pre = vc[0].second;
    int MX = 0;
    for (auto& vi : vc) {
        if (vi.second < pre) {
            MX = (pre - vi.second > MX ? pre - vi.second : MX);
            pre = vi.second;
        }
        pre -= vi.first;
    }

    cout << MX << '\n';
    return 0;
}

