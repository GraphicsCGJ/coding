#include <iostream>
#include <vector>

using namespace std;

void calc2 (int tmp, int tmp2, int& c) {
    while (true) {
        if (tmp % tmp2 == 0) {
            tmp = tmp / tmp2;
            c ++;
        }
        else
            break;
    }
}

int calc (vector<int>& vec) {
    int c2, c5, c10;
    c2 = c5 = c10 = 0;

    for (int& v : vec) {
        calc2(v, 2, c2);
        calc2(v, 5, c5);
    }

    return c10 + (c2 > c5 ? c5 : c2);
}

int main(void) {
    int n;
    cin >> n;
    int cnt = 0;
    vector<int> vec;

    for (int i = 1; i <= n; i++) {
        vec.push_back(i);
        if (i % 5 == 0) {
            cnt += calc(vec);
            vec.clear();
        }
    }

    cout << cnt << endl;

    return 0;
}