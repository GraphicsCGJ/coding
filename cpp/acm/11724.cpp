#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int **map;
bool *visited;

void dfs(int idx) {
    visited[idx] = true;

    for (int i = 0; i < n; i++) {
        if (visited[i] == false && map[idx][i] == 1)
            dfs(i);
    }
}

int main(void) {
    int resultVal = 0;

    cin >> n >> m;

    map = (int**)malloc(sizeof(int*) * n);
    visited = (bool*)malloc(sizeof(bool) * n);

    for (int i = 0; i < n; i++) {
        visited[i] = false;

        map[i] = (int*)malloc(sizeof(int) * n);
        memset(map[i], 0x00, n * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        map[a - 1][b - 1] = 1;
        map[b - 1][a - 1] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            dfs(i);
            resultVal ++;
        }
    }

    cout << resultVal << endl;

    return 0;
}