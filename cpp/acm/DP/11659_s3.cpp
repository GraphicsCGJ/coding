#include<iostream>
#include<vector>

using namespace std;

int N, M;
vector<int> v1;
int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    v1.push_back(0);
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v1.push_back(tmp + v1[i]);
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        cout << v1[b] - v1[a - 1] << "\n";
    }

    return 0;
}