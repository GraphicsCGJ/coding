#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int *known;
vector<vector<int>> party;

void calc (int cnt) {
    for (int i = 0; i < m; i++) {
        bool flag = true;
        for (int j = 0; j < party[i].size(); j++) {
            if (known[party[i][j]] == 1) {
                flag = false;
                break;
            }
        }

        if (flag) {
            vector<int> new_known_list;
            for (int j = 0; j < party[i].size(); j++) {

            }
        }
    }
}

int main(void) {

    int known_init = 0;
    cin >> n >> m;
    cin >> known_init;

    known = new int[n + 1];

    for (int i = 0; i < known_init; i++) {
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


    return 0;
}