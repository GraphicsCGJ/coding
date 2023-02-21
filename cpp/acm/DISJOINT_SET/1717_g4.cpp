#include <iostream>

using namespace std;

int parent[1000001];
int N, M;


int find_root(int x) {
    if (x == parent[x]) return x;

    // path compression.
    // all node in same tree have the same parent
    return parent[x] = find_root(parent[x]);
}



/* Union Function */
void union_root(int x, int y) {
    x = find_root(x);
    y = find_root(y);

    if (x!=y) {
        parent[x] = y;
    }
}

bool same_group(int x, int y) {
    return find_root(x) == find_root(y);
}


int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i <= N; i++)
        parent[i] = i;
    for (int i = 0; i < M; i++) {
        int tmp, a, b;
        cin >> tmp >> a >> b;

        if (tmp == 0)
            union_root(a, b);
        else
            cout << (same_group(a, b) ? "YES\n" : "NO\n");
    }

    return 0;
}