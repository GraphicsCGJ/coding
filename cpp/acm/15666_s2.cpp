#include <bits/stdc++.h>

using namespace std;

int N, M;

int arr[8];
int values[8];
vector<int[]> rst2;
int sz1, sz2;

int cmp(int a[], int b[]) {
    bool rt = true;

    for (int i = 0; i < M; i++) {
        if (a[i] == b[i]) continue;
        return (a[i] < b[i] ? 1 : -1);
    }

    return 0;
}

bool bsearch(int target[]) {
    int l = 0;
    int r = sz2 - 1;
    while (l <= r)  {
        int m = (l + r);
        m *= 0.5;

        int tmp = cmp(rst2[m], target);
        if (tmp == 0) return true;
        else if (tmp < 0) r = m - 1;
        else l = m + 1;
    }

    return false;
}

void dfs(int pos) {
    if (sz1 == M) {

        if (bsearch(values))
            return;

        int tmp[8];
        rst2.push_back(tmp);
        for (int i = 0; i < sz1; i++) {
            cout << values[i]<< " ";
            rst2[sz2][i] = values[i];
        }
        sz2++;
        cout << '\n';
        return;
    }
    if (pos >= N) return;


    values[sz1++] = arr[pos];
    dfs(pos);
    sz1--;
    dfs(pos + 1);
}

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    sz1 = 0; sz2 = 0;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    dfs(0);
    return 0;
}