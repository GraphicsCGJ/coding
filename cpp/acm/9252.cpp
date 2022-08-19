#include <iostream>
#include <string>
#include <vector>

using namespace std;

class lcs_c {
    public:
        int length;
        char c;
        lcs_c *exptr;
};

int main(void) {
    string a;
    string b;

    cin >> a >> b;

    vector<vector<lcs_c>> vec(a.length() + 1, vector<lcs_c>(b.length() + 1));
    for (int i = 0; i <= a.length(); i++) {
        for (int j = 0; j <= b.length(); j++) {
            vec[i][j].length = 0;
            vec[i][j].c = 0x00;
            vec[i][j].exptr = 0x00;
        }
    }

    lcs_c maxval;
    maxval.length = 0;

    // cout << a << endl << b << endl;
    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i - 1] != b[j - 1]) {
                lcs_c *tmpval = &vec[i - 1][j];
                if (tmpval->length < vec[i][j - 1].length)
                    tmpval = &vec[i][j - 1];
                vec[i][j].length = tmpval->length;
                vec[i][j].c = tmpval->c;
                vec[i][j].exptr = tmpval->exptr;
            }
            else {
                vec[i][j].length = vec[i - 1][j - 1].length + 1;
                vec[i][j].c = a[i - 1];
                vec[i][j].exptr = &vec[i - 1][j - 1];

                if (maxval.length < vec[i][j].length) {
                    maxval.length = vec[i][j].length;
                    maxval.c = vec[i][j].c;
                    maxval.exptr = vec[i][j].exptr;
                }
            }
        }
    }

    cout << maxval.length << endl;
    if (maxval.length == 0)
        return 0;

    lcs_c *ptr = &maxval;
    string resultString = "";

    while (ptr->c != 0x00) {
        resultString = ptr->c + resultString;
        ptr = ptr->exptr;
    }

    cout << resultString << endl;

    return 0;
}