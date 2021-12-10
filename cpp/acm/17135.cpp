#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX_VAL 16

typedef pair<int, int> node_t;


int n, m, d;
int map[MAX_VAL][MAX_VAL];
int map2[MAX_VAL][MAX_VAL];


int dist(node_t& a, node_t& b) {
    int x = a.first - b.first;
    int y = a.second - b.second;
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    return x + y;
}

int main(void) {
    cin >> n >> m >> d;
    vector<bool> comb;
    int height = -1;

    for (int i = 0; i < m; i++)
        comb.push_back(i < m - 3 ? false : true);



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1 && height < n - i)
                height = n - i;
        }
    }

    int result = -1;
    vector<int> arch;
    vector<node_t> target;
    vector<node_t> erased;

    arch.reserve(MAX_VAL);
    target.reserve(MAX_VAL * MAX_VAL);
    erased.reserve(MAX_VAL * MAX_VAL);
    do { /* mC3 = m^3*/
        // archor
        arch.clear();

        for (int i = 0; i < comb.size(); i++) {
            if (comb[i] == true)
                arch.push_back(i);
        }

        memcpy(map2, map, sizeof(map2));

        int local_result = 0;
        for (int ii = 0; ii < height; ii++) { // n
            /* m */
            target.clear();
            erased.clear();

            // /* debug map2 */
            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j < m; j++) {
            //         cout << map2[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;

            for (int j = 0; j < m; j++) {
                for (int i = 0; i < n; i++) {
                    if (map2[n - i - 1][j] == 1) {
                        node_t node(n - i - 1, j);
                        target.push_back(node);
                        break;
                    }
                }
            }

            int ax = n;
            for (auto& ay : arch) {
                int min_d = MAX_VAL + MAX_VAL + 1;
                node_t an(ax, ay);
                node_t erase(-1, -1);

                // cout << an.first << ", " << an.second << endl;
                for (auto& t : target) {
                    // cout << t.first << ", " << t.second << "[" << dist(an, t)<< "] ";
                    if (dist(an, t) <= d && min_d > dist(an, t)) {
                        erase = t;
                        min_d = dist(an, t);
                    }
                }
                // cout << endl;

                if (erase.second >= 0 && find(erased.begin(), erased.end(), erase) == erased.end()) {
                    map2[erase.first][erase.second] = 0;
                    local_result++;
                    erased.push_back(erase);
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i == n - 1) {
                        map2[n - i - 1][j] = 0;
                    }
                    else {
                        map2[n - i - 1][j] = map2[n - i - 2][j];
                    }
                }
            }
        }

        if (local_result > result)
            result = local_result;

    } while(next_permutation(comb.begin(), comb.end()));

    cout << result << endl;
    return 0;
}
