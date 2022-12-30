#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


int N;

int arr[1000000];

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int maxVal = 0;
    int size = 0;
    vector<int> vec1;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++) {
        // int res = bsearch(arr2, size, arr[i]);
        int idx = lower_bound(vec1.begin(), vec1.end() ,arr[i]) - vec1.begin();

        if (res == size)
            arr2[size++] = arr[i];
        else
            arr2[res] = arr[i];
    }

    cout << size << endl;

    return 0;
}