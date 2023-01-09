#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int, ll> P;
typedef pair<ll, int> P2;

#define MX -1

int N, M;
ll dst[100001];
int pre[100001];
bool visited[100001];

// vector<map<int, int>> edges;
vector<vector<P>> edges;

int main(void) {
    priority_queue<P2> pq;

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    // edges.resize(N, map<int, int>());
    edges.resize(N, vector<P>());
    fill(dst, dst + N, MX);
    for (int i = 0; i < M; i++) {
        int a, b, w;

        cin >> a >> b >> w;
        a--; b--;

        // edges[a].emplace(b, w);
        // edges[b].emplace(a, w);
        edges[a].push_back(P(b, w));
        edges[b].push_back(P(a, w));
    }
    int cur = 0;
    dst[cur] = 0;
    pre[cur] = -1;
    pq.push(P2(0, cur));
    while (!pq.empty()) {

        P2 p2 = pq.top();
        pq.pop();
        cur = p2.second;

        // cout << cur << '\n';
        if (visited[cur] == true)
            continue;
        visited[cur] = true;


        for (auto b : edges[cur]) {
            if (dst[b.first] == -1 || dst[b.first] > dst[cur] + b.second) {
                dst[b.first] = dst[cur] + b.second;
                pre[b.first] = cur;
                pq.push(P2(-dst[b.first], b.first));
            }
        }
    }

    // string s = "";
    int ans[100001];
    int ai = 0;

    if (dst[N-1] != -1) {
        ans[ai++] = N;
        int tmp = N - 1;
        while (pre[tmp] != -1) {
            ans[ai++] = pre[tmp] + 1;
            tmp = pre[tmp];
        }

        for (int i = ai - 1; i >= 0; i--) {
            cout <<ans[i] << ' ';
        }
        cout << '\n';
        // s = to_string(N);
        // int tmp = N - 1;
        // while (pre[tmp] != -1) {
        //     s = to_string(pre[tmp] + 1) + " " + s;
        //     tmp = pre[tmp];
        // }
        // cout << s << '\n';
    }
    else
        cout << -1 << '\n';

    return 0;
}

