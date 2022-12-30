#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int *known;
int *parent;
vector<vector<int>> party;


int findSet(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = findSet(parent[v]);
}

void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b)
        parent[b] = a;
}

int main(void) {
    int known_cnt;

    cin >> n >> m;
    cin >> known_cnt;

    known = new int[n + 1];
    parent = new int [n + 1];

    /* init parent */
    for (int i = 0; i <= n; i++)
        parent[i] = i;

    /* cin known */
    for (int i = 0; i < known_cnt; i++) {
        int tmp;
        cin >> tmp;
        known[tmp] = 1;
    }

    /* get party lists */
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        vector<int> vec(tmp, 0);
        for (int j = 0; j < tmp; j++) {
            cin >> vec[j];
        }
        party.push_back(vec);
    }

    /* calc parent*/
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < party[i].size(); j++) {
            int a;
            int b;
            if (known[findSet(party[i][j])] == 1) {
                a = party[i][j];
                b = party[i][j - 1];
            }
            else {
                a = party[i][j - 1];
                b = party[i][j];
            }

            unionSet(a, b);
        }
    }

    int ret = 0;
    for (int i = 0; i < m; i++) {
        bool possible = true;
        for (int j = 0; j < party[i].size(); j++) {
            int &val = party[i][j];
            if (known[findSet(val)] == 1) {
                possible = false;
                break;
            }
        }

        if (possible == true)
            ret++;
    }

    cout << ret << endl;

    return 0;
}