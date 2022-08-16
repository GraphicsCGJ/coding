#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int ascending[1001];
int descending[1001];
int arr[1001];

int N, M = -1;

void dp(int value) {
    int localMax = 0;
    for (int i = value + 1; i <= M; i++) {
        if (ascending[i] > localMax)
            localMax = ascending[i];

        if (descending[i] > localMax)
            localMax = descending[i];
    }
    descending[value] = localMax + 1;

    localMax = 0;
    for (int i = 1; i < value; i++) {
        if (ascending[i] > localMax)
            localMax = ascending[i];
    }
    ascending[value] = localMax + 1;
}

int main(void) {
    memset(ascending, 0x00, sizeof(ascending));
    memset(descending, 0x00, sizeof(descending));
    memset(arr, 0x00, sizeof(arr));

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (M < arr[i])
            M = arr[i];
    }

    for (int i = 0; i < N; i++) {
        dp(arr[i]);
    }

    int maxval = 0;
    for (int i = 1; i <= M; i++) {
        maxval = maxval < ascending[i] ? ascending[i] : maxval;
        maxval = maxval < descending[i] ? descending[i] : maxval;
    }
    cout << maxval << endl;

}
