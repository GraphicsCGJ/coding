#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MX 250000000

typedef pair<int, int> P1;

int T, N, M, W;
vector<P1> edges[501];
int dst[501][501];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> T;

    while (T--) {
        cin >> N >> M >> W;
        fill(&dst[0][0], &dst[N-1][N], MX);

        // for (int i = 0; i < N; i++)
        //     edges[i].clear();

        for (int i = 0; i < M; i++) {
            int a, b, w;
            cin >> a >> b >> w; a--; b--;
            // edges[a].push_back(P1(b, w));
            // edges[b].push_back(P1(a, w));

            dst[a][b] = (dst[a][b] > w ? w : dst[a][b]);
            dst[b][a] = (dst[b][a] > w ? w : dst[b][a]);
        }

        for (int i = 0; i < W; i++) {
            int a, b, w;
            cin >> a >> b >> w; a--; b--;
            // edges[a].push_back(P1(b, -w));
            w = -w;

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

        bool flag = false;
        for (int i = 0; i < N && !flag; i++) {
            for (int j = 0; j < N && !flag; j++) {
                if (dst[i][j] + dst[j][i] < 0) flag = true;
            }
        }

        cout << (flag ? "YES\n" : "NO\n");
    }


    return 0;
}