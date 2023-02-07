#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;
int arr1[300000];
int arr2[300000];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr1[i];

    bool flag = arr1[0] < arr1[N-1];
    int s = flag ? 1 : 0, e = flag ? N-2 : N-1;



    return 0;
}