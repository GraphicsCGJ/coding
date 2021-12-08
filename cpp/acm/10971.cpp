#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;
#define MAX_VAL 10
#define MAX_W_VAL 1000000

int n;
int min_val;
int w[MAX_VAL][MAX_VAL];
bool visited[MAX_VAL];

vector<int> bt_vector;

bool check (int target) {
    if (w[bt_vector.back()][target] == 0 || visited[target])
        return false;
    return true;
}

void backtracking(int si) {

    stack<int> s;
    s.push(si);

    while(!s.empty()) {
        int sv = s.top();
        s.pop();

        if (sv == -1) {
            visited[bt_vector.back()] = false;
            bt_vector.pop_back();
            continue;
        }

        bt_vector.push_back(sv);
        visited[bt_vector.back()] = true;

        if (bt_vector.size() == n) {
            if (w[bt_vector.back()][bt_vector.front()] != 0) {
                int sum = 0;
                for (int i = 0; i < bt_vector.size() - 1; i++) {
                    // cout << bt_vector[i] << "->" << bt_vector[i+1] << ", ";
                    sum += w[bt_vector[i]][bt_vector[i + 1]];
                }
                sum += w[bt_vector.back()][bt_vector.front()];

                // cout << sum << endl;

                if (sum < min_val) min_val = sum;
            }

            visited[bt_vector.back()] = false;
            bt_vector.pop_back();
            continue;
        }

        s.push(-1);
        for (int i = 0; i < n; i++) {
            if (!check(i))
                continue;
            s.push(i);
        }
    }
}

int main(void) {
    min_val = MAX_W_VAL * MAX_VAL * MAX_VAL + 1;
    bt_vector.reserve(MAX_VAL * MAX_VAL);
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        memset(visited, false, sizeof(visited));
        backtracking(i);
    }

    cout << min_val << endl;

    return 0;
}