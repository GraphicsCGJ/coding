#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

typedef long long ll;
vector<ll> vec;

void dfs(int depth, ll num) {
    if (depth > 10) return;

    vec.push_back(num);

    for (int i = 0; i < num % 10; i++) {
        dfs(depth + 1, num * 10 + i);
    }
}

int main(void) {
    cin >> N;
    N--;
    for (int i = 0; i < 10; i++) {
        dfs(1, i);
    }

    sort(vec.begin(), vec.end());

    // for (int i = 0; i < vec.size(); i++) {
    //     cout << i << ": " << vec[i] << endl;
    // }
    if (N < 0 || N >= vec.size())
        cout << -1 << endl;
    else
        cout << vec[N] << endl;
    return 0;
}