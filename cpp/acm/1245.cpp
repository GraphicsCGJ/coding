#include <iostream>

using namespace std;

int field[101][71];
bool visited[101][71];
int N, M;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int cnt = 0;

int main(void) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> field[i][j];
            visited[i][j] = false;
        }
    }



}
