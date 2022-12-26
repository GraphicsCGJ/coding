#include<iostream>
#include<vector>

using namespace std;

int K, N;
long long maxVal;
int result = 0;

vector<int> values;

/*
Recursivly find the 'result'
Update L & R
*/
void bsearch(long long l, long long r) {
    while (l <= r) { // Escape Conditions
        long long m = ((l + r) / 2);
        int cnt = 0;

        for (int i = 0; i < K; i++) {
            cnt += (values[i] / m);
        }

        if (cnt >= N) {
            result = m;
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
}

int main(void) {
    maxVal = 0;
    cin >> K >> N;

    for (int i = 0; i < K; i++) {
        int tmp;
        cin >> tmp;
        values.push_back(tmp);
        maxVal += tmp;
    }

    maxVal /= N;
    bsearch(1, maxVal);
    cout << result << endl;

    return 0;
}