#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MX 200000001

int V, E;
typedef pair<int, int> P1;
typedef long long ll;
int t1, t2;

vector<P1> edges[801];

int dst[801];
int dst2[801];
int dst3[801];

bool visited[801];

void dijkstra(int *dst, int start) {
    priority_queue<P1> pq;
    fill(dst, dst + V, MX);
    fill(visited, visited + V, false);

    dst[start] = 0;
    pq.push(P1(0, start));

    while (!pq.empty()) {
        P1 p = pq.top();
        int &cur = p.second;
        int &wgt = p.first;
        // cout << cur << '\n';
        pq.pop();

        if (visited[cur] == true) continue;
        visited[cur] = true;

        wgt = -wgt;
        /* dst refresh */
        for (auto& e : edges[cur]) {
            int& nxt = e.first;
            int& nxt_wgt = e.second;

            if (dst[nxt] > dst[cur] + nxt_wgt) {
                dst[nxt] = dst[cur] + nxt_wgt;
                pq.push(P1(-dst[nxt], nxt));
            }
        }
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> V >> E ;

    for (int i = 0; i < E; i++) {
        int a, b, w;
        cin >> a >> b >> w; a--; b--;

        edges[a].push_back(P1(b, w));
        edges[b].push_back(P1(a, w));
    }

    cin >> t1 >> t2; t1--; t2--;

    dijkstra(dst, 0);
    dijkstra(dst2, t1);
    dijkstra(dst3, t2);

    // for (int i = 1; i <= V; i++) {
    //     cout << i << ":" << dst[i-1] << ' ';
    // }
    // cout << '\n';
    // for (int i = 1; i <= V; i++) {
    //     cout << i << ":" << dst2[i-1] << ' ';
    // }
    // cout << '\n';
    // for (int i = 1; i <= V; i++) {
    //     cout << i << ":" << dst3[i-1] << ' ';
    // }
    // cout << '\n';

    ll route_1 = 0;
    ll route_2 = 0;

    if (dst[V - 1] == MX || dst[t1] == MX || dst[t2] == MX) {
        cout << -1 << '\n';
    }

    else {
        route_1 = dst[t1] + dst2[t2] + dst3[V-1];
        route_2 = dst[t2] + dst3[t1] + dst2[V-1];

        cout << (route_1 > route_2 ? route_2 : route_1) << '\n';
    }

    return 0;
}