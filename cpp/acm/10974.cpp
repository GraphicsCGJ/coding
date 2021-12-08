#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_VAL 8



int n;


int main(void) {
    vector <int> v;

    cin >> n;

    for (int i = 0; i < n; i++)
        v.push_back(i + 1);

    do {
        for (auto &i : v)
            printf("%d ", i);
        printf("\n");
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}