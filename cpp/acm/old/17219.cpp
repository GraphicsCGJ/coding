#include<iostream>
#include <string>
#include <set>

using namespace std;


class c1 {
public:
    string url;
    string passwd;
    c1(string url, string passwd) {
        this->url = url;
        this->passwd = passwd;
    }
};

bool operator< (const c1& a, const c1& b) {
    return a.url < b.url;
}

int N, M;
set<c1> s1;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M ;

    for (int i = 0; i < N; i++) {
        string s;
        string s2;
        cin >> s >> s2;
        c1 cc(s, s2);
        s1.insert(cc);
    }

    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        c1 c1_i(s, "");

        auto it = s1.find(c1_i);
        cout << it->passwd << "\n";
    }

    // for (auto & cc : s1) {
    //     cout << cc.url << "\n";
    // }





    return 0;
}