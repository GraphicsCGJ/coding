#include <iostream>
#include <vector>

using namespace std;

int N, M;

int cheet[100] = {0, };
bool visited[100] = {0, };

vector<int> bfs;

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i < N + M; i++) {
        int a, b;
        cin >> a >> b;
        cheet[a - 1] = b - 1;
    }

    bfs.push_back(0);
    visited[0] = true;

    int cnt = 0;
    for (int i = 1; i <= 6; i++) {
        bfs.push_back(cheet[i] == 0 ? i : cheet[i]);
        visited[bfs[bfs.size() - 1]] = true;
    }

    while (bfs.size() != 0) {
        cnt ++;
        vector<int> bfs2;
        // for (auto& i : bfs) {
        //     cout << i << " ";
        // }
        // cout << endl;
        for (auto& i : bfs) {
            if (i == 99) {
                cout << cnt << endl;
                return 0;
            }

            for (int j = 1; j <= 6; j++) {
                if (i + j >= 100) continue;;
                int tar = cheet[i + j] == 0 ? i + j : cheet[i + j];
                if (visited[tar] == false) {
                    visited[tar] = true;
                    bfs2.push_back(tar);
                }
            }
        }

        bfs = bfs2;
    }

    cout << -1 << endl;

    return 0;
}