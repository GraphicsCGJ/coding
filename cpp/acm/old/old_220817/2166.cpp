#include<iostream>

using namespace std;

typedef long long ll;

typedef struct {
    ll x;
    ll y;
} dot;

int N;
dot da[10001];


int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> da[i].x >> da[i].y;
    }

    ll sum = 0;
    for (int i = 0; i < N; i++) {
        int idx1 = i;
        int idx2 = (i + 1) % N;

        sum += (da[idx1].x * da[idx2].y - da[idx2].x * da[idx1].y);
    }

    if (sum < 0) sum = -sum;

    if (sum % 2 == 0)
        printf("%ld.0", sum / 2);
    else
        printf("%ld.5", sum / 2);

    return 0;
}