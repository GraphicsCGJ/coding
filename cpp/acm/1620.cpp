#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
vector <string> vec;
unordered_map<string, int> m2;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);	//없으면 시간 초과

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        vec.push_back(s);
        m2.emplace(s, i + 1);
    }

    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        if (s[0] >= '1' && s[0] <= '9') {
            int tmp = stoi(s.c_str());
            cout << vec[tmp - 1] << "\n";
        }
        else {
            auto mi = m2.find(s);
            cout << mi->second << "\n";
        }
    }
    return 0;
}