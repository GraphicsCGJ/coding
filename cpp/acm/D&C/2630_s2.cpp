#include <iostream>

using namespace std;

int paper[128][128];
int N;
int blue = 0;
int white = 0;

void isfill(int si, int sj, int n) {
    int ret = paper[si][sj];
    for (int i = si; i < si + n && ret != -1; i++) {
        for (int j = sj; j < sj + n && ret != -1; j++) {
            if (ret != paper[i][j]) {
                ret = -1;
            }
        }
    }

    if (ret == 0)
        white ++;
    else if (ret == 1)
        blue ++;
    else {
        int n2 = n / 2;
        isfill(si, sj, n2);
        isfill(si, sj + n2, n2);
        isfill(si + n2, sj, n2);
        isfill(si + n2, sj + n2, n2);
    }
}

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    // input
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    isfill(0, 0, N);
    cout << white << endl;
    cout << blue << endl;
}