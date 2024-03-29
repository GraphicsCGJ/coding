#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

int N, K, D;
int cnt = 0;
int arr[101];

void factorization (int target, int val) {
    double sqrtNum = sqrt(target);
    int num = target;
    int k = 2;

    while (k <= sqrtNum && num != 1) {
        if (num % k == 0) {
            // cout << k << ' ';
            arr[k]+=val;
            num /= k;
        }
        else k++;
    }
    if (num > 1) {
        arr[num]+=val;
    }

    // for (int i = 0; i < 101; i++)
    //     cout << arr[i] << ' ';
    // cout << '\n';
}

void dfs(int remain, int val, vector<int>& v) {
    if (remain < 0) {
        return;
    }

    else if (remain == 0) {
        fill(arr, arr + 101, 0);
        int sumval = 0;
        bool flag = false;
        for (int i = 1; i < v.size(); i++)
            if (i >= D && v[i] > 0)
                flag = true;
        if (flag == false) return;

        for (int i = 1; i < v.size(); i++) {
            if (v[i] > 0) {
                sumval += v[i];

                for (int j = 2; j <= v[i]; j++) {
                    // cout << j << '\n';
                    factorization(j, -1);
                }
            }
        }
        for (int i = 2; i <= sumval; i++) {
            // cout << i << '\n';
            factorization(i, 1);
        }

        sumval = 1;
        for (int i = 1; i <= N; i++) {
            if (arr[i] == 0) continue;
            sumval *= (i * arr[i]);
        }

        cnt += sumval;
        // cout << "sumval: " << sumval << '\n';
        return;
    }
    else {
        while (remain - val >= 0) {
            v[val] ++;
            dfs(remain - val, val, v);
            v[val] --;

            val++;
            if (val > K) break;
        }
    }
}


int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K >> D;
    vector<int> v(N + 1, 0);
    dfs(N, 1, v);

    cout << cnt << '\n';
    return 0;
}

