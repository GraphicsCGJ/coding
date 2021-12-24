#include <iostream>

using namespace std;

#define MAX_VAL 10

int map[MAX_VAL][MAX_VAL];
int cnt[MAX_VAL];
int result;

bool check(int r, int c, int n) {
    if (r + n >= 10 || c + n >= 10 || n <= 0 || cnt[n - 1] <= 0)
        return false;

    if (n == 1) {

    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[r + i][c + j] == 0) return false;
        }
    }

    return true;
}

void flip(int r, int c, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[r + i][c + j] = 1 - map[r + i][c + j];
        }
    }
}

void print() {
    cout << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

bool findNext (int& r, int& c, int& n) {
    while (r < 10 && c < 10 && n > 0 && cnt[n - 1] > 0) {
        // check
        bool flag = true;
        flag = check(r, c, n);

        // if success
        if (flag)
            return true;
        else {
            c++;
            if (c >= 10) {
                r++; c = 0;
                if (r >= 10) {
                    n--;
                    r = 0; c = 0;
                    if (n <= 0)
                        return false;
                }
            }
            continue;
        }
    }

    return false;
}

void bruteforce(int r, int c, int n, int& cnt2) {

    while(!findNext(r, c, n)) {
        // cout << "loop" << endl;
        if (check(r, c, n) == false) return;
    }



    // cout << r << ", " << c << endl;
    // print();

    /* do */
    flip(r, c, n);
    cnt[n - 1] --;
    cnt2++;
    /* check if all map is colored */
    bool flag = true;
    for (int i = 0; i < 10 && flag; i++)
        for (int j = 0; j < 10 && flag; j++)
            flag = (map[i][j] == 1) ? false : flag;

    if (flag) {// all map checked.
        result = (result < 0 ? cnt2 : (result > cnt2 ? cnt2 : result));
        // for (int i =0; i < 5;i++) {
        //     cout << i << " "  << cnt[i] <<endl;
        // }
    }
    else
        bruteforce(r, c + 1, n, cnt2);
    flip(r, c, n);
    cnt[n - 1] ++;
    cnt2--;

    /* or not */
    bruteforce(r, c + 1, n, cnt2);
}

int main(void) {
    result = -1;
    int local_result = 0;

    for (int i = 0; i < MAX_VAL; i++) {
        for (int j = 0; j < MAX_VAL; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < MAX_VAL; i++) {
        cnt[i] = 5;
    }
    bool flag = true;
    for (int i = 0; i < 10 && flag; i++)
        for (int j = 0; j < 10 && flag; j++)
            flag = (map[i][j] == 1) ? false : flag;

    if (flag) {
        cout << 0 << endl;
        return 0;
    }



    bruteforce(0, 0, 5, local_result);

    cout << result << endl;
    for (int i =0; i < 5;i++) {
        cout << i << " "  << cnt[i] <<endl;
    }
    cout << endl;

    return 0;
}