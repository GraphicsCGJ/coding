#include <iostream>
#include <vector>

using namespace std;


int arr[1000000];
int answer;
vector<int> ansvec;
void dfs(int n, int cnt, vector<int>& vec) {
    if (arr[n] > 0 && arr[n] < cnt)
        return;

    arr[n] = cnt;
    if (n == 1) {
        if (answer > cnt) {
            answer = cnt;
            ansvec.clear();
            for (auto& v : vec)
                ansvec.push_back(v);
            return;
        }
    }

    if (cnt > answer)
        return;

    if (n % 3 == 0) {
        vec.push_back(n/3);
        dfs(n / 3, cnt + 1, vec);
        vec.pop_back();
    }
    if (n % 2 == 0) {
        vec.push_back(n/2);
        dfs(n / 2, cnt + 1, vec);
        vec.pop_back();
    }
    if (n > 1) {
        vec.push_back(n-1);
        dfs(n - 1, cnt + 1, vec);
        vec.pop_back();
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    answer = 1000002;
    vector<int> vv;
    vv.push_back(n);
    dfs (n, 0, vv);

    cout << answer << '\n';
    for (auto& v : ansvec)
        cout << v << ' ';
    cout << '\n';
    return 0;
}