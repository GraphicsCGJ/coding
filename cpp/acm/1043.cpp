#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int *known;
vector<vector<int>> party;

vector<int> getPossibleParty() {
    vector<int> possibleParty;
    for (int veci = 0; veci < party.size(); veci++) { // vec = party[i]
        bool isPossible = true;
        vector<int> &vec = party[veci];
        for (int i = 1; i <= n; i++) {
            if (known[i] == 0) continue;

            if (find(vec.begin(), vec.end(), i) != vec.end()) {
                isPossible = false;
                break;
            }
        }

        if (isPossible == true)
            possibleParty.push_back(veci);
    }

    return possibleParty;
}

int calc (int cnt, vector<int> possibleParty) { // greedy
    /* calc less */
    int lessValue = 51;
    int lessIdx = -1;
    for (int i = 0; i < possibleParty.size(); i++) {
        vector<int> &party_1 = party[i];
        int local_lessValue = 0;

        for (int j = 0; j < possibleParty.size(); j++) {
            vector<int> &party_2 = party[j];
            bool flag = false;

            if (i == j) continue;
            for (int value_1 : party_1) {
                for (int value_2 : party_2) {
                    if (value_1 == value_2) {
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    local_lessValue++;
                    break;
                }
            }
        }

        if (lessValue > local_lessValue && local_lessValue > 0) {
            lessValue = local_lessValue;
            lessIdx = i;
        }
    }

    if (lessIdx == -1) return cnt;

    for (auto &vi : party[lessIdx]) {
        known[vi] = 1;
    }

    return calc(cnt + 1, getPossibleParty());
}

int main(void) {
    int known_cnt;

    cin >> n >> m;
    cin >> known_cnt;

    known = new int[n + 1];

    for (int i = 0; i < known_cnt; i++) {
        int tmp;
        cin >> tmp;
        known[tmp] = 1;
    }

    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        vector<int> vec(tmp, 0);
        for (int j = 0; j < tmp; j++) {
            cin >> vec[j];
        }
        party.push_back(vec);
    }

    vector<int> possibleParty = getPossibleParty();
    for (auto &vi : possibleParty) {
        cout << vi << " ";
        for (auto &vii : party[vi])
            cout << vii << ", ";
        cout << endl;
    }
    int ret = calc(0, possibleParty);

    cout << ret << endl;

    return 0;
}