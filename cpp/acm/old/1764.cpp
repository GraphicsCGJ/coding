#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int  N, M;
set<string> s1;
set<string> s2;

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        s1.insert(s);
    }

    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        if (s1.find(s) != s1.end()) {
            s2.insert(s);
        }
    }

    cout << s2.size() << endl;
    for (auto &s : s2) {
        cout << s << endl;
    }

    return 0;
}