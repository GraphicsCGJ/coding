#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int field[9][9];
int n, m;

typedef struct {
    int val;
    bool check;
} tmp_t;

vector<tmp_t> jgs;
vector<int> result;

int b_search(int num) {
    int s = 0;
    int e = jgs.size() - 1;
    int m;

    while (s <= e) {
        m = (s + e) / 2;
        if (jgs[m].val == num)  {
            if (jgs[m].check == false) {
                jgs[m].check = true;
                return num;
            }
            else {
                return -1;
            }
        }
        else if (jgs[m].val > num) e = m - 1;
        else s = m + 1;
    }

    return -1;
}

void search(int si, int sj) {
    for (int i = -8; i <= 8; i++) {
        for (int j = -8; j <= 8; j++) {
            /* 1. make number */
            int ti = si, tj = sj;
            int num = 0;

            while (ti >= 0 && ti < n && tj >= 0 && tj < m) {
                num = ((num * 10) + field[ti][tj]);
                ti += i;
                tj += j;

                int local_num = b_search(num);
                if (local_num != -1)
                    result.push_back(local_num);

                if (i == 0 && j == 0)
                    break;
            }


        }
    }
}

int main(void) {
    cin >> n >> m;

    int tmp = 0;
    while (tmp*tmp <= 999999999) {
        tmp_t tt;
        tt.val = tmp * tmp;
        tt.check = false;
        jgs.push_back(tt);
        tmp ++;
    }

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            field[i][j] = s[j] - '0';
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << field[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            search(i, j);
        }
    }

    if (result.size() > 0) {
        sort(result.begin(), result.end());
        cout << result[result.size() - 1] << endl;
    }

    else {
        cout << -1 << endl;
    }

    return 0;
}
