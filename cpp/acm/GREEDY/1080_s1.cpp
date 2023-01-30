#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M;

int matA[50][50];
int matB[50][50];

void convert(int r, int c) {
    for (int i = r; i < r + 3; i++) {
        for (int j = c; j < c + 3; j++) {
            matA[i][j] = 1 - matA[i][j];
        }
    }
}

bool check() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matA[i][j] != matB[i][j])
                return false;
        }
    }
    return true;
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
            matA[i][j] = s[j] - '0';
    }

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
            matB[i][j] = s[j] - '0';
    }

    if (check()) {
        cout << 0 << '\n';
        return 0;
    }
    if (N < 3 || M < 3) {
        cout << -1 << '\n';
        return 0;
    }


    int cnt = 0;
    for (int i = 0; i <= N - 3; i++) {
        for (int j = 0; j <= M - 3; j++) {
            if (matA[i][j] != matB[i][j]) {
                convert(i,j); cnt++;
                if (check()) {
                    cout << cnt << '\n';
                    return 0;
                }
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}
