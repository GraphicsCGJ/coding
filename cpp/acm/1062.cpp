#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define ALPHA_CNT 26

int n, k;
int w[ALPHA_CNT];
bool comb[ALPHA_CNT];

// class tmp_c {
//     public:
//         char c;
//         int cnt;
//         bool operator<(const tmp_c& a) {
//             return this->cnt < a.cnt;
//         }

//         tmp_c(char c, int cnt) {
//             this->c = c;
//             this->cnt = cnt;
//         }

// };

// a t i n c
int main(void) {
    cin >> n >> k;
    if (k < 5) {
        cout << 0 << endl;
        return 0;
    }
    k -= 5;
    vector<vector<char>> v;
    vector<char> vi;
    vector<char> vj;
    vector<bool> comb;
    vi.reserve(30);
    vj.reserve(30);

    for (int ii = 0; ii < n; ii++) {
        string s;
        vi.clear();
        cin >> s;

        sort(s.begin(), s.end());
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'c' || s[i] == 'i' || s[i] == 'n' || s[i] == 't')
                continue;
            if (find(vi.begin(), vi.end(), s[i]) == vi.end()) {
                vi.push_back(s[i]);
            }

            if (find(vj.begin(), vj.end(), s[i]) == vj.end()) {
                vj.push_back(s[i]);
            }
        }
        v.push_back(vi);
    }

    // k = vj.size();
    sort(vj.begin(), vj.end());
    k = vj.size() < k ? vj.size() : k;
    /* combination */
    for (int i = 0; i < vj.size(); i++) {
        comb.push_back(i < vj.size() - k ? false : true);
    }
    int max_val = -1;
    do {
        bool check[30];
        memset(check, false, 30);
        for (int i = 0; i < comb.size(); i++) {
            if (comb[i])
                check[vj[i] - 'a'] = true;
        }

        int cnt = 0;
        for (auto& vi : v) {
            bool flag = true;
            for (int i = 0; i < vi.size(); i++) {
                if (check[vi[i] - 'a'] == false) {
                    flag = false;
                    break;
                }
            }

            if (flag) cnt++;
        }

        if (cnt > max_val)
            max_val = cnt;


    } while (next_permutation(comb.begin(), comb.end()));

    cout << max_val << endl;
}