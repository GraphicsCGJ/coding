#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> P1;

int N, sz;
vector<P1> rooms[100000];

P1 arr[100000];

bool cmp(P1& a, P1& b) {
    return a.second == b.second ? a.first < b.first : a.second < b.second;
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // sz = -1;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int n, s, e;
        cin >> n >> s >> e; e--;
        P1 p1(s, e);
        arr[i] = p1;
    }

    sort(arr, arr + N, cmp);

    for (int i = 0; i < N; i++) { // lectures
        P1& p = arr[i];
        cout << p.first << ':' << p.second ;
        int room_number = -1;
        for (int j = 0; j < sz; j++) { // rooms
            bool flag2 = true;
            for (auto& room : rooms[j]) { // lectures in room
                if ((p.first > room.second && p.first > room.second) ||
                    (p.second < room.first && p.second < room.first)) {
                    continue;
                }
                else {
                    flag2 = false;
                    break;
                }
            }

            if (flag2) {
                room_number = j;
                break;
            }
        }
        if (room_number == -1)
            room_number = sz++;
        cout << ' ' << room_number << '\n';
        rooms[room_number].push_back(p);
    }

    cout << sz << '\n';

    return 0;
}