#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> P1;

#define MX 499999

int N, M, R;
int items[100];
int roads[100][100];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M >> R;
    fill(&roads[0][0], &roads[N-1][N], MX);
    for (int i = 0; i < N; i++) {
        cin >> items[i];
        roads[i][i] = 0;
    }
    for (int i = 0; i < R; i++) {
        int a, b, w;
        cin >> a >> b >> w; a--; b--;
        roads[a][b] = w;
        roads[b][a] = w;
    }

            for (int k = 0; k < N; k++)  {
    for (int i = 0; i < N; i++)  {
        for (int j = 0; j < N; j++)  {
                roads[i][j] = min(roads[i][j], roads[i][k] + roads[k][j]);
            }
        }
    }

    int gmx = 0;
    for (int i = 0; i < N; i++)  {
        int lmx = 0;
        for (int j = 0; j < N; j++)  {
            if (roads[i][j] <= M)
                lmx += items[j];
        }

        if (gmx < lmx)
            gmx = lmx;
    }

    cout << gmx << '\n';

    return 0;
}