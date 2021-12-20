#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_VAL 11

int map[MAX_VAL][MAX_VAL];
bool visited[MAX_VAL];
bool visited2[MAX_VAL];
int popularity[MAX_VAL];

int result;

int n;

void bruteForce() {

}

void bfs(int s, bool* v) {

    queue<int> q;

    q.push(s);

    while(!q.empty()) {
        int top = q.front();
        v[top] = true;

        q.pop();

        for (int i = 0; i < n; i++) {
            if (map[top][i] == 1 && !v[i]) {
                v[i] = true;
                q.push(i);
            }
        }
    }

}

int main(void) {

    memset(map, 0, sizeof(map));
    memset(popularity, 0, sizeof(popularity));
    result = -1;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> popularity[i];

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++) {
            int tmp;
            cin >> tmp;
            tmp -= 1;
            map[i][tmp] = 1;
            map[tmp][i] = 1;
        }
    }

    /* brute force */
    for (int i = 1; i <= (n / 2) + (n % 2 == 0 ? 0 : 1); i++) {
        vector<bool> comb(n, false);
        for (int j = 0; j < i; j++)
            comb[n - 1 - j] = true;

        do {
            memset(visited, 0, sizeof(visited));
            memset(visited2, 0, sizeof(visited2));

            for (int j = 0; j < n; j++) {
                if (comb[j]) {
                    visited[j] = true;
                    visited2[j] = false;
                }
                else {
                    visited[j] = false;
                    visited2[j] = true;
                }
            }

            /* check dfs or bfs */
            int start;
            bool flag;

            for (start = 0; start < n; start++) {
                if (!visited[start]) break;
            }
            bfs(start, visited);
            flag = true;
            for (int j = 0; j < n; j++) {
                if (!visited[j]) {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                continue;


            for (start = 0; start < n; start++) {
                if (!visited2[start]) break;
            }
            bfs(start, visited2);
            flag = true;
            for (int j = 0; j < n; j++) {
                if (!visited2[j]) {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                continue;

            /* calc diff */
            int sum1 = 0, sum2 = 0;
            int diff;
            for (int j = 0; j < n; j++) {
                if (!comb[j])
                    sum1 += popularity[j];
                else
                    sum2 += popularity[j];
            }
            diff = sum1 >= sum2 ? sum1 - sum2 : sum2 - sum1;

            /* store min val */
            if (result < 0) result = diff;
            else {
                if (result > diff)
                    result = diff;
            }

        } while (next_permutation(comb.begin(), comb.end()));
    }
    /* *** */

    cout << result;

    return 0;
}