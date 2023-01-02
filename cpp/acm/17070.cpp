#include <iostream>

using namespace std;

int N;

class C1 {
public:
    int i1, j1;
    int i2, j2;

    C1() {
        i1 = 0;
        j1 = 0;
        i2 = 0;
        j2 = 0;
    };

    C1(int i1, int j1, int i2, int j2) {
        this->i1 = i1;
        this->j1 = j1;
        this->i2 = i2;
        this->j2 = j2;
    }
};

int field[16][16];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> field[i][j];
        }
    }

    C1 pipe(0, 0, 0, 1);


    while (pipe.i2 != N - 1 || pipe.j2 != N - 1) {

    }


    return 0;
}