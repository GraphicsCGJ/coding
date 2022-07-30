#include <iostream>

using namespace std;

int N;
int canEat;
int map[21][21];
bool visited[21][21];

void initvisited() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
}

void dfs (int i, int j) {

}

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    visited[]




    return 0;
}