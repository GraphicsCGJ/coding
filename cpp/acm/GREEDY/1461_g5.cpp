#include <iostream>
#include <algorithm>

using namespace std;

int N, N1, N2;
int i1, i2;
int M;

int arr1[50];
int arr2[50];
int hand[50];
int hsz;

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (tmp < 0)
            arr1[N1++] = -tmp;
        else
            arr2[N2++] = tmp;
    }

    sort(arr1, arr1 + N1, greater<int>());
    sort(arr2, arr2 + N2, greater<int>());

    int result = 0;
    while (i1 < N1) {
        result += arr1[i1] * 2;
        i1 += M;
    }

    while (i2 < N2) {
        result += arr2[i2] * 2;
        i2 += M;
    }

    if (N1 > 0 && N2 > 0)
        result -= (arr1[0] < arr2[0] ? arr2[0] : arr1[0]);
    else if (N1 > 0)
        result -= arr1[0];
    else
        result -= arr2[0];

    cout << result << '\n';
    return 0;
}
