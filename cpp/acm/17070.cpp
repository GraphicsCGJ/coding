#include <iostream>
#include <queue>

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
C1 pipes[16 * 16 * 3];
int size = 0;

bool equal(C1& a, C1& b) {
    return a.i1 == b.i1 && a.j1 == b.j1 && a.i2 == b.i2 && a.j2 == b.j2;
}

bool cmp(C1& a, C1& b) {
    return  a.i1 == b.i1 ?
                a.j1 == b.j1 ?
                    a.i2 == b.i2 ?
                        a.i2 < b.j2 :
                        a.i2 < b.i2
                    :
                    a.j1 < b.j1
                :
                a.i1 < b.i1;
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> field[i][j];
        }
    }

    C1 start(0, 0, 0, 1);
    queue<C1> q;
    q.push(start);

    while (!q.empty()) {
        C1 pipe = q.front();
        q.pop();

        if (pipe.i1 == pipe.i2) {
            C1 pipe2(pipe.i1 + 1, pipe.j1 + 1, pipe.i2 + 1, pipe.j2 + 1);
            auto iter = lower_bound(&pipes[0], &pipes[size], pipe2);

            if (pipe2.j2 < N && iter != &pipes[size] && !equal(*iter, pipe2)) {

            }

        }
        else if (pipe.j1 == pipe.j2) {

        }
        else {

        }
    }


    return 0;
}