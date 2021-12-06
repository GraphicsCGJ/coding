#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> vowelsVector;

bool check(vector<char> v) {

    int consonants = 0;
    int vowels = 0;
    for (const auto& i : v) {
        if (find(vowelsVector.begin(), vowelsVector.end(), i) != vowelsVector.end())
            vowels++;
        else
            consonants++;
    }

    // cout << consonants << " , " << vowels << endl;

    if (consonants >= 2 && vowels >= 1)
        return true;
    return false;
}

bool cmp (char a, char b) {
    return a < b;
}

void backtracking(vector<char> &v, vector<char> &v2, int i, int n) {
    // for (const char& c : v2) {
    //     cout << c;
    // }
    // cout << endl;

    if (v.size() - i < n - v2.size())
        return;
    if (v2.size() == n) {
        if (check(v2)) {
            for (const char& c : v2) {
                cout << c;
            }
            cout << endl;
        }
        return;
    }
    if (i == v.size())
        return;


    if (v2.size() < n) { // can insert
        v2.push_back(v[i]);
        backtracking(v, v2, i+1, n);
        v2.pop_back();
        backtracking(v, v2, i+1, n);
    }
}

int main(void) {
    int l, c;
    cin >> l >> c;

    vowelsVector.push_back('a');
    vowelsVector.push_back('e');
    vowelsVector.push_back('i');
    vowelsVector.push_back('o');
    vowelsVector.push_back('u');

    vector<char> v;
    for (int i = 0; i < c; i++) {
        char tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i <= v.size() - l; i++) {
        vector<char> v_tmp;
        v_tmp.push_back(v[i]);

        backtracking(v, v_tmp, i+1, l);
    }

    return 0;
}