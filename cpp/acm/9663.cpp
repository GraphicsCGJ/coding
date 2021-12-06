// N QUEEN

#include <iostream>
#include <vector>

using namespace std;

int cnt;

bool check(
    vector<vector<int>>& v,
    int r,
    int c,
    int n
) {

    for (int i = 0; i < n; i++) {
        int r1, r2;
        r1 = r - c + i;
        r2 = r + c - i;
        if (v[i][c] == 1)
            return false;
        if (v[r][i] == 1)
            return false;
        if (r1 >= 0 && r1 < n && v[r1][i] == 1)
            return false;
        if (r2 >= 0 && r2 < n && v[r2][i] == 1)
            return false;
    }

    return true;
}


void backtracking(
    vector<vector<int>>& v,
    int i,
    int n
) {

    if (i == n) {
        // cout << "found!!" << endl;
        cnt ++;
        return;
    }

    for (int j = 0; j < n; j++) {
        if (check(v, i, j, n) == true) {
            v[i][j] = 1;
            backtracking(v, i+1, n);
            v[i][j] = 0;
        }
    }
}

int main(void) {
    int n;

    cin >> n;

    cnt = 0;
    vector<vector<int>> v(n, vector<int>(n, 0));
    backtracking(v, 0, n);
    cout << cnt << endl;

    return 0;
}