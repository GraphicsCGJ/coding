#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
#define MX 199999999
typedef pair<int,int> P1;

int N, M, T;
int S, G, H;

int dst1[2000];
int dst2[2000];
int dst3[2000];
bool visited[2000];

vector<int> endList;
vector<vector<P1>> edges;

void dijkstra(int dst[], int S) {
    fill(dst, dst + N, MX);
    fill(visited, visited + N, false);

    dst[S] = 0;
    priority_queue<P1> pq;
    pq.emplace(0, S);
    while (!pq.empty()) {
        P1 p = pq.top();
        int curwgt = p.first;
        int cur = p.second;
        pq.pop();

        if (visited[cur])
            continue;
        visited[cur] = true;

        for (auto& e : edges[cur]) {
            if (dst[e.first] > dst[cur] + e.second) {
                dst[e.first] = dst[cur] + e.second;
                pq.emplace(-dst[e.first], e.first);
            }
        }
    }
}

void sol() {
    cin >> N >> M >> T;
    cin >> S >> G >> H; S--; G--; H--;

    edges.clear();
    edges.resize(N, vector<P1>());
    endList.resize(T,0);

    int gh;
    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b>>w;a--;b--;
        edges[a].push_back(P1(b,w));
        edges[b].push_back(P1(a,w));

        if ((a == G && b == H) || (a == H && b == G))
            gh = w;
    }

    for (int i = 0; i < T; i++) {
        cin >> endList[i];
        endList[i]--;
    }

    sort(endList.begin(), endList.end());

    dijkstra(dst1, S);
    dijkstra(dst2, G);
    dijkstra(dst3, H);

    for (auto tgt : endList) {
        if ((dst1[tgt] >= dst1[G] + dst3[tgt] + gh) || (dst1[tgt] >= dst1[H] + dst2[tgt] + gh))
            cout << tgt + 1 << ' ';
    }
    cout << '\n';
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int TC;
    cin >> TC;

    while (TC--)
        sol();

    return 0;
}
