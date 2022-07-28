#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define MAX_VAL 51

int n, m;
char map[MAX_VAL][MAX_VAL];
bool visited[MAX_VAL][MAX_VAL];

int result;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

class tmp_c {
    public:
        int x;
        int y;
        int depth;

    tmp_c(int x, int y, int depth) {
        this->x = x;
        this->y = y;
        this->depth = depth;
    }
};

void bfs(int si, int sj) {
    queue<tmp_c> q;

    tmp_c f(si, sj, 0);

    q.push(f);

    while(!q.empty()) {
        tmp_c node = q.front();

        visited[node.x][node.y] = true;
        q.pop();

        if (node.depth > result)
            result = node.depth;

        for (int i = 0; i < 4; i++) {
            int ni = dy[i] + node.x;
            int nj = dx[i] + node.y;

            if (ni < 0 || ni >= n || nj < 0 || nj >= m || visited[ni][nj] || map[ni][nj] == 'W')
                continue;

            tmp_c new_node(ni, nj, node.depth + 1);
            visited[ni][nj] = true;
            q.push(new_node);

        }
    }
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'L') {
                memset(visited, false, sizeof(visited));

                bfs(i, j);
            }
        }
    }

    cout << result << endl;


    return 0;
}