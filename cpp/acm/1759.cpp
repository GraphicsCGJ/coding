#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (char a, char b) {
    return a < b;
}

int main(void) {
    int l, c;
    cin >> l >> c;

    vector<char> v;
    for (int i = 0; i < c; i++) {
        char tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), cmp);

    // for (const auto& i : v) {
    //     cout << i << endl;
    // }


    return 0;
}