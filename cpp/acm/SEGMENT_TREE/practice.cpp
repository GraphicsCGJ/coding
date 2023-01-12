#include <iostream>

using namespace std;

int arr[1000];
int segtr[2000];

int N;

int segtrInitialize(int s, int e, int node) {
    if (s == e) return segtr[node] = arr[s];

    int mid = (s + e) / 2;

    return segtr[node] = segtrInitialize(s, mid, node * 2 + 1) + segtrInitialize(mid + 1, e, node * 2 + 2);
}

int segtrSum(int s, int e, int ql, int qr, int node) {
    // segtre 0 1 2 3 4 5 6 7 ..
    //        ^ ^     ^ ^
    //        l s     e r
    // s, e have to contain part of [l, r].
    if (ql > e || qr < s) return 0;

    // [s, e] is fully occupied by [ql, qr], then return.
    if (ql <= s && qr >= e) return segtr[node];


    int mid = (s + e) / 2;
    return segtrSum(s, mid, ql, qr, node * 2 + 1) + segtrSum(mid + 1, e, ql, qr, node * 2 + 2);
}

void segtrUpdate(int s, int e, int node, int idx, int diff) {
    if (idx < s || idx > e) return;

    segtr[node] += diff;

    if (s == e) return;
    int mid = (s + e) / 2;

    segtrUpdate(s, mid, node * 2 + 1, idx, diff);
    segtrUpdate(mid + 1, e, node * 2 + 2, idx, diff);
}

int main(void) {

    cin >> N;
    int SN = 2 * N - 1;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    segtrInitialize(0, N, 0);
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < SN; i++) {
        cout << segtr[i] << ' ';
    }
    cout << '\n';


    return 0;
}