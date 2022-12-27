// cin.tie(NULL)과 ios::sync_with_stdio(false)

#include<iostream>
#include<string>
#include<vector>

using namespace std;

string s1, s2;


class lcs_c {
public:
    int len;
    char c;
    lcs_c* exptr;

    lcs_c() {
        len = 0;
        c = 0x00;
        exptr = 0x00;
    };

    void set(int len, char c, lcs_c* exptr) {
        this->len = len;
        this->c = c;
        this->exptr = exptr;
    };

    void set(lcs_c &tmp) {
        this->len = tmp.len;
        this->c = tmp.c;
        this->exptr = tmp.exptr;
    }
};

int main(void) {
    // cin.tie(NULL);
    // ios::sync_with_stdio(false);

    cin >> s1 >> s2;
    vector<vector<lcs_c>> vec(s1.length() + 1, vector<lcs_c>(s2.length() + 1));

    lcs_c biggest;
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            /* matched, +1 from i-1, j-1 and store. */
            if (s1[i - 1] == s2[j - 1]) {
                vec[i][j].set(vec[i-1][j-1].len + 1, s2[j - 1], &vec[i - 1][j - 1]);

                if (biggest.len < vec[i][j].len) {
                    biggest.set(vec[i][j]);
                }
            }

            /* not matched, compare i-1 & j-1, store bigger one. */
            else {
                lcs_c& tmp = (vec[i-1][j].len > vec[i][j-1].len ? vec[i-1][j] : vec[i][j-1]);
                vec[i][j].set(tmp);
            }
        }
    }

    lcs_c* tmp = &biggest;
    string s = "";
    while(tmp != nullptr) {
        s = tmp->c + s;
        tmp = tmp->exptr;
    }

    cout << s << endl;

    return 0;
}