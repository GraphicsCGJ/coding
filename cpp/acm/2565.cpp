#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class C1 {
public:
    int a, b;
};

C1 lanes[100];
int dp[101];
int N;

bool cmp (C1& a, C1& b) {
    return a.cnt > b.cnt;
}

int main(void) {
    int globalCnt = 0;
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b; a--; b--;

        C1 &c1 = lanes[i];
        c1.a = a; c1.b = b;
    }

    sort(lanes, lanes + N, cmp);

    for (int i = 0; i < N; i++) {
        dp[i] = 1;

        for (int j = 0; j <= i; j++) {
            if (lanes[j].b <)
        }
    }

    return 0;
}