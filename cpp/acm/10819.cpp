
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc(vector<int>& v) {
    int sum = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        int tmp = v[i] - v[i+1];
        if (tmp < 0) tmp = -tmp;
        sum += tmp;
    }

    return sum;
}

bool cmp(int a, int b) {
    return a < b;
}

int main(void) {
    int n;
    cin >> n;
    vector<int> v(n, 0);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end(), cmp);
    int max = 0;
    do {
        int sum = calc(v);
        if (max < sum) max = sum;
        // cout << sum << endl;
    } while (next_permutation(v.begin(), v.end()));


    cout << max << endl;
    return 0;
}