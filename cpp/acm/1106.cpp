#include <iostream>

using namespace std;
int N, C;

typedef struct {
    int cost;
    int people;
} knap;

knap arr[20];

int main(void) {
    cin >> C >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].cost >> arr[i].people;
    }


    return 0;
}