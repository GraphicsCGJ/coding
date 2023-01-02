#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int arr[8];
bool isUsed[8];

void dfs(int values[], int size, int lvl, int lvlMax) {
    if (lvl == lvlMax) {
        for (int i = 0; i < M; i++)
            cout << values[i] << " ";
        cout << '\n';

        return;
    }

    for (int i = 0; i < N; i++) {
        if (isUsed[i])
            continue;

        values[size++] = arr[i];
        isUsed[i] = true;
        dfs(values, size, lvl + 1, lvlMax);
        isUsed[i] = false;
        size--;
    }
}

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(&arr[0], &arr[N]);
    int dfsArr[8];

    dfs(dfsArr, 0, 0, M);

    return 0;
}