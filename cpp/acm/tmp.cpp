#include <cstdio>
#include <set>
#include <map>
#include <string>
#include <functional>
#include <iostream>
using namespace std;

int main() {
    set<int, greater<int> > s;
    map<int, string, less<int> > m;

    // --- set example
    s.insert(4), s.insert(99), s.insert(0);
    s.insert(24), s.insert(9), s.insert(10);
    auto s_iter = s.find(4);
    if (s_iter != s.end()) s.erase(s_iter);
    s.erase(s.find(0));
    for (const auto &i : s) printf("%d ", i);puts("");
    cout << "lower bound of 11 : " << *(s.lower_bound(11)) << endl;
    cout << "upper bound of 11 : " << *(s.upper_bound(11)) << endl;

    // // --- map example
    // m.insert(make_pair(6, "six")), m.insert(make_pair(5, "five"));
    // m.emplace(1, "one"), m.emplace(2, "two"), m.emplace(10, "ten");
    // m[3] = "three", m[4] = "four";
    // m.erase(4);
    // for (const auto &i : m) printf("%d: %s, ", i.first, i.second.c_str());puts("");
    // cout << "lower bound of 4 : " << (*m.lower_bound(4)).second << endl;

    return 0;
}