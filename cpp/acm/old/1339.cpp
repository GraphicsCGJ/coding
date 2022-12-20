#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<cmath>

using namespace std;

int n;
class tmp_c {
    public:
        char c;
        int cnt;
        bool operator==(const tmp_c& b) {
            return this->c == b.c;
        }

        tmp_c(char c, int cnt) {
            this->c = c;
            this->cnt = cnt;
        }
};

bool cmp (const tmp_c& a, const tmp_c& b) {
    return a.cnt > b.cnt;
}
int main(void) {
    string s;
    vector<tmp_c> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;


        int val_1 = 1;
        for (int j = 0; j < s.length(); j++) {
            tmp_c t(s[j], (int)pow(10, s.length() - 1 - j));
            auto it = find(v.begin(), v.end(), t);

            if (it != v.end()) {
                it->cnt += t.cnt;
            }
            else {
                v.push_back(t);
            }
        }
    }

    sort(v.begin(), v.end(), cmp);

    int cnt = 9;
    int sum = 0;
    for (auto &i : v) {
        sum += (i.cnt * (cnt--));
    }

    cout << sum << endl;

    return 0;
}