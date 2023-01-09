#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MX 200000
vector<vector<int>> tree;

bool isCat[MX];
bool isLeaf[MX];
int N,M;

void dfs(int pos, int prev, int catCnt, int &cnt) {
    catCnt = isCat[pos] == 1 ? catCnt + 1 : 0;
    if (catCnt > M) {
        return;
    }

    if (isLeaf[pos]) {
        cnt++;
        return;
    }

    for (auto& nxt : tree[pos]) {
        if (nxt == prev) continue;
        dfs(nxt, pos, catCnt, cnt);
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    tree.resize(N, vector<int>());
    fill(isLeaf, isLeaf + N, true);
    for (int i = 0; i < N; i++) {
        cin >> isCat[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        tree[a].push_back(b);
        tree[b].push_back(a);
        if (isLeaf[a] && tree[a].size() > 1) isLeaf[a] = false;
        if (isLeaf[b] && tree[b].size() > 1) isLeaf[b] = false;
    }
    isLeaf[0] = false;

    int cnt = 0;
    int catCnt = 0;
    dfs(0, -1, catCnt, cnt);
    cout << cnt << '\n';

    return 0;
}

