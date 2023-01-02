#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int field[20][20];

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

class Ca {
public:
    int i;
    int j;
    int dist;
    Ca() {}
    Ca(int i, int j, int dist) {
        this->i = i;
        this->j = j;
        this->dist = dist;
    }
    void print1() {
        cout << i << ":" << j << " " << dist << '\n';
    }
    void print2() {
        cout << '\t'<<i << ":" << j << " " << dist << '\n';
    }
};

bool cmp (Ca& a, Ca& b) {
    return a.i == b.i ? a.j < b.j : a.i < b.i;
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    Ca cur;
    int level = 2;
    int exp = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> field[i][j];
            if (field[i][j] == 9) {
                cur.i = i; cur.j = j;
                cur.dist = 0;
                field[i][j] = 0;
            }
        }
    }

    while (cur.dist >= 0) {
        bool visited[N][N];
        vector<Ca> vec1;
        fill(&visited[0][0], &visited[N-1][N], false);
        visited[cur.i][cur.j] = true;
        vec1.push_back(cur);
        Ca nxt(-1, -1, -1);
        while (vec1.size() > 0) { // same distance Ca's vector
            vector<Ca> vec2;
            for (auto& cur2 : vec1) {
                for (int i = 0; i < 4; i++) {
                    int i2 = dy[i] + cur2.i;
                    int j2 = dx[i] + cur2.j;

                    if (i2 < 0 || i2 >= N || j2 < 0 || j2 >= N || visited[i2][j2] == true || field[i2][j2] > level)
                        continue;

                    visited[i2][j2] = true;
                    Ca nxt(i2, j2, cur2.dist + 1);
                    vec2.push_back(nxt);
                }
            }

            sort(vec2.begin(), vec2.end(), cmp);

            for (auto& v : vec2) {
                if (field[v.i][v.j] < level && field[v.i][v.j] > 0) {
                    field[v.i][v.j] = 0;
                    nxt = v;
                    exp++;
                    if (exp == level) {
                        level ++;
                        exp = 0;
                    }
                    break;
                }
            }

            if (nxt.dist < 0) // not found
                vec1 = vec2;
            else
                break;
        }

        // nxt is next loc.
        if (nxt.dist < 0) { // no Location.
            cout << cur.dist << '\n';
            break;
        }
        else {
            cur = nxt;
        }
    }


    return 0;
}