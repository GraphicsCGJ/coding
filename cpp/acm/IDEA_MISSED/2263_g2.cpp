#include <iostream>
#include <algorithm>

using namespace std;

int N;
int pre[100001];
int in[100001];
int post[100001];

void dfs(int s, int e, int s2, int e2) {
    if (s > e) return;
    int root = post[e];
    // cout << s << ' '<< e << ' '<< s2 << ' '<< e2 <<'\n';
    cout << root << ' ';

    if (s == e) return;
    int loc = (&in[0] - find(in, in + N, root)) / sizeof(int*);
    int m = s2 + (find(in, in + N, root) - &in[s2]); // inorder's loc.
    dfs( s, s + (m-s2-1), s2, m-1);
    dfs( s + (m-s2), e - 1, m+1, e2);
}

int main(void) {

    cin >> N;

    for (int i = 0; i < N; i++) cin >> in[i];
    for (int i = 0; i < N; i++) cin >> post[i];


    dfs(0, N-1, 0, N-1); cout << '\n';


    return 0;
}