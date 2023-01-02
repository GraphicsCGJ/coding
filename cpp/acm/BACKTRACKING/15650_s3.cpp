#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

bool check[8];
int values[8];

bool cmp (bool& a, bool& b) {
    return a > b;
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        check[i] = i < M ? 1 : 0;
        values[i] = i + 1;
    }

    do {
        for (int i = 0; i < N; i++) {
            if (check[i] == 1)
                cout << values[i] << " ";
        }
        cout << endl;
    } while(next_permutation(&check[0], &check[N], cmp));


    return 0;
}