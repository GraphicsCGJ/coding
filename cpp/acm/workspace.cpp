#include<iostream>
#include<set>

using namespace std;
int N;

int field[20][20];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);


    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> field[i][j];
            if (i != 0) field[i][j] += field[i-1][j];
        }
    }

    set<int> ss[20];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0) {

            }
        }
    }

    return 0;
}
