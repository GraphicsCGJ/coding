#include <iostream>
#include <vector>

using namespace std;

int N, M;

int arr[8];

void dfs(vector<int> values, int pos , int level, int levelMax) {
    if (level >= levelMax) {
        for (auto& val : values) {
            cout << val << " ";
        }
        cout << '\n';
        return;
    }
    if (pos >= N) return;

    values.push_back(arr[pos]);
    dfs(values, pos, level + 1, levelMax);
    values.pop_back();
    dfs(values, pos + 1, level, levelMax);
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    vector<int> vec;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    dfs(vector<int>(0), 0, 0, M);

    return 0;
}