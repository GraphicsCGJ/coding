#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int T;
int n;

int main(void) {

    cin >> T;
    string str;


    while (T--) {
        vector<int> vec;
        string tmpstr;
        int s, e;
        bool isReversed = false;

        cin >> str;
        cin >> n;
        vec.reserve(n);
        cin >> tmpstr;

        vector<char> tmpvec;
        for (int i = 0; i < tmpstr.size(); i++) {
            if (tmpstr[i] == '[')
                continue;
            else if (tmpstr[i] == ',' || tmpstr[i] == ']') {
                int tmpint = 0;
                if (tmpvec.size() == 0) continue;
                for (int j = 0; j < tmpvec.size(); j++)
                    tmpint += (int)(pow(10, tmpvec.size() - 1 - j)) * (tmpvec[j] - '0');

                vec.push_back(tmpint);

                tmpvec.clear();
            }
            else {
                tmpvec.push_back(tmpstr[i]);
            }
        }

        s = 0;
        e = vec.size() - 1;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'R')
                isReversed = (isReversed) ? false : true;
            else {
                if (isReversed)
                    e--;
                else
                    s++;
            }
        }

        if (e - s < -1)
            cout << "error" << endl;
        else if (e - s == -1) {
            cout << "[]" << endl;
        }
        else {
            cout << "[";
            if (!isReversed) {
                for (int i = s; i <= e; i++) {
                    if (i == e)
                        cout << vec[i];
                    else
                        cout << vec[i] << ",";
                }
            }
            else {
                for (int i = e; i >= s; i--) {
                    if (i == s)
                        cout << vec[i];
                    else
                        cout << vec[i] << ",";
                }
            }

            cout << "]" << endl;
        }

    }

    return 0;
}