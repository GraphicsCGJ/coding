#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MX 200001

typedef pair<int,int> P1;

int N, K;

bool visited[100001];
int pre[100001];
// int cntarr[100001];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;


    queue<P1> q;

    q.push(P1(N,0));
    pre[N] = -1;
    visited[N] = true;

    while (!q.empty()) {
        P1 p = q.front();
        int& cur = p.first;
        int& dist = p.second;
        q.pop();
        // cntarr[cur]++;
        // cout << cur << ':' << cntarr[cur] << '\n';
        if (cur > 100000 || cur < 0) continue;

        if (cur == K) {
            int tmp = cur;
            vector<int> v;
            while (tmp != -1) {
                v.push_back(tmp);
                tmp = pre[tmp];
            }
            cout << dist << '\n';
            for (auto iter = v.rbegin(); iter != v.rend(); iter++)
                cout << *iter << ' ';
            cout << '\n';

            break;
        }

        if (cur * 2 <= 100000 && visited[cur * 2] == false) {
            pre[cur*2] = cur;
            visited[cur*2] = true;
            q.push(P1(cur * 2, dist + 1));
        }
        if (cur + 1 <= 100000 && visited[cur + 1] == false) {
            pre[cur+1] = cur;
            visited[cur + 1] = true;
            q.push(P1(cur + 1, dist + 1));
        }
        if (cur - 1 >= 0 && visited[cur - 1] == false) {
            pre[cur-1] = cur;
            visited[cur - 1] = true;
            q.push(P1(cur - 1, dist + 1));

        }
    }

    return 0;
}