#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int map[10][10];
int papers[6];

int mincnt;

class c1 {
    public:
        int used[6];
        c1() {
            memset(used, 0x00, sizeof(int) * 6);
        }
};

vector<c1> v1;

void calc_1(int cnt, int idx, c1 val) {
    int tmp = (idx / 5) + 1;

    if (cnt - tmp >= 0) {
        val.used[tmp]++;
        calc_1(cnt - tmp, idx - 1, val);
        val.used[tmp]--;
    }
    calc_1(cnt - 1, idx - 1, val);
}

int main(void) {
    mincnt = 100;
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) cnt++;
        }
    }


    return 0;
}























// void calc(int factor, int cnt, int i_in, int j_in) {
//     /* papers check */
//     bool check = true;
//     if (factor <= 0) return;

//     for (int i = 0; i < 10 && check == true; i++) {
//         for (int j = 0; j < 10 && check == true; j++) {
//             if (map[i][j] != 0)
//                 check = false;
//         }
//     }
//     if (check == true) {
//         if (mincnt > cnt) {
//             mincnt = cnt;
//             return;
//         }
//     }

//     if (papers[factor] == 0) {
//         factor--;
//         i_in = 0; j_in = 0;
//         if (factor <= 0) return;
//     }

//     /* map check */
//     for (int i = i_in; i <= 10 - factor; i++) {
//         for (int j = i == i_in ? j_in : 0; j <= 10 - factor; j++) {
//             check = true;
//             for (int ii = i; ii < i + factor && check; ii++) {
//                 for (int jj = j; jj < j + factor && check; jj++) {
//                     if (map[ii][jj] == 0)
//                         check = false;
//                 }
//             }

//             if (check == true) {
//                 cout << " " << i+1 << ":" << j+1 << "> factor: " << factor << "  cnt: " << cnt << endl;
//                 /* in */
//                 papers[factor] --;
//                 for (int ii = i; ii < i + factor && check; ii++) {
//                     for (int jj = j; jj < j + factor && check; jj++) {
//                         map[ii][jj] = 0;
//                     }
//                 }
//                 calc(factor, cnt + 1, i, j + 1);
//                 papers[factor] ++;
//                 for (int ii = i; ii < i + factor && check; ii++) {
//                     for (int jj = j; jj < j + factor && check; jj++) {
//                         map[ii][jj] = 1;
//                     }
//                 }

//                 /* not in */
//                 calc(factor, cnt, i, j + 1);
//             }
//         }
//     }
//     calc(factor - 1, cnt, 0, 0);
// }