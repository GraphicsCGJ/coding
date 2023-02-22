#include <iostream>
#include <algorithm>

using namespace std;



int N, M;
int arr[100000];

int diff = 1000000000 * 2 + 1;
int ans1, ans2;

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N ;
    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr + N);
    int pa = 0, pb = N-1;

    while (pb > pa) {
        int local_diff = arr[pb] + arr[pa];
        int abs_diff = local_diff < 0 ? -local_diff : local_diff;

        if (abs_diff < diff) {
            ans1 = pa; ans2 = pb;
            diff = abs_diff;
        }
        if (local_diff > 0) pb--;
        else pa++;
    }

    cout << arr[ans1] << ' ' << arr[ans2] << '\n';



    return 0;
}