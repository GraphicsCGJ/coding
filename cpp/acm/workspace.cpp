#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> P1;


int N;
P1 arr[100000];

bool cmp (P1& a, P1& b) {
    return a.second == b.second ? a.first < b.first : a.second < b.second;
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;

    sort(arr, arr + N);

    priority_queue<int> pq;
    pq.push(-arr[0].second);

    int sz = 1;
    for (int i = 1; i < N; i++) {
        int e = -pq.top();

        if (e <= arr[i].first)
            pq.pop();
        else
            sz++;

        pq.push(-arr[i].second);
    }

    cout << sz << '\n';
    return 0;
}