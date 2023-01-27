#include <iostream>
#include <algorithm>
// #include <set>
#include <map>

using namespace std;

int N, M;

int aN[50];

int main(void) {

    // multiset<int> s1;
    map<int, int> m1;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> aN[i];

    cin >> M;
    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        if (m1.find(tmp) != m1.end()) {
            m1.find(tmp)->second++;
        }
        else {
            m1.emplace(tmp, 1);
        }
    }

    sort(aN, aN + N);
    if (m1.rbegin()->first > aN[N-1]) {
        cout << -1 << '\n';
        return 0;
    }

    int time = 0;
    while(!m1.empty()) {
        for (int i = N-1; i >= 0; i--) {
            auto p = m1.lower_bound(aN[i]);
            if (p->first == aN[i]) {
                p->second--;
                if (p->second == 0)
                    m1.erase(p);
            }
            else {
                if (m1.empty())
                    break;
                if (p == m1.begin())
                    continue;
                p--;

                p->second--;
                if (p->second == 0)
                    m1.erase(p);
            }
        }

        time++;
    }

    cout << time << '\n';
    return 0;
}

