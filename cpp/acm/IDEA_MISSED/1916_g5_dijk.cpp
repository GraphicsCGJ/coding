#include <iostream>


using namespace std;

typedef long long ll;

int N, M;
int S, E;

ll MX = 10000000000 + 1;
ll bus[1000][1000];
ll dst[1000];
bool visited[1000];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N;
    cin >> M;

    fill(dst, dst + N, MX);
    fill(&bus[0][0], &bus[N-1][N], MX);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;

        if (bus[a][b] > c)
            bus[a][b] = c;
    }

    cin >> S >> E; S--; E--;
    dst[S] = 0;

    while (true) {
        int pos = -1;
        int len = MX;
        for (int i = 0; i < N; i++) {
            if (len >= dst[i] && visited[i] == false) {
                pos = i;
                len = dst[i];
            }
        }
        if (pos < 0)
            break;

        visited[pos] = true;
        for (int i = 0; i < N; i++) {
            if (bus[pos][i] != MX) {
                dst[i] = dst[i] > dst[pos] + bus[pos][i] ? dst[pos] + bus[pos][i] : dst[i];
            }
        }
    }
    cout << dst[E] << '\n';

    return 0;
}