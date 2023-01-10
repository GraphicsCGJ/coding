#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define MX 9999999

int V, E;
int S;

typedef pair<int, int> P1;

vector<vector<P1>> edges;
priority_queue<P1> pq;
// priority_queue <P1, vector<P1>, less<P1>> pq;

int dst[20000];
bool visited[20000];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> V >> E;
    cin >> S;
    S--;

    edges.resize(V, vector<P1>());
    fill(dst, dst + V, MX);
    fill(visited, visited + V, false);

    for (int i = 0; i < E; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;

        edges[a].push_back(P1(b, w));
        // edges[b].push_back(P1(a, w));
    }

    dst[S] = 0;
    pq.push(P1(0, S));

    while (!pq.empty()) {
        P1 p = pq.top();
        pq.pop();
        int cur = p.second;

        if (visited[cur] == true)
            continue;
        visited[cur] = true;


        // cout << cur << '\n';
        for (auto &e : edges[cur]) {
            int &nxt = e.first;
            int &weight = e.second;

            if (dst[nxt] > dst[cur] + weight) {
                dst[nxt] = dst[cur] + weight;
                pq.push(P1(-dst[nxt], nxt));
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (dst[i] < MX) {
            cout << dst[i] << '\n';
        }
        else {
            cout << "INF\n";
        }
    }

    return 0;
}