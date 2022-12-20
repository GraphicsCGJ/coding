/* Combination */

/* Large Integer Addition */


#include <iostream>
#include <vector>

using namespace std;

vector<int> memoization[101][101];

void print_vec(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[vec.size() - 1 - i];
    }
    cout << endl;
}

vector<int> string_add(vector<int>& a, vector<int>& b) {
    vector<int> *longvec, *shortvec;
    vector<int> ret;
    if (a.size() > b.size()) {
        longvec = &a;
        shortvec = &b;
    }
    else {
        longvec = &b;
        shortvec = &a;
    }

    for (int i = 0; i < shortvec->size(); i++) {
        ret.push_back((*longvec)[i] + (*shortvec)[i]);
    }
    for (int i = 0; i < longvec->size() - shortvec->size(); i++) {
        ret.push_back((*longvec)[shortvec->size() + i]);
    }

    for (int i = 0; i < ret.size(); i++) {
        if (ret[i] >= 10) {
            int mok = ret[i] / 10;
            ret[i] %= 10;

            if (i + 1 < ret.size())
                ret[i + 1] += mok;
            else {
                ret.push_back(mok);
            }
        }
    }

    return ret;
}

int main(void) {

    for (int i = 1; i < 101; i++) {
        for (int j = 0; j < (i / 2) + 1; j++) {
            // cout << i << " : " << j << endl;
            vector<int>& vec = memoization[i][j];
            if (j == 0)
                vec.push_back(1);
            else {

                // cout << "\t" << (i - 1) << ":" << (j > (i - 1) / 2 ? i - 1 - j : j) << endl;
                // cout << "\t" << (i - 1) << ":" << (j - 1 > (i - 1) / 2 ? i - 1 - (j - 1) : j - 1) << endl;
                vec = string_add(memoization[i - 1][j > (i - 1) / 2 ? i - 1 - j : j],
                                memoization[i - 1][j - 1 > (i - 1) / 2 ? i - 1 - (j - 1) : j - 1]);

                // cout << "size: " << vec.size() << endl;;
                // cout << "value: ";
                // print_vec(vec);
            }
        }
    }

    int n, m;
    cin >> n >> m;

    if (n - m < m)
        m = n - m;

    print_vec(memoization[n][m]);

    return 0;
}