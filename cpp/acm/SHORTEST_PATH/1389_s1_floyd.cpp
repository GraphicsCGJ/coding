#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_DIST 101
#define MAX_DEGE 5000

int dist[MAX_DIST][MAX_DIST];

int N, M;

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = i == j ? 0 : MAX_DIST;
        }
    }

    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        dist[l][r] = dist[r][l] = 1;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[j][i] = dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int target = -1;
    int globalMin = MAX_DIST;
    for (int i = 0; i < N; i++) {

        int localMin = 0;
        for (int j = 0; j < N; j++) {
            // cout << dist[i][j] << " ";
            localMin += dist[i][j];
        }

        if (localMin < globalMin) {
            globalMin = localMin;
            target = i + 1;
        }

        // cout << endl;
    }

    cout << target << endl;


    return 0;
}