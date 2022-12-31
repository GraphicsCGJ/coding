#include <iostream>
#include <vector>
using namespace std;

class C1 {
public:
    int z, y, x;
    C1 (int z, int y, int x) {
        this->z = z;
        this->y = y;
        this->x = x;
    }
};

int N, M, H;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dh[6] = {0, 0, 0, 0, -1, 1};

int tomato[100][100][100];

vector<C1> search_1() {
    vector<C1> vec;
    for (int k = 0; k < H; k++) {
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < M; i++) {
                if (tomato[k][j][i] == 1) {
                    C1 c1(k, j, i);
                    vec.push_back(c1);
                }
            }
        }
    }

    return vec;
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int cnt = 0;

    cin >> M >> N >> H;

    for (int k = 0; k < H; k++) {
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < M; i++) {
                cin >> tomato[k][j][i];
            }
        }
    }

    vector<C1> vec1 = search_1();
    while (true) {
        vector<C1> vec2;

        /* 2. bfs */
        int local_cnt = 0;
        for (auto& c1 : vec1) {
            for (int i = 0; i < 6; i++) {
                int i2 = c1.x + dx[i];
                int j2 = c1.y + dy[i];
                int k2 = c1.z + dh[i];

                if (i2 < 0 || i2 >= M || j2 < 0 || j2 >= N || k2 < 0 || k2 >= H)
                    continue;

                if (tomato[k2][j2][i2] == 0) {
                    tomato[k2][j2][i2] = 1;
                    C1 c1(k2, j2, i2);
                    vec2.push_back(c1);

                    local_cnt++;
                }
            }
        }

        if (local_cnt > 0)
            cnt++;
        else
            break;

        vec1 = vec2;
    }

    /* final check */
    for (int k = 0; k < H; k++) {
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < M; i++) {
                if (tomato[k][j][i] == 0) {
                    cout << -1 << "\n";
                    return 0;
                }
            }
        }
    }

    cout << cnt << "\n";

    return 0;

}