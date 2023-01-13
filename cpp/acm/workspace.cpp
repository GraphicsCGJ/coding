#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

typedef pair<int, int> P1;

bool visited[100001];
vector<P1> edge[100001];

int global_diff;

int dfs(int cur, int depth) {
    visited[cur] = true;
    int mx_depth = 0;
    int mx_depth2 = 0;

    for (auto& e : edge[cur]) {
        int &nxt = e.first;
        int &wgt = e.second;

        if (visited[nxt]) continue;

        int lcl_depth = dfs(nxt, depth + wgt) + wgt;

        if (mx_depth <= lcl_depth) {
            mx_depth2 = mx_depth;
            mx_depth = lcl_depth;
        }

        else if (mx_depth2 <= lcl_depth) {
            mx_depth2 = lcl_depth;
        }
    }

    if (mx_depth2 > 0) {
        if (mx_depth + mx_depth2 > global_diff)
            global_diff = mx_depth + mx_depth2;
    }

    if (mx_depth + depth > global_diff)
        global_diff = mx_depth + depth;


    return mx_depth;
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int a, b, w;

        cin >> a >> b >> w;
        a--; b--;

        edge[a].push_back(P1(b, w));
        edge[b].push_back(P1(a, w));
    }

    dfs(0, 0);
    cout << global_diff;
    return 0;
}