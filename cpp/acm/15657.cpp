#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int N, M;
string arr[8];

void dfs(int indices[], int size, int pos, int lvl) {
    if (lvl == M) {
        for (int i = 0; i < M; i++)
            cout << arr[indices[i]] << " ";
        cout << '\n';

        return;
    }
    if (pos >= N) return;

    indices[size++] = pos;
    dfs(indices, size, pos, lvl + 1);
    size--;
    dfs(indices, size, pos + 1, lvl);
}

int main(void) {
    int arr2[8];
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    fill (&arr[0], &arr[8], 0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(&arr[0], &arr[N]);

    dfs(arr2, 0, 0, 0);

    return 0;
}