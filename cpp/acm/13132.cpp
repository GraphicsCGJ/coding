#include <iostream>
#include <vector>

using namespace std;

int N;
double M, B;
double possibility_win;
class ca {
public:
    int p;
    double rate;
};

vector<ca> vec;

void calc (int cdepth, int depth, double money, double possibility) {

    // cout << cdepth << " " << depth << " " << money << " " << possibility << endl;

    if (money <= B) {
        return;
    }
    else if (cdepth == depth) {
        if (money > 1.0)
            possibility_win += possibility;
        return;
    }
    else {
        /* win */
        calc (cdepth + 1, depth, money * (1 - M) +  money * (M) * vec[cdepth].rate, possibility * vec[cdepth].p / 100.0);

        /* lose */
        calc (cdepth + 1, depth, money * (1 - M), possibility * (1.0f - vec[cdepth].p / 100.0));
    }
}

int main(void) {
    cin >> N >> M >> B;

    M /= 100.0;
    B /= 100.0;

    possibility_win = 0.0;

    for (int i = 0; i < N; i++) {
        ca cai;
        cin >> cai.p >> cai.rate;
        vec.push_back(cai);

    }

    calc(0, N, 1.0, 1.0);

    printf("%.6lf\n", possibility_win * 100.0);

    return 0;
}