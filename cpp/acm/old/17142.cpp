#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_VAL 51

int map[MAX_VAL][MAX_VAL];
int map2[MAX_VAL][MAX_VAL];
bool visited[MAX_VAL][MAX_VAL];

int n, cnt;

int dx[4]{0, 0, 1, -1};
int dy[4]{1, -1, 0, 0};

class tmp_c {
    public:
        int r;
        int c;
        int value;
        tmp_c(int r, int c, int value) {
            this->r = r;
            this->c = c;
            this->value = value;
        }
};

int propagation() {

    vector<tmp_c> v, v2;
    v.reserve(MAX_VAL * MAX_VAL);
    v2.reserve(MAX_VAL * MAX_VAL);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map2[i][j] > 0) {
                tmp_c tmp(i, j, map2[i][j]);
                v.push_back(tmp);
            }
        }
    }
    int max_val = 1;

    while (!v.empty()) {
        v2.clear();
        for (auto& vi : v) {
            for (int i = 0; i < 4; i++) {
                int r2 = vi.r + dx[i];
                int c2 = vi.c + dy[i];

                if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= n || (map2[r2][c2] > 0 || map[r2][c2] == -1))
                    continue;

                tmp_c tmp(r2, c2, map2[r2][c2]);
                v2.push_back(tmp);


                map2[r2][c2] = map2[vi.r][vi.c] + 1;
                if (tmp.value == -2) continue;
                if (map2[r2][c2] > max_val)
                    max_val = map2[r2][c2];
            }
        }
        v = v2;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map2[i][j] == 0)
                return -1;
        }
    }

    return max_val;
}

int main(void) {
    vector<tmp_c> v;
    vector<int> comb;
    v.reserve(MAX_VAL * MAX_VAL);
    comb.reserve(MAX_VAL * MAX_VAL);

    cin >> n >> cnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                tmp_c tmp(i, j, map[i][j]);
                v.push_back(tmp);
                map[i][j] = -2;
            } else if(map[i][j] == 1)
                map[i][j] = -1;
        }
    }

    for (int i = 0; i < v.size(); i++) {
        if (i < v.size() - cnt)
            comb.push_back(0);
        else
            comb.push_back(1);
    }

    int max_val = MAX_VAL * MAX_VAL + 1;
    do {
        /* copy map to bfs map*/
        memcpy(map2, map, sizeof(map));
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < comb.size(); i++) {
            if (comb[i] == 1)
                map2[v[i].r][v[i].c] = 1;
        }

        /* do propagate */
        int result = propagation();

        if (result == -1)
            continue;

        if (result < max_val)
            max_val = result;
    } while (next_permutation(comb.begin(), comb.end()));

    if (max_val == MAX_VAL * MAX_VAL + 1) {
        cout << -1 << endl;
    }
    else {
        cout << max_val - 1 << endl;
    }

    return 0;
}