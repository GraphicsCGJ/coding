#include <iostream>
#include <string>

using namespace std;

int N;
bool b1[100000];
bool b1_2[100000];
bool b2[100000];

inline bool rangecmp(const int &l, const int &r) {
    for (int i = l; i <= r; i++)
        if (b1[i] != b2[i]) return false;
    return true;
}

inline void exchange(const int &l, const int &r) {
    for (int i = l; i <= r; i++) {
        b1[i] = 1 - b1[i];
    }
}

inline bool cmp (const int &idx, const int &factor) {
    if (b1[idx-factor] == b2[idx-factor]) {
        return true;
    }
    else {
        return false;
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int cnt = 0, ans = -1;
    cin >> N;

    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 0; i < N; i++)
        b1[i] = b1_2[i] = s1[i] == '1';
    for (int i = 0; i < N; i++)
        b2[i] = s2[i] == '1';

    for(int ii = 0; ii < 2; ii++) {
        cnt = 0;
        if (ii == 1) {
            for (int i = 0; i < N; i++) b1[i] = b1_2[i];
            b1[0] = 1 - b1[0];
            b1[1] = 1 - b1[1];
            cnt ++ ;
        }

        for (int i = 1; i < N; i++) {
            if (cmp(i, 1) == false) {
                cnt++;
                if (i == N-1)
                    exchange(i-1, i);
                else
                    exchange(i-1, i + 1);

            }
        }

        if (rangecmp(0, N-1) ==false)
            cnt = -1;

        if (ii == 0)
            ans = cnt;
        else
            ans = (ans == -1 ? cnt : cnt == -1 ? ans : ans < cnt ? ans : cnt);
    }

    cout << ans << '\n';

    return 0;
}
