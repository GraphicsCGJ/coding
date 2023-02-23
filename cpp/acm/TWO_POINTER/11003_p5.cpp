#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, L;
int arr[5000000];
int res[5000000];

typedef pair<int,int> P1;
priority_queue<P1> pq;

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> L;
    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int i = 0; i < N; i++) {
        int r = i;
        int l = r - L;

        pq.push(P1(-arr[r], r));

        while (!pq.empty()) {
            P1 p1 = pq.top();
            if (p1.second <= l) pq.pop();
            else break;
        }

        res[r] = -pq.top().first;
    }

    for (int i = 0; i < N; i++) cout << res[i] << ' ';
    cout << '\n';
    return 0;
}








// #include <iostream>
// #include <algorithm>
// #include <map>

// using namespace std;

// int N, L;
// int arr[5000000];
// int res[5000000];

// map<int,int> mp;

// int main(void) {
//     cin.tie(0);
//     cout.tie(0);
//     ios_base::sync_with_stdio(0);

//     cin >> N >> L;
//     for (int i = 0; i < N; i++) cin >> arr[i];

//     for (int i = 0; i < N; i++) {
//         int r = i;
//         int l = r - L;

//         if (l >= 0) {
//             auto iter = mp.find(arr[l]);
//             if (iter != mp.end()) {
//                 iter->second--;
//                 if (iter->second == 0)
//                     mp.erase(iter);
//             }
//         }

//         auto iter = mp.find(arr[r]);
//         if (iter != mp.end())
//             iter->second++;
//         else
//             mp.emplace(arr[r], 1);

//         // cout << mp.lower_bound(-1000000000)->first << ' ' << mp.lower_bound(-1000000000)->second << '\n';
//         res[r] = mp.lower_bound(-1000000000)->first;

//     }

//     for (int i = 0; i < N; i++) cout << res[i] << ' ';
//     cout << '\n';
//     return 0;
// }