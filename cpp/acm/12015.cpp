#include <iostream>
#include <cstring>

using namespace std;


int N;

int arr[1000000];
int arr2[1000000];

int bsearch(int *arr2, int& size, int& value) {
    int l = 0, r = size - 1;

    while (l <= r) {
        int m = (l + r) * (0.5);

        if (value > arr2[m]) {
            l = m + 1;
        }
        else if (value < arr2[m]) {
            r = m - 1;
        }
        else
            return m;
    }

    return
}

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int maxVal = 0;
    int size = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    memset(arr2, 0x00, 1000000);


    for (int i = 0; i < N; i++) {
        int res = bsearch(arr2, size, arr[i]);

    }

    cout << maxVal << endl;

    return 0;
}