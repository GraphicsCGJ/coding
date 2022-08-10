#include <iostream>
// #include <iostream>

using namespace std;

int N, M;
int field[1000][1000];
int area[1000][1000];


int main(void) {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            field[i][j] = c - '0';

            area[i][j] = 0;
        }
    }


    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << field[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    int maxval = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (field[i][j] == 1) {
                area[i][j] = 1;
                if (i > 0 && j > 0) {
                    bool check = true;
                    int idx;

                    for (idx = 0; idx <= area[i - 1][j - 1]; idx++) {
                        check = (field[i - idx][j] == 1 && field[i][j - idx] == 1);
                        if (check == false) break;
                    }

                    if (check == true) {
                        area[i][j] = area[i - 1][j - 1] + 1;
                    }
                    else {
                        area[i][j] = idx;
                    }



                    // if (area[i - 1][j - 1] != 0) {
                    //     bool check = true;
                    //     int ii = 0;
                    //     for (ii = 0; ii <= area[i - 1][j - 1] && check; ii++) {
                    //         check = field[i - ii][j] == 1 && field[i][j - ii] == 1;
                    //     }

                    //     if (check == true) {
                    //         area[i][j] = ii + 1;
                    //         if (maxval < area[i][j])
                    //             maxval = area[i][j];
                    //     }
                    // }
                }

                if (maxval < area[i][j])
                    maxval = area[i][j];
            }
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << area[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    cout << maxval * maxval << endl;



    return 0;
}