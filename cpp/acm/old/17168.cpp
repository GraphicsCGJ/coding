#include <iostream>
#include <vector>

using namespace std;

// #define comb_t char[6][6]
#define N 10

class comb_t {
    public:
        char comb[6][6];
        int total;

        comb_t() {
            for (int i = 0; i < 6; i++)
                for (int j = 0; j < 6; j++)
                    comb[i][j] = 0;

            total = 0;
        }
};

int map[11][11];
vector<comb_t> v;

void printmap() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", map[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");
}

int calc_1() {
    int res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1) res++;
        }
    }

    return res;
}

void input() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &map[i][j]);
}

void calc_comb(int n, int c, comb_t vi) {
    if (c == 0 && n == 0) {
        /* push back */
        v.push_back(vi);
        return;
    }
    else if (n < 0 || (n != 0 && c == 0)) {
        return;
    }

    for (int i = 0; i <= 5; i++) {

    }
}

int main(void) {
    int num_1 = 0;

    input();
    printmap();

    /* calc comb */
    num_1 = calc_1();
    comb_t tmp;
    calc_comb(num_1, 5, tmp);


    return 0;
}