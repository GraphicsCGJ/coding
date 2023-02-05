#include <iostream>
#include <deque>

using namespace std;

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deque<char> dq;

    string s1, s2;
    bool isReverse = false;

    cin >> s1 >> s2;
    for (int i = 0; i < s2.length(); i++)
        dq.push_back(s2[i]);
    int tmp = s2.length() - s1.length();

    while (tmp--) {
        if (isReverse) {
            auto iter = dq.rend();
            iter--;
            dq.pop_front();
            if (*iter == 'B')
                isReverse = false;
        }
        else {
            auto iter = dq.end();
            iter--;
            dq.pop_back();
            if (*iter == 'B')
                isReverse = true;
        }
    }

    for (int i = 0; i < s1.length(); i++) {
        if (isReverse) {
            if (dq[dq.size() - 1 - i] != s1[i]) {
                cout << 0 << '\n';
                return 0;
            }
        }
        else {
            if (dq[i] != s1[i]) {
                cout << 0 << '\n';
                return 0;
            }
        }
    }

    cout << 1 << '\n';
    return 0;
}
