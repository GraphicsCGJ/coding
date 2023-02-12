#include<iostream>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

int N, M;
int S, E;
#define MX 1000000001


typedef pair<int, int> P1;
vector<vector<P1>> edges;
priority_queue<P1> pq;

int dst[1000];
int pre[1000];
bool visited[1000];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M;

    fill(visited, visited + N, false);
    fill(dst, dst + N, MX);
    fill(pre, pre + N, -1);


    edges.resize(N, vector<P1>());

    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w; a--; b--;
        edges[a].emplace_back(b, w);
    }

    cin >> S >> E; S--; E--;

    dst[S] = 0;
    pq.emplace(0, S);

    while (!pq.empty()) {
        P1 p = pq.top();
        pq.pop();
        int cur = p.second;

        if (visited[cur])
            continue;
        visited[cur] = true;

        for (auto &e : edges[cur]) {
            int &nxt = e.first;
            int &weight = e.second;

            if (dst[nxt] > dst[cur] + weight) {
                dst[nxt] = dst[cur] + weight;
                pre[nxt] = cur;
                pq.push(P1(-dst[nxt], nxt));
            }
        }
    }

    cout << dst[E] << '\n';

    int tmp = E;
    vector<int> vec;
    while (tmp != -1) {
        vec.push_back(tmp);
        tmp = pre[tmp];
    }

    cout << vec.size() << '\n';

    for (auto iter = vec.rbegin(); iter != vec.rend(); iter++) {
        cout << *iter + 1 << ' ';
    }cout << '\n';

    return 0;
}
