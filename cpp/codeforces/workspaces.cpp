#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, ll> P;

#define MX 100000000001LL

int N, M;
int dst[100001];
int visited[100001];

vector<vector<P>> edges;
int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    fill(dst, dst + N, MX);

    for (int i = 0; i < M; i++) {
        int a, b, w;

        cin >> a >> b >> w;
        a--; b--;
        edges[a].push_back(P(b, w));
        edges[b].push_back(P(a, w));
    }

    int cur = 0;
    dst[cur] = 0;
    visited[cur] = true;

    while (cur >= 0) {
        int nxt = -1;

        for (auto b : edges[cur]) {
            if (dst[b.first] > dst[cur] + b.second)
                dst[b.first] = b.second;
        }

        for ()
    }

    return 0;
}

