#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int N;

typedef pair<int,int> P1;

int field[21][20];

map<int,P1> mp[20];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0) {
                field[i][j] = 0;
                continue;
            }
            cin >> field[N - i+1][j];
        }
    }

    for (int c = 0; c < N; c++) {
        for (int r = 1; r <= N; r++) {
            field[r][c] += field[r-1][c];
        }
    }
    for (int c = 0; c < N; c++) {
        for (int r = 0; r <= N; r++) {
            if (c == 0) {
                mp[c].emplace(field[r][c], P1(-1, r));
            }
            else {
                for (auto& mpi : mp[c-1]) {
                    if (mpi.second.second > r) continue;
                    mp[c].emplace(mpi.first + field[r][c], P1(mpi.second.second, r));
                }
            }
        }
    }


    vector<int> path;
    pair<int,P1> idx;
    int total_sum = 0;
    for (int c = 0; c < N; c++)
        total_sum += field[N][c];

    int diff = total_sum * 2 + 1;
    for (auto &iter : mp[N-1]) {
        int diff_local = 2 * iter.first - total_sum;
        if (diff_local < 0) diff_local = -diff_local;
        if (diff > diff_local) {
            idx = iter;
            diff = diff_local;
        }
    }

    cout << diff << '\n';
    for (int c = N-1; c >= 0; c--) {
        path.push_back(idx.second.second);
        if (idx.second.first == -1) break;

        int tmp = idx.first - field[idx.second.second][c];
        idx = *mp[c-1].find(tmp);
    }

    for (auto iter = path.rbegin(); iter != path.rend(); iter++) {
        cout << *iter << ' ';
    }cout << '\n';



    return 0;
}

