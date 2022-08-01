#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<int> vec;

int main(void) {
    N = 100;
    while (true) {
        cin >> N;
        if (N == 0) break;
        vec.clear();
        vec.reserve(N);

        int tmp;
        cin >> tmp;
        vec.push_back(tmp);

        sort(vec.begin(), vec.end());





    }

    return 0;
}