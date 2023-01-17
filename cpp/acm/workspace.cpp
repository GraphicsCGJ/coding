#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MX 250000000

typedef long long ll;

typedef pair<ll, ll> P1;

ll T, N, M, W;
vector<P1> edges[100000];
ll dst[101][101];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    cin >> M;
    fill(&dst[0][0], &dst[N-1][N], MX);

    for (int i = 0; i < N; i++)
        dst[i][i] = 0;

    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w; a--; b--;

        dst[a][b] = (dst[a][b] > w ? w : dst[a][b]);
    }
        /* floyd */

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
            }
        }
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (dst[i][j] < MX ? dst[i][j] : 0) << ' ';
        }
        cout << '\n';
    }

    return 0;
}